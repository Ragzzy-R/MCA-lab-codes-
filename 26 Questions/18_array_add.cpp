#include<iostream>
using namespace std;
template <class type1,class type2>
class ArrayAdd {
    public:
        void add(type1* a,type2* b,int size) {

            for(int i=0;i<size;i++) {
                b[i]+=a[i];
            }
        }
};

int main() {

        ArrayAdd<int,float> ad;
        int n;
        int i;
        cout<<"Enter the size of arrays"<<endl;
        cin>>n;
        int a[n];
        float b[n];
        cout<<"Enter the elements for integer array"<<endl;
        for(i=0;i<n;i++) {
            cin>>a[i];
        }
        cout<<"Enter the elements for float array"<<endl;
        for(i=0;i<n;i++) {
            cin>>b[i];
        }

        ad.add(a,b,n);

        for(i=0;i<n;i++) {
            cout<<b[i]<<endl;
        }
}
