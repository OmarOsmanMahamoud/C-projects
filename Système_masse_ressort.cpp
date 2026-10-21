#include <iostream>
#include <cmath>
#include <fstream>

void euler(float x[], float vx[], float dt, int n, float ω){
    for(int i=0; i<n; i++){
        x[i+1]+=x[i]+vx[i]*dt;
        vx[i+1]+=vx[i]-(ω*x[i])*dt;
    }
}

void csv(int n, float x[], float vx[]){
    std::ofstream myfile;
    myfile.open("masse_ressort");
    myfile<<"x,vx\n";
    for(int i=0; i<n; i++){
        myfile<<x[i]<<','<<vx[i]<<'\n';
    }
    myfile.close();
}

int main(){
    float m=0.5; //kg
    float k=100; // N.m^-1
    float ω=k/m;
    float ti=0; // 0s
    float tf=5; // 5s
    float dt=0.0001; //0.01s
    float x0 =0.3; //m
    int n=500; //nbre de pas
    float *x = new float[n];
    float *vx = new float[n];
    x[0]=x0;
    vx[0]=0;

    euler(x,vx,dt,n,ω);
    csv(n,x,vx);

    delete[] x;
    delete[] vx;

    return 0;
}