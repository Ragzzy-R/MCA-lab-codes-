#include<iostream>
#include<string>
using namespace std;

char* operator+(char* s1,char* s2) {
char* c;
c=new(25);
strcpy(s1,s2);
return s1;
}
int main() {
    char* s1,s2;
    s1=new char(25);
    s2=new char(25);
    cout<<"Enter the two strings";
    cin>>s1>>s2;
    cout<<s1+s2;
    return 0;
}
