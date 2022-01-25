/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Nom du labo    : Test
Auteur(s)      : Miguel Jalube
Date           : 21.01.2022
But            :

Remarque(s)    : à compléter

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Point.h"
#include "Utilities.h"

//***************************************************************
// 					  Définition des using
//***************************************************************

using namespace std;
using vPoint =  vector<Point>;

//***************************************************************
// 					  Définition des prototypes
//***************************************************************

void test(Point& p);

//***************************************************************
// 					            main
//***************************************************************

int main() {
   vPoint vp;
   int n = 1;
   //{Point p = n;}
   vp.resize(10);

   cout << "******************************************************" << endl;
   cout << "*     Test des constructeurs" << endl;
   cout << "******************************************************" << endl;
   cout << endl;

   vp[0] = {1, 2};
   vp[1] = {5, 4};
   vp[2] = vp[1] + 2;
   vp[3] = n + vp[2];
   vp[4] = vp[3] + vp[4];
   vp[5] = 0;
   vp[6] -= vp[5] += vp[0] - 3;
   cout << "Saisir un point [x y] : ";
   if(!(cin >> vp[7])){
      cin.clear();
   }
   Utilities::bufferClear();
   double coord;
   cout << "Saisir une coordonnee : ";
   cin >> coord;
   Utilities::bufferClear();

   cout << endl;
   ++vp[7];
   for(Point& p : vp){
      test(p);
   }


   cout << endl;
   cout << "******************************************************" << endl;
   cout << "*     Test des operateurs de comparaison" << endl;
   cout << "******************************************************" << endl;
   cout << endl;
   cout << boolalpha;
   cout << "vp[5] <  vp[7]  => "  << (vp[5] < vp[7])    << endl;
   cout << "vp[5] >  vp[7]  => "  << (vp[5] > vp[7])    << endl;
   cout << "vp[5] <= vp[7]  => "  << (vp[5] <= vp[7])   << endl;
   cout << "vp[5] >= vp[7]  => "  << (vp[5] >= vp[7])   << endl;
   cout << "vp[5] == vp[7]  => "  << (vp[5] == vp[7])   << endl;
   cout << "vp[5] != vp[7]  => "  << (vp[5] != vp[7])   << endl;


   cout << endl;
   cout << "******************************************************" << endl;
   cout << "*     Test d'un foncteur" << endl;
   cout << "******************************************************" << endl;
   cout << endl;
   cout << setprecision(2);
   cout << "Quel point contient une coordonnee de "<< coord <<"?" << endl;
   cout << "vp[" << ( *( find_if( vp.begin(), vp.end(), HasCoordinate(coord) ) ) )
   .getID()-1
   << "]" << endl;

	cout << "Pressez Enter pour quitter";
   Utilities::bufferClear();



	return EXIT_SUCCESS;
}


//***************************************************************
// 					  Définition des fonctions
//***************************************************************

void test(Point& p){

   if(!p.isOrigin()) {

   }
   cout << "vp[" << p.getID()-1 << "] : " << p << endl;
}
