//#include "lentille.h"
//#include "source.h"
#include "GravLens.h"
#include "bmp_io.hh"
#include<iostream>
#include<cmath>

using namespace std;

#define G  6.67e-11
#define c2 9e16


int main() {

  image image1;
  image1.creerimage(2e30, 1.2e20, -8e11, -8e11, 3e10, 3e10, 0, 3e11, 2.4e20, 80);
    // (Mlentille,Dlentille,Xlentille, Ylentille,Vxlentille,Vylentille,Vzlentille,Rsource,Dsource,Nbre_images)
    //Valeurs prof:  image1.creerimage(2e30, 1.2e20, 0, 1.8e11, 0, 6e10, 0, 3e11, 2.4e20, 20) lentille de 1 masse_solaire
    //lentille=quasar (2e35, 1e22, 0, 0, 0, 6e10, 0, 1e13, 1e23, 20) source: galaxie 
    //lentille=Terre source= Soleil Observateur=Mars
  // image1.creerimage(6e24, 5e10, 0,0,3e10,3e10,0,7e8,2e11,80);
    //convert images_0*.bmp GravLens.gif
  }

  


 
	    

























































































































