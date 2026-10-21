#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

void euler(float Θ[500], float dΘ[500], float ddΘ, float dt, float n){
    for(int i=0; i<n; i++){
        Θ[i+1]+=Θ[i]+dΘ[i]*dt;
        dΘ[i+1]+=dΘ[i]-(ddΘ*Θ[i])*dt;
    }
}

void csv(float Θ[50],float dΘ[500], float n){
    std::ofstream myfile;
    myfile.open("Pendulum_csv");
    myfile<<"Θ,dΘ\n";
    for(int i=0; i<n; i++){
        myfile << Θ[i] << ',' << dΘ[i] << '\n';
    }
}



int main(){
    float ti=0;
    float tf=5;
    float l=5;
    float g=9.81;
    float ω=sqrt((g/l));
    float θ0= 0.78;
    float Θ[500]={};
    Θ[0]=θ0; 
    float dΘ[500]={};
    dΘ[0]=0;
    float ddΘ= pow(ω,2);
    float n=sizeof(Θ)/float(sizeof(float));
    float dt=(tf-ti)/n;

    euler(Θ, dΘ, ddΘ, dt, n);
    csv(Θ, dΘ, n);
    // cout<<dΘ[0]<<'\n';
    
    return 0;
}

