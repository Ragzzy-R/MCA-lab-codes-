/*
	4.Write a program to print the following triangle of binary digits.

	(i)	  1 
	1 0 1 
	1 0 0 0 1 
	1 0 0 0 0 0 1 
	1 0 0 0 0 0 0 0 1 

	(ii)
	1
	1 2
	1 2 3
	1 2 3 4
	1 2 3 4 5 
 */
 
 class Exp4 {
	
	public static void main(String args[]) 
	{
		int count = 0;
		count = Integer.parseInt(args[0]);
		
		for(int i = 1 ; i <= count; i++) {
			System.out.print("1");
			for(int j = 0; j< i; j++) {
				System.out.print("0");
			}
			System.out.println("1");
		}
		
		for(int i = 1 ; i <= count+1; i++) {
			
			for(int j = 1; j< i; j++) {
				System.out.print(j);
				}
			System.out.println();
			}
	}
}