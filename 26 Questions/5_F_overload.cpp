/**
 *5. Write a c++ program to illustrate the concept of function overloading.s
 */
using namespace std;
#include<iostream>
#define PI 3.14
class Polygon {
public:
    double area;
double Area(double radius);
double Area(float side);
double Area(float length,float breadth);
double Area(double base,double height);
};

double Polygon::Area(float side) {
    return double(side*side);
}

double Polygon::Area(float length,float breadth) {
    return double(length*breadth);
}

double Polygon::Area(double base,double height) {
    return double(.5*base*height);
}
double Polygon::Area(double radius) {
    return double(PI*radius*radius);
}
int main() {
    Polygon p;
    double radius;
    float side;
    float l,b;
    double bs,h;
    cout<<"Enter radius ";
    cin>>radius;
    cout<<"Circle "<<p.Area(radius)<<endl;
    cout<<"Enter side ";
    cin>>side;
    cout<<"Square "<<p.Area(side);
    cout<<"Enter length and breadth "<<endl;
    cin>>l>>b;
    cout<<"rectangle "<<p.Area(l,b);
    cout<<"Enter base and height "<<endl;
    cin>>bs>>h;
    cout<<"Triangle "<<p.Area(bs,h)<<endl;
    return 0;

}
