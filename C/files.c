/*
  @author:Raghuram Iyer "Ragzzy-R"
  The Program is a small application which maintains a student database.
  The program can Search the database file using rollno.write new records
  to it(appends).It comes with a easy to use user-friendly interface just
  like a command-prompt SQL.I tried testing all possiblilities but the code
  is prone to errors.so please let me know if any.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>



/*
  this prints the help.Press H for help
*/
void printHelp() {
		printf("\t\tWelcome to student Database\n");
		printf("\t\t-----------------\n");
		printf("\t\t  Command List\n");
		printf("\t\t-----------------\n");
		printf("\t\tS->Search from file\n");
		printf("\t\tW->Write into file\n");
		printf("\t\tH->help\n");
		printf("\t\tX->exit\n\n\n");
		printf("NOTE:THE COMMANDS ARE CASE-SENSITIVE\n");
		printf("CAUTION:NEVER EDIT student.txt MANUALLY.IT WILL CAUSE DAMAGE\n");
		printf("TO THE SEARCHING ALGORITHM.YOU MAY GET UNEXPECTED RESULT.\n");
		printf("IF YOU HAVE ANY PROBLEM WITH SEARCHING TRY DELETING THE FILE\n");
	        printf("AND RUNNING THE PROGRAM AGAIN\n");
}

int main() {
	//declare all necessary variables
	FILE *fp;
	char name[20];
	char rollno[10],searchFor[10],temp[30];
	int m1,m2,m3,m4,m5,total;
	float avg;
	char ch;
	char result;
	printHelp(); //prints the help at the startup.
	/*this loops runs forever until X is pressed*/	
	while(1) {
		printf("\nstudentDB>"); //this prints the command prompt like SQL>
		scanf(" %c",&ch);
		switch(ch) {
		case 'S':
			if((fp=fopen("student.txt","r"))==NULL) {
			perror("Fopen Failure");
			printf("\nProbably You are trying to read from a file that does not exist\n");
			printf("Try writing something first.Then read");
			}
			else { 
				printf("Enter The rollNo to search:");
				scanf("%s",searchFor);
				
				/*This piece of code searches the string for us.first
				  the file is read line by line using fgets.It is read
				  until we reach EOF.thus the while loop executes till
				  the file is fully read.				
				*/
				while(fgets(temp,sizeof(temp),fp)!=NULL) {
					/*the strstr()function searches for the substring "searchFor" from 
					  "temp".					
					*/
					if(strstr(temp,searchFor)!=NULL) {
						/*condition is true if we get the substring (i.e) in this case
						  the roll no is present.						
						*/
						printf("\n\n");
						/* now we have got the rollno.we have to print the details
						   of the student.so we read line by line.from the point where
						   our strstr() found the rollno.*/
						do {
							fgets(temp,sizeof(temp),fp);
							printf("%s",temp);
						}
						/*The while loop is repeated (i.e) the data is printed line by
						  line until we find "<End of Record>".Once this is found The 
						  we no longer print and return to studentDB> prompt*/
						while(strncmp(temp,"<End of Record>",15)!=0);					
					}	
					
				}
			}
			fclose(fp);
			printf("\n\n");
			break;
		case 'W':
			if((fp=fopen("student.txt","a+"))==NULL) {
			perror("FOpen Failure:");
			}
			else {
				/*
				 The data is read from user using normal printf and scanf
				*/
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
				/*The data is written into the file.I have maintained a structure so that
				  it will be easy for us to read and search.To see how the structure looks 
				  like see the student.txt file.
				  CAUTION:NEVER EDIT THE FILE MANUALLY.IT WILL
				  CAUSE DAMAGE TO THE SEARCHING ALGORITHM.YOU MAY GET UNEXPECTED RESULT */
				fprintf(fp,"$>RollNo:%s\n    Name:%s\n    M1=%d\n    M2=%d\n    M3=%d\n    M4=%d\n    M5=%d\n    Total=%d\n    average=%.2f\n",rollno,name,m1,m2,m3,m4,m5,total,avg);
				/*we append each record with <End of Record> so that it will be easy 
				  for searching*/
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
	
