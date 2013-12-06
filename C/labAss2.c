#include<stdio.h>
#include<math.h>
int sum(int n) {
	int even,odd,ans;
	even=0;
	odd=1;
		
	ans=sum(n-1);
	pow(even,odd);
	return ans;
}

int main() {
	int i,j,n;
	printf("Enter the number\n");
	scanf("%d",&n);
	sum(n);
	return 0;
}
