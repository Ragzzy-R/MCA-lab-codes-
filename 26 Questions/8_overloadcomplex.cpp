/**
*8. Write a c++ program to
*illustrate the concept of operator overloading method(using the concept of complex nos)
*/

using namespace std;
#include<iostream>
class Complex {
    public:
            int r,i;
            Complex operator+(Complex b) {
                Complex c;
                c.r=r+b.r;
                c.i=i+b.i;
                return c;
            }
};

int main() {
    Complex a,b,c;
    cout<<"Enter the real and imaginary part of a";
    cin>>a.r>>a.i;
    cout<<"Enter the real and imaginary part of a";
    cin>>b.r>>b.i;
    c=a+b;
    cout<<"The addition of two complex numbers is ";
    cout<<c.r<<"+"<<c.i<<"i"<<endl;
    return 0;
}




