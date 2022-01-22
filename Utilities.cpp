//
// Created by migue on 21.01.2022.
//

#include <iostream>
#include <limits>
#include "Utilities.h"

using namespace std;

void Utilities::bufferClear() {
   cin.ignore(numeric_limits<streamsize>::max(),'\n'); // vide le buffer
}

bool HasCoordinate::operator() (const Point& p) const {
   return p.x == coordinate || p.y == coordinate;
}
