#ifndef GRAVLENS_H
#define GRAVLENS_H


class lentille {
 public:
  
  double Xlentille ;
  double Ylentille;                  //Repérage lentille(pointM)  par ses coordonnées
  double Dlentille;                    //distance lentille-observateur;
  double Mlentille;                    //Masse lentille

  double vx;                      //On donne une vitesse de déplacement à la lentille
  double vy;
  double vz;

  
  void initialise (double masse,double distance, double abscisse, double ordonnee, double vitessex, double vitessey, double vitessez);//vecteur3D vitesse
  void affiche();
};

class source {
 public: 
  double Dsource;                    //distance source-observateur;
  double Rsource;


  void initialise (double rayon, double distance);
  void affiche ();
};

class image{
 public:
  int N;
  lentille lens1;
  source source1;

  void initialise(double M,double Dd, double Xm, double Ym,double Vx, double Vy, double Vz, double Rs, double Ds);
  void creerimage(double M,double Dd, double Xm, double Ym,double Vx, double Vy, double Vz, double Rs, double Ds,int Nbre_images);
};
  
#endif  
