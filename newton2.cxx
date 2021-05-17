// Newton fractal
// GL, 5.5.14

#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

int main()
{
 const double max = 2;
 const double min = -2;
 const int N = 500;       // Number of points along axis
 const double h = (max-min)/(N-1);
 const int iterMax = 100; // Maximum number of iterations

 ofstream out("out");

 complex<double> z0,zOld,z;

 for(double re = min; re <= max; re += h)
   for(double im = min; im <= max; im += h)
   {
    z0 =  complex<double>(re,im);
    zOld = z0;
    int i;
    for(i = 0; i<iterMax; i++)
    {
      z = zOld - (zOld*zOld*zOld - 1.0)/(3.0*zOld*zOld);
      //z = zOld - ( pow(zOld,7) - 5.0*pow(zOld,3) - 1.0 ) / ( 7.0*pow(zOld,6) - 15.0*pow(zOld,2));
      if (abs(z-zOld) < 1e-6) break;
      zOld = z;
    }
    out << real(z0) << "\t" << imag(z0) << "\t" << i << endl;

   }

   out.close();

   return 0;
}
