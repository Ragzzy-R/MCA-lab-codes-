/*Program for Matrix Manipulation.Note that this program
  can handle only manipulation upto the order of 5x5.this is 
  because we are using static arrays.If you want  to manipulate
  nxn matrix then use dynamic memory Allocation
*/

/*defining header files stdio.h for Input Ouput functions like printf and scanf
  stdlib is used because exit(0) is used.
Also we are defining two macros TRUE AND FALSE and assigning values 1 and 0 respectively.
Macros are codes where the Macro will be replaced by the actual values before complilation (i.e)
the program will be replaced with 1 and 0 wherever TRUE and FALSE are present throughout the code.This is used of readablity*/
#include<stdio.h>
#include<stdlib.h>
#define TRUE 	1
#define FALSE	0


/*This is a user defined Function.It checks whether Addtion or subtraction is possible
 for the two matrices.It takes four parameters
 row= a  pass by reference of row of first Matrix
 col= a  pass by reference of col of first Matrix
 row1= a  pass by reference of row of second Matrix
 col1= a  pass by reference of col of second Matrix
*/
int isAddOrSubPossible(int* row,int* col,int* row1,int* col1) {
	printf("Enter the number of rows and column of first matrix : \n");
	/*note here we have not used & before row or col.This is perfectly legal!because row and col are not actual
	  row and column they are just passed by reference meaning that only their address are passed (i.e) 
	  they mean that row is actually &row so u are strictly not supposed to use &row then you will get unpredictable results
	*/ 		
	scanf("%d %d",row,col); 
	printf("Enter the number of rows and columns of second matrix : \n");	
	scanf("%d %d",row1,col1);
	

	/*We check whether the rows of both matrices are equal AND colums are equal
	  note we use *row meaning we are telling the compiler to look for the value in the address "row" 
	*/
    	if((*row==*row1)&&(*col==*col1))
        	return TRUE; //if yes return TRUE
    	else
     		return FALSE; //else return FALSE
}	

/*This function Checks if Multiplication is possible with the Given Matrices.The Parameters are same as 
isAddOrSubPossible*/
int isMulPossible(int* row,int* col,int* row1,int* col1) {
    	printf("Enter the number of rows and column of first matrix : \n");
   	scanf("%d %d",row,col);
    	printf("Enter the number of rows and columns of second matrix : \n");
    	scanf("%d %d",row1,col1);
    	if(*col==*row1)	//checking whether the column of first matrix is equal to the row of second matrix.
        	return TRUE;
   	else
        	return FALSE;
}

/*This  function populates the Matrix.(i.e) Get elements from the user and insert into the Matrix
Parameters:
	matrix[][5]  = this matrix is passed by reference.This is the matrix that will be populated.
			note : this is a two dimensional array of size [5][5].the declaration may seem
				wierd but this is a restriction in the Language definition.The easiest and efficent way to
				pass/return a multi dimensional array is to use structures but as it is not covered
				yet in the syllabus I'm using this type of passing
	row	     = the row count of the Matrix
	col	     = the col count of the Matrix
In other words,we can say that populate matrix fills up the "matrix[][]" with "row" rows and "col" columns
note: the row and col are passed by values here*/
void populateMatrix(int matrix[][5],int row,int col) {
	int i,j;
    	for(i=0;i<row;i++) {
        	for(j=0;j<col;j++) {
        		printf("Enter the Element (%d,%d)",i+1,j+1);
            		scanf("%d",&matrix[i][j]);
		}
    	}
    
}

/*This function is simple and straight forward.It takes the same parameters as populate Matrix 
  it do some formatting to print the Matrix just like the how we represent Matrix in real world*/
void displayMatrix(int matrix[][5],int row,int col) {
	int i,j;
	for(i=0;i<row;i++) {
	        printf("|\t");
		for(j=0;j<col;j++) {
			printf("%d \t",matrix[i][j]);
		}
	printf("|\n");
	}
}

/*this function add MatrixA and MatrixB and stores the Value in MatrixC 
all the three matrices will be of order "row"x"col"
*/
int addMatrix(int matrixA[][5],int matrixB[][5],
		int matrixC[][5],int row,int col) {
	int i,j;
	for(i=0;i<row;i++) {
                for(j=0;j<col;j++) {
                        matrixC[i][j]=matrixA[i][j]+matrixB[i][j];
                }
        }

}

/*this function multiply MatrixA[][5] with MatrixB[][5] and stores the result in MatrixC[][5]
  MatrixA will be of order "row"x"col" and MatrixB will be of order "row1"x"col1" 
after the mutiplication,MatrixC will be the product of MatrixA and MatrixB with order "row"x"col1"
*/
int multiplyMatrices(int matrixA[][5],int matrixB[][5],
		     int matrixC[][5],int row,int row1,int col) {
        int i,j,k;
        for(i=0;i<row;i++) {
		for(j=0;j<col;j++) {
			matrixC[i][j]=0;
			for(k=0;k<row1;k++) {
                        	matrixC[i][j]+=matrixA[i][k]*matrixB[k][j];
                	}
        	}

	}
}

/*same as addition*/
int subtractMatrix(int matrixA[][5],int matrixB[][5],
		int matrixC[][5],int row,int col) {
	int i,j;
        for(i=0;i<row;i++) {
                for(j=0;j<col;j++) {
                        matrixC[i][j]=matrixA[i][j]-matrixB[i][j];
                }
        }
}


/*here goes our main Function.It contains a simple interface for users to choose what matrix operation
they want to do and a switch case which switches to that operation depending on user input*/
int main() {

	int matrixA[5][5],matrixB[5][5],sumMatrix[5][5];
	int i,j,n;
	int row=0,col=0,row1=0,col1=0;
	printf("---------------------\n");
	printf("|Matrix Manipulation|\n");
	printf("---------------------\n");
	printf("----------------------------------\n");
	printf("|Welcome!please select an Option |\n");
	printf("|1.Matrix Addition		 |\n");
	printf("|2.Matrix Subtraction		 |\n");
	printf("|3.Matrix Multiplication	 |\n");
	printf("|4.Exit				 |\n");
	printf("----------------------------------\n");
	scanf("%d",&n);
	switch(n) {
		case 1:
			/*first we check whether addition is possible
			using the isAddOrSubPossible().
			Note: we pass the address of row,col,row1,col1.This is
			the reason we did not use & in scanf in the function above.A call by reference is done 
			rather than a call by value because,in Call by Value a new copy of variable is made dedicatedly
			for the function and is deleted when the function is finished executing,
			while in call by reference the address of the variable is passed which means that 
			in call by value if you change the value inside a function,it will not affect the value
			in main function but if we call by reference it changes the original value as no copy is
			made for the new function.As we are getting user value for rows and columns inside 
			the function.we need to use that rows and column value in main()
			and other function.So we dont copy the variable for each function rather pass the address,So that we can
			use the values wherever we want.
			*/
			if(isAddOrSubPossible(&row,&col,&row1,&col1)) {
			/*if the contol comes here that means the matrices are eligible for addition*/
            		printf("\nEnter the first Matrix \n");
			/*so we populate both the matrices*/
	    		populateMatrix(matrixA,row,col);
            		printf("\nEnter the Second Matrix \n");
	    		populateMatrix(matrixB,row,col);
			/*Add both Matrices*/
            		addMatrix(matrixA,matrixB,sumMatrix,row,col);
	   		printf("\nThe first Matrix  is\n");
			/*display MatrixA,B and sumMatrix*/	    		
			displayMatrix(matrixA,row,col);
	    		printf("\nThe second Matrix is\n");
	    		displayMatrix(matrixB,row,col);
	    		printf("\nThe sum of two matrices is:\n");
	    		displayMatrix(sumMatrix,row,col);	
			}
			else { 	/*this happens when the matrices are not eligible for addition*/
				printf("The two matrices are not of same order hence Addition is Not Possible\n");
				printf("Exiting...\n");
			}        
			break;
		case 2:
			/*this is same as addtion*/
	    		if(isAddOrSubPossible(&row,&col,&row1,&col1)) {
            		printf("\nEnter the first Matrix \n");
            		populateMatrix(matrixA,row,col);
            		printf("\nEnter the Second Matrix \n");
            		populateMatrix(matrixB,row1,col1);
           		subtractMatrix(matrixA,matrixB,sumMatrix,row,col);
            		printf("\nThe first Matrix  is\n");
            		displayMatrix(matrixA,row,col);
         		printf("\nThe second Matrix is\n");
            		displayMatrix(matrixB,row1,col1);
            		printf("\nThe sum of two matrices is:\n");
            		displayMatrix(sumMatrix,row,col);
	   		}
			else {	
				printf("The two matrices are not of same order hence Addition is Not Possible\n");
				printf("Exiting...\n");
        		}
			break;
		case 3:
			/*same mechanism as add and sub*/
	    		if(isMulPossible(&row,&col,&row1,&col1)) {
            		printf("\nEnter the first Matrix \n");
            		populateMatrix(matrixA,row,col);
               		printf("\nEnter the Second Matrix \n");
            		populateMatrix(matrixB,row1,col1);
        		multiplyMatrices(matrixA,matrixB,sumMatrix,row,row1,col);
            		printf("\nThe first Matrix  is\n");
            		displayMatrix(matrixA,row,col);
            		printf("\nThe second Matrix is\n");
            		displayMatrix(matrixB,row1,col1);
            		printf("\nThe sum of two matrices is:\n");
           	 	displayMatrix(sumMatrix,row,col1);
	   		}
			else {	
				printf("The two matrices are not of correct order hence Multiplication is Not Possible\n");
				printf("Exiting...\n");
        		}	
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Wrong Option Exitting....");
			exit(0);
	}
	return 0;
}


