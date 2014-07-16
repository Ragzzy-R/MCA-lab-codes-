/*2. To write a java program to find the result of the following expressions
i)(a<<2) + (b>>2)
ii)(b>0)
iii)(a+b*100) /10
iv)a & b
Assume a=10 and b=5 
*/


class Exp2 {
	
	public static void main(String args[]) {
		int a = 10;
		int b = 5;
		System.out.println((a<<2) + (b>>2));
		System.out.println((b>0));
		System.out.println((a+b*100) /10);
		System.out.println(a & b);
	}
	
}