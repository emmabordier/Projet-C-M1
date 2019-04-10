#include "GravLens.h"
#include "bmp_io.hh"   //on rajoute classe bmp
#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<iomanip>
#define G  6.67e-11
#define c2 9e16

using namespace std;

void lentille::initialise( double masse, double distance, double abscisse, double ordonnee, double vitessex, double vitessey, double vitessez)
{
  Mlentille= masse ; Dlentille= distance;
  Xlentille= abscisse; Ylentille= ordonnee;
  vx= vitessex; vy=vitessey; vz=vitessez;
 
}

void lentille::affiche()
{
  cout << "masse_lentille" << Mlentille << endl;
  cout << "distance_obs_lentille"<< Dlentille<< endl;
  cout << "abscisse_lentille"<< Xlentille << endl;
  cout << "ordonnée_lentille"<< Ylentille << endl;
}

void source::initialise( double rayon, double distance1)
{
 Rsource=rayon ; Dsource=distance1;
}

void source::affiche() {
  cout << "Rayon_lentille="<< Rsource << endl;
}

void image::initialise(double M,double Dd, double Xm, double Ym,double Vx, double Vy, double Vz, double Rs, double Ds){
  lentille lens1;
  source source1;
  lens1.initialise(M,Dd,Xm,Ym,Vx,Vy,Vz);
  source1.initialise(Rs,Ds);
  }
  
void image::creerimage(double M,double Dd, double Xm, double Ym,double Vx, double Vy, double Vz, double Rs, double Ds,int Nbre_images)
{
  lentille lens1;
  source source1;
  lens1.initialise(M,Dd,Xm,Ym,Vx,Vy,Vz);
  source1.initialise(Rs,Ds);

  double startx=-1e12;    // pixels 
  double starty=-1e12;
  double endx=1e12;
  double endy=1e12;
  double pas = 2.5e10;//2.5e10;
  double Xs,Ys,Xa,Ya,Yi,Xi;
  int pixel=0;
  int i;

  N=Nbre_images;
  
  double width= (endx-startx)/pas;     // On définit les largeur et hauteur de l'image 
  double height= (endy-starty)/pas;
  

  ostringstream y;         // pour pouvoir créer plusieurs images dont le nom "y" changera à chaque tour de boucle
  fstream fich;

  for (i=0; i<N; i++){
 
  
  Bmp24 bmp_image(width,height);                                      // Création de l'objet image bmp
  unsigned char* const bmp_image_data=bmp_image.pixel_data();
  
  double ycur = endy;
  size_t pixel_index=0;
  while(ycur > starty)
    {
      double xcur = startx;
      while (xcur < endx)
	{
	  Xa=xcur;
	  Ya=ycur;
	  //cout << Xa << "/" << Ya << " " << endl;
	  Xi=Xa*Ds/(Dd+i*Vz);
	  Yi=Ya*Ds/(Dd+i*Vz);
	  double R=sqrt( (Xa-(Xm+i*Vx))*(Xa-(Xm+i*Vx)) + (Ya-(Ym+i*Vy))*(Ya-(Ym+i*Vy)) );
	  double alpha = (4*G*M)/(R*c2);
	  double alphax = alpha*(Xa-(Xm+i*Vx))/R;
	  double alphay = alpha*(Ya-(Ym+i*Vy))/R;
	  Xs=Xi-alphax*(Ds-(Dd+i*Vz));
	  Ys=Yi-alphay*(Ds-(Dd+i*Vz));

	  if(sqrt(Xs*Xs+Ys*Ys) < Rs){                           // for(size_t pixel_index = 0 ; pixel_index < endx * endy ; ++pixel_index) {
	   
	    bmp_image_data[3 * pixel_index] = 255;                      // 255:blanc
	    bmp_image_data[3 * pixel_index + 1] = 255;
	    bmp_image_data[3 * pixel_index + 2] = 255 ;
  }

	  
	  
	  else {                                                     //0:noir
	    bmp_image_data[3 * pixel_index] = 0;
	    bmp_image_data[3 * pixel_index + 1] = 0;
	    bmp_image_data[3 * pixel_index + 2] = 0 ;
	  }
	  
	  xcur += pas;
	  pixel_index += 1;
	}
      ycur -= pas;
    }

  y << "image_"<<setfill('0')<<setw(3)<<i<<".bmp";      //on donne un nom à la variable de nom y 
  
  bool ok = bmp_image.write_file((y.str()).c_str());   // On crée une image avec le nom y
  y.str("");                                           // On nettoie l'ostringstream 
  }
}

