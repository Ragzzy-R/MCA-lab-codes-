/*
 * To write a java program to print the individual digits of a 3 digit number
 */

class Exp3 {
		
	public static void main(String args[]) {
		int number 	= 0;
		int quotient	= 0;
		int remainder 	= 0;
		int place 	= 1;
		number = Integer.parseInt(args[0]);
		System.out.println("The individual digits are : ");
		do {
			remainder = number%10;
			quotient  = number/10;
			number 	  = quotient;
			System.out.println(remainder + " "+ place + "Th place");
			place *=10;
			
		}while(number > 0);
	}
}
