#include<stdio.h>
int main() {
	char c;
	printf("Please enter a single character\n");
	scanf("%c",&c);
	if((c>=48) && (c<=57)) 
		printf("You have entered a numerical value\n");
	else if((c>=65)&&(c<=90))
		printf("You have entered a capital letter\n");	
	else if((c>=97)&&(c<=122))
		printf("You have entered a small letter\n");	
	else
		printf("U have entered a special\n");
	
	return 0;
}
