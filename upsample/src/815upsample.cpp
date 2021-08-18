#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
using namespace std;


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int upsample(double dx,int flag, double pu, double pv,double mr,int u,int v) {
            int Dx[25];
            double Wp, Gr, Gs, S=0,Y=0;
            double mr=0;
            Gr = dx/mr;
            Gs =  ( (u - pu)*(u - pu) + (v-pv)*(v-pv) );//ij=uv
            Wp = 1/sqrt(Gs*Gr);
            S = S + Wp;
            Y = Y + Wp*(dx);
            Dx[flag] = Y/S;
  return Dx[flag];
}
