#include<iostream>
using namespace std;
template <class Data>
int find(Data a[],Data searchfor,int size)  {
    int i;
    for(i=0;i<size;i++) {
        if(searchfor==a[i])
            break;
        else
            continue;
    }
    return i;

}

int main() {
    int i;
    int s;
    int res,n;
    cout<<"Enter the size of arrays"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements for integer array"<<endl;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }

    cout<<"what u want to search the array for?"<<endl;
    cin>>s;

    res=find(a,s,n);
    if(res!=n) {
        cout<<"integer found at index "<<res<<endl;
    }
    else
        cout<<"Integer not found";
    return 0;
}

