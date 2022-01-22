/*
-----------------------------------------------------------------------------------
Nom du fichier : Utilities.h
Nom du labo    : Test
Auteur(s)      : Miguel Jalube
Date           : 21.01.2022
But            :

Remarque(s)    : à compléter

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef POINT_UTILITIES_H
#define POINT_UTILITIES_H

#include "Point.h"

class Point;

class Utilities {
public:
   static void bufferClear();

private:

};

class HasCoordinate{
public:
   HasCoordinate(double x) : coordinate(x) {};
   bool operator() (const Point& p) const;
private:
   const double coordinate;
};

#endif //POINT_UTILITIES_H
