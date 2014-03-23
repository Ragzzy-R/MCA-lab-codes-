using namespace std;
#include<iostream>

template <class Number>
class Arithmetic {
public: 
		Number a;
		Number b;
	Arithmetic() {
		a = Number();
		b = Number();
	}
	
	Number add(Number a , Number b) {
		return a+b;
		
	}
	
	Number subtract(Number a,Number b) {
		return a-b;
		
	}
	
	Number multiply(Number a,Number b) {
		return a*b;
		
	}
	
	Number divide(Number a,Number b) {
		if(b==0) {
			return -1;
		}
		return a/b;
		
	}
};

int main() {

	Arithmetic<int> a;
	Arithmetic<float> b;
	cout<<a.add(10,20)<<endl;
	cout<<a.subtract(20,10)<<endl;
	cout<<a.multiply(20,10)<<endl;
	cout<<a.divide(20,10)<<endl;

	cout<<b.add(10.5,20.5)<<endl;
	cout<<b.subtract(20.33,10.323)<<endl;
	cout<<b.multiply(20.24,10.22)<<endl;
	cout<<b.divide(20.2,10.1)<<endl;
	return 0;
}

