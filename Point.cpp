/*---------------------------------------------------------------------------------
Nom du fichier : Point.cpp
Nom du labo    : Test
Auteur(s)      : Miguel Jalube
Date           : 21.01.2022
But            :

Remarque(s)    : à compléter

Compilateur    : Mingw-w64 g++ 8.1.0
---------------------------------------------------------------------------------*/

#include <iostream>
#include "Point.h"

using namespace std;

//***************************************************************
// 					            Variables de classe
//***************************************************************

unsigned Point::number = 0;
unsigned Point::next = 1;

//***************************************************************
// 					            Constructeurs
//***************************************************************

// Avec paramètres
Point::Point               (const Point& c) : ID(next++){
   x = c.x;
   y = c.y;
   ++number;
   cout << "Contructeur avec plusieurs paramètre" << endl;
}

//***************************************************************
// 					            Operateurs membres
//***************************************************************

Point    Point::operator+  (double z) const {
   Point res = *this;
   res += z;
   return res;
}

Point&   Point::operator+= (double z){
   x += z;
   y += z;
   return *this;
}

Point&   Point::operator-= (double z){
   *this += -z;
   return *this;
}

Point    Point::operator-  (double z) const {
   Point res = *this;
   res -= z;
   return res;
}

Point    Point::operator+  (const Point& p) const {
   Point res = *this;
   res += p;
   return res;
}

Point    Point::operator-  (const Point& p) const {
   Point res = *this;
   res -= p;
   return res;
}

Point&   Point::operator+=  (const Point& p){
   x += p.x;
   y += p.y;
   return *this;
}

Point&   Point::operator-=  (const Point& p){
   x -= p.x;
   y -= p.y;
   return *this;
}

Point&   Point::operator=  (const Point& p){
   x = p.x;
   y = p.y;
   cout << "Operateur d'affectation" << endl;
   return *this;
}

bool     Point::operator==  (const Point& p) const{
   return x == p.x && y == p.y;
}

bool     Point::operator!=  (const Point& p) const{
   return !(*(this) == p);
}

bool     Point::operator<   (const Point& p) const{
   bool isSmaller = x-p.x + y-p.y < p.x - x + p.y - y;
   return isSmaller;
}

bool     Point::operator>    (const Point& p) const{
   return  p < *this;
}

bool     Point::operator>=   (const Point& p) const{
   return !(*(this) < p);
}

bool     Point::operator<=   (const Point& p) const{
   return !(*(this) > p);
}

// ++Point
Point&   Point::operator++  (){
   *this += 1;
   return *this;
}

// Point++
Point   Point::operator++  (int){
   Point temp = *this;
   ++(*this);
   return temp;
}

// --Point
Point&   Point::operator--  (){
   *this -= 1;
   return *this;
}

// Point--
Point   Point::operator--  (int){
   Point temp = *this;
   --(*this);
   return temp;
}

//***************************************************************
// 					            Operateurs non-membres
//***************************************************************

ostream& operator<<  (ostream &os,  const Point& c){
   os << "[" << c.x << ", " << c.y << "]";
   return os;
}

istream& operator>>  (istream &is,  Point& c){
   bool inputOk;
   Point temp;

   inputOk = !(is >> temp.x).fail() && !((is >> temp.y).fail());

   if(inputOk){
      c = temp;
   }else{
      is.clear(is.rdstate() | ios::failbit);
   }

   return is;
}

Point    operator+   (double z,     const Point& p){
   return p + z;
}

//***************************************************************
// 					            Methodes
//***************************************************************

bool Point::isOrigin() const {
   return x == 0 && y == 0;
}

unsigned Point::getID() const {
   return ID;
}

unsigned Point::getNumber(){
   return number;
}