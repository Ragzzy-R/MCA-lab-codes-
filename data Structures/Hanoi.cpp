#include<iostream>
using namespace std;
int main()
{
	int x,n;
	long int total,begin,end;
	cout<<"\nEnter the number of disks";
	cin>>n;
	for(x=1;x<(1<<n);x++)
	{
		cout<<"\nMove from disk"<<(x&x-1)%3+1<<"to disk"<<((x|x-1)+1)%3+1;
	}
	return 0;
}
