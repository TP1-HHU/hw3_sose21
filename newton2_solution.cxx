// Newton fractal
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

 int* F = new int[N*N];

 ofstream out("out");

 complex<double> z0,zOld,z;

 for(int i=0; i <N ; i++)
   for(int j=0; j < N; j++)
   {
    z0 =  complex<double>(min + j*h, min + i*h);
    zOld = z0;
    int c;
    for(c = 0; c<iterMax; c++)
    {
      z = zOld - (zOld*zOld*zOld - 1.0)/(3.0*zOld*zOld);
      if (abs(z-zOld) < 1e-6) break;
      zOld = z;
    }
    F[i * N + j] = c;
  }

  for(int i=0; i <N ; i++){
    double im = min + i*h;
    for(int j=0; j < N; j++) {
        double re = min + j*h;
        out << re << "\t" << im << "\t" << F[i * N + j] << endl;
    }
  }

   out.close();
   delete[] F;

   return 0;
}
