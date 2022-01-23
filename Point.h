/*
-----------------------------------------------------------------------------------
Nom du fichier : Point.cpp
Nom du labo    : Test
Auteur(s)      : Miguel Jalube
Date           : 21.01.2022
But            :

Remarque(s)    : à compléter

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef POINT_POINT_H
#define POINT_POINT_H

#include <iostream>
#include "Utilities.h"

class Point {
   friend std::ostream& operator<<  (std::ostream& os, const Point& c);
   friend std::istream& operator>>  (std::istream& os, Point& c);
   friend Point         operator+   (double z, const Point& c);
   friend class HasCoordinate;
public:
   //***************************************************************
   // 					            Constructeurs / destructeur
   //***************************************************************

   // Contructeur sans paramètres
   Point    () :  x(0), y(0), ID(next++){
      ++number;
   };

   // Destructeur
   ~Point   (){
      --number;
   };

   // Contructeur avec paramètres
   Point    (double x, double y) : x(x), y(y), ID(next++){
      ++number;
   };

   // Contructeur avec 1 paramètre
   Point    (double x) : x(x), y(x), ID(next++){
      ++number;
   };

   // Contructeur de copie
   Point    (const Point& c);

   //***************************************************************
   // 					            Operateurs
   //***************************************************************

   // Operations avec les scalaires
   Point&   operator+=  (double z);
   Point&   operator-=  (double z);
   Point    operator+   (double z) const;
   Point    operator-   (double z) const;

   // Operations avec les points
   // Operateur d'affectation obligatoire car utilisation de propriétés statics
   Point&   operator=   (const Point& p);
   Point&   operator+=  (const Point& p);
   Point&   operator-=  (const Point& p);
   Point&   operator++  ();
   // Marche pas avec un autre type que int
   Point    operator++  (int);
   Point&   operator--  ();
   // Marche pas avec un autre type que int
   Point    operator--  (int);
   Point    operator+   (const Point& p) const;
   Point    operator-   (const Point& p) const;
   bool     operator==  (const Point& p) const;
   bool     operator!=  (const Point& p) const;
   bool     operator<   (const Point& p) const;
   bool     operator>   (const Point& p) const;
   bool     operator<=  (const Point& p) const;
   bool     operator>=  (const Point& p) const;

   //***************************************************************
   // 					            Methodes
   //***************************************************************

   bool isOrigin() const;
   unsigned getID() const;
   // Fonction static ne peut pas etre const
   static unsigned getNumber();
private:

   //***************************************************************
   // 					            Propriétés
   //***************************************************************

   double x, y;
   const unsigned ID;
   static unsigned number;
   static unsigned next;
};


#endif //POINT_POINT_H
