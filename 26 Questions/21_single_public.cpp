
#include<iostream>
using namespace std;

class Vehicle {
    public:
    string name;
    string engine;
    int wheelCount;

};
class Car:public Vehicle {
    public:
    Car(string name,string engine) {
    Vehicle::name=name;
    Vehicle::engine=engine;
    }

    void display() {
    cout<<name<<endl;
    cout<<engine<<endl;

    }
};
int main() {
    string c;
    string d;
    cout<<"Enter a car name its engine types";
    cin>>c>>d;
    Car c2(c,d);
    c2.display();

}
