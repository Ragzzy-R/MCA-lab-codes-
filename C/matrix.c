#include<stdio.h>
#include<stdlib.h>
#define TRUE 	1
#define FALSE	0



int isAddOrSubPossible(int* row,int* col,int* row1,int* col1) {
	printf("Enter the number of rows and column of first matrix : \n");
	scanf("%d %d",row,col);
	printf("Enter the number of rows and columns of second matrix : \n");
	scanf("%d %d",row1,col1);
    	if((*row==*row1)&&(*col==*col1))
        	return TRUE;
    	else
     		return FALSE;
}	

int isMulPossible(int* row,int* col,int* row1,int* col1) {
    	printf("Enter the number of rows and column of first matrix : \n");
   	scanf("%d %d",row,col);
    	printf("Enter the number of rows and columns of second matrix : \n");
    	scanf("%d %d",row1,col1);
    	if(*col==*row1)
        	return TRUE;
   	else
        	return FALSE;
}

void populateMatrix(int matrix[][5],int row,int col) {
	int i,j;
    	for(i=0;i<row;i++) {
        	for(j=0;j<col;j++) {
        		printf("Enter the Element (%d,%d)",i+1,j+1);
            		scanf("%d",&matrix[i][j]);
		}
    	}
    
}
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

int addMatrix(int matrixA[][5],int matrixB[][5],
		int matrixC[][5],int row,int col) {
	int i,j;
	for(i=0;i<row;i++) {
                for(j=0;j<col;j++) {
                        matrixC[i][j]=matrixA[i][j]+matrixB[i][j];
                }
        }

}

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

int subtractMatrix(int matrixA[][5],int matrixB[][5],
		int matrixC[][5],int row,int col) {
	int i,j;
        for(i=0;i<row;i++) {
                for(j=0;j<col;j++) {
                        matrixC[i][j]=matrixA[i][j]-matrixB[i][j];
                }
        }
}

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
			if(isAddOrSubPossible(&row,&col,&row1,&col1)) {
            		printf("\nEnter the first Matrix \n");
	    		populateMatrix(matrixA,row,col);
            		printf("\nEnter the Second Matrix \n");
	    		populateMatrix(matrixB,row,col);
            		addMatrix(matrixA,matrixB,sumMatrix,row,col);
	   		printf("\nThe first Matrix  is\n");
	    		displayMatrix(matrixA,row,col);
	    		printf("\nThe second Matrix is\n");
	    		displayMatrix(matrixB,row,col);
	    		printf("\nThe sum of two matrices is:\n");
	    		displayMatrix(sumMatrix,row,col);	
			}
			else {
				printf("The two matrices are not of same order hence Addition is Not Possible\n");
				printf("Exiting...\n");
			}        
			break;
		case 2:
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


