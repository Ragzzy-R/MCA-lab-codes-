/**
*6. Write a c++ program to overload the function add( ) with same no of arguments but with different datatypes.
*/
using namespace std;
#include<iostream>

int add(int a,int b) {
    return a+b;
}



float add(float a,float b) {
    return a+b;
}


double add(double a,double b) {
    return a+b;
}


int main() {
    int a,b;
    float af,bf;
    double ad,bd;
    cout<<"Enter Integers";
    cin>>a>>b;
    cout<<"Enter Floats";
    cin>>af>>bf;
    cout<<"Enter Doubles";
    cin>>ad>>bd;
    cout<<"integers : "<<add(a,b)<<endl;
    cout<<"Floats   : "<<add(af,bf)<<endl;
    cout<<"Doubles  : "<<add(ad,bd)<<endl;
    return 0;

}
