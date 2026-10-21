#include <iostream>
#include <cmath> 
#include <fstream>

int main(){

    // Pamètres
    float g=9.81; // m.s^-2
    float ti=0;
    float tf=5;
    float v0=30; // m.s^-1
    float θ=0.78; // θ°

    // arrays
    float x[50]= {};
    float y[50]= {};
    float vx[50]= {};
    float vy[50]= {};
    float dt = (tf-ti)/(sizeof(x)/float(sizeof(float))); // s
    int n = ((tf-ti)/dt);

    vx[0]=v0*cos(θ);
    vy[0]=v0*sin(θ);

    for(int i=0; i<n; i++){
        x[i+1]+=x[i]+vx[i]*dt;
        y[i+1]+=y[i]+vy[i]*dt;
        vy[i+1]+=vy[i]-g*dt;
        vx[i+1]+=vx[i];
    }

    std::ofstream myfile;
    myfile.open("mvt_plan_trajectories_cpp");
    myfile << "x,y,vx,vy\n";
    for(int i = 0; i < n; i++)
        myfile << x[i] << ',' << y[i] << ',' << vx[i] << ',' << vy[i] << '\n';
    myfile.close();

    return 0;
}
