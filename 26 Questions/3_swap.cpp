/*
 *
 * 3. Write a c++ program using function template to swap two integers,float numbers and characters.
 *
 *
 * */
#include<iostream>
using namespace std;
template <class Data>
void swap(Data* a, Data* b) {

	Data temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


int main() {
     int a,b;
     float fa,fb;
     char ca,cb;
     cout<<"Enter the integers";
     cin>>a>>b;
     swap(a,b);
     cout<<a<<"   "<<b<<endl;
     cout<<"Enter the floats";
     cin>>fa>>fb;
     swap(fa,fb);
     cout<<fa<<"   "<<fb<<endl;

     cout<<"Enter the chars";
     cin>>ca>>cb;
     swap(ca,cb);
     cout<<ca<<"   "<<cb<<endl;
     return 0;

}
