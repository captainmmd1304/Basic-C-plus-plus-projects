#include <iostream>
#include <cmath>

int main () {
   double a;
   double b;
   double z;
   double c;
   double d;
   double m;

   std:: cout << "Enter the value of side a in cm: ";
   std:: cin >> a;
   std:: cout << "Enter the value of side b in cm: ";
   std:: cin >> b;

   c = pow (a, 2);
   d = pow (b, 2);

   z = c + d ;

   m = sqrt (z);

   std:: cout <<"The value of hypotenuse is " << m << " cm.";

   return 0;
   
   }