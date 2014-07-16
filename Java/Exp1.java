
/*1. To write a java program to find the area of rectangle using command line arguments.*/

class Exp1 {
	public static void main(String args[]) 
	{
		int length,breadth;
		length	= Integer.parseInt(args[0]);
		breadth = Integer.parseInt(args[1]);
		System.out.println("The area of this rectangle is : " + (length * breadth));
	}
}