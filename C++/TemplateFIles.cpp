using namespace std;
#include<iostream>
#include<fstream>
#include<string>
template <class Data>
class FileData {
    public:
    Data data;
    FileData() {
        data = Data();
    }
    void setData(fstream* f,Data data) {
    *f<<data;
    }
};

int main() {
    FileData<char> cd;
    FileData<string> strd;
    FileData<int> id;
    fstream f;
    char c;
    string str;
    int n;
    cout<<"Enter a character, a string, a number in that order\n";
    cin>>c>>str>>n;
    f.open("sample.txt",fstream::in|fstream::out);
    cd.setData(&f,c);
    cd.setData(&f,'\n');

    strd.setData(&f,str);
    cd.setData(&f,'\n');

    id.setData(&f,n);
    cd.setData(&f,'\n');

    cout<<"retriving data from the file:\n";
    f>>c;
    cout<<c<<endl;

    f>>str;
    cout<<str<<endl;

    f>>n;
    cout<<n<<endl;
    return 0;

}
