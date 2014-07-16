#include<stdio.h>

int main() {
	int p[10];
	int n;
	int waiting=0;
	int i;
	int sum;
	float avg;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		printf("Enter the CPU burst time for Process %d",i+1);
		scanf("%d",&p[i]);
	}
	printf("---------\t------------\t--------------\n");
	printf(" Process \t Burst time \t waiting time \n");
	printf("---------\t------------\t--------------\n");
	printf("P1       \t%d          \t%d        \n",p[0],waiting);
	waiting+=p[0];

	for(i=1;i<n;i++) {
	sum+=waiting;
	printf("P%d      \t%d          \t%d	   \n",i+1,p[i],waiting);
	waiting+=p[i];
	}
	waiting	-=  p[i];
	avg	 =  sum/n;
	printf("Average Waiting time : %f ",avg);
	return 0;
}
