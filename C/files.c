#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE	1
#define FALSE	0



void printHelp() {
		printf("\tWelcome to student Database\n");
		printf("\t\t-----------------\n");
		printf("\t\tEnter Your Choice\n");
		printf("\t\t-----------------\n");
		printf("\t\tS->Search from file\n");
		printf("\t\tW->Write into file\n");
		printf("\t\tH->help\n");
		printf("\t\tX->exit\n\n\n");
		printf("NOTE:THE COMMANDS ARE CASE-SENSITIVE\n");
}

int main() {
	FILE *fp;
	char name[20];
	char rollno[10],searchFor[10],temp[30];
	int m1,m2,m3,m4,m5,total;
	float avg;
	char ch;
	int isRollNoPresent=FALSE;
	char result;
		printHelp();
	while(1) {
		printf("\nstudentDB>");
		scanf(" %c",&ch);
		switch(ch) {
		case 'S':
			if((fp=fopen("student.txt","r"))==NULL) {
			perror("Fopen Failure:");
			}
			else { 
				printf("Enter The rollNo to search:");
				scanf("%s",searchFor);
				while(fgets(temp,sizeof(temp),fp)!=NULL) {
					if(strstr(temp,searchFor)!=NULL) {
						isRollNoPresent=TRUE;
						printf("\n\n");
						do {
							fgets(temp,sizeof(temp),fp);
							printf("%s",temp);
						}
						while(strncmp(temp,"<End of Record>",15)!=0);					
					}
					else if(feof(fp)) {
						printf("The RollNo does not exist");					
					}
					
				}
			}
			printf("\n\n");
			break;
		case 'W':
			if((fp=fopen("student.txt","a+"))==NULL) {
			perror("FOpen Failure:");
			}
			else {
				printf("Name:");
				scanf("%s",name);
				printf("RollNo:");
				scanf("%s",rollno);
				printf("Mark1:");		
				scanf("%d",&m1);
				printf("Mark2:");		
				scanf("%d",&m2);
				printf("Mark3:");		
				scanf("%d",&m3);
				printf("Mark4:");		
				scanf("%d",&m4);
				printf("Mark5:");		
				scanf("%d",&m5);
				total=m1+m2+m3+m4+m5;
				avg=total/5;
				fprintf(fp,"$>RollNo:%s\n    Name:%s\n    M1=%d\n    M2=%d\n    M3=%d\n    M4=%d\n    M5=%d\n    Total=%d\n    average=%.2f\n",rollno,name,m1,m2,m3,m4,m5,total,avg);
				fprintf(fp,"\n<End of Record>");
				fprintf(fp,"\n\n");
				fclose(fp);	
				printf("Record successfully written to the file\n");		
				break;
			}
		case 'H':
				printHelp();
				break;

		case 'X':
				printf("Exitting student DataBase\n");
				exit(0);
				break;	
		
		default:
				printf("Wrong Option press H for help\n");
				break;		
		}
	}
	return 0;
}  
	
