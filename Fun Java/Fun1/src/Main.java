import java.util.*;

public class Main {
	
	Scanner in = new Scanner(System.in);

	int factorial(int n) {
		int result = n;
		if(n == 0) return 1;
		for(int i = n - 1; i > 0; i--) result *= i;
		return result;
	}
	
	int binom_coeff(int n, int k) {
		return (factorial(n) / (factorial(n - k) * factorial (k)));
	}
	
	void print_pascal(int size) {
		for(int i = 0; i < size; i++) {
			if(i == 0) continue;
			for(int j = 0; j < i; j++) {
				System.out.print(binom_coeff(i - 1, j) + " ");
			}
			System.out.println();
		}
	}
	
	void print_algebra(int size,int a, int b) {
		int tempExp1 = size, tempExp2 = 0;
		for(int i = 0; i <= size; i++) {
			System.out.print(binom_coeff(size, i));
			System.out.print("<a^" + tempExp1--);
			System.out.print("b^" + tempExp2++ + ">");
			if(i != size) System.out.print("+");
		}
		System.out.println();
		
		tempExp1 = size; tempExp2 = 0;
		
		for(int i = 0; i <= size; i++) {
			System.out.print(binom_coeff(size, i));
			System.out.printf("<%.0f>", Math.pow(a, tempExp1--) * Math.pow(b, tempExp2++));
			if(i != size) System.out.print("+");
		}
		System.out.println();
		
		int result = 0;
		tempExp1 = size; tempExp2 = 0;
		
		for(int i = 0; i <= size; i++) {
			result += binom_coeff(size, i) * Math.pow(a, tempExp1--) * Math.pow(b, tempExp2++);
		}
		System.out.println(result);
		
	}
	
	public Main() {
		int n,a,b;
		System.out.print("Masukkan nilai n : ");
		n = in.nextInt();
		System.out.print("Masukkan nilai a : ");
		a = in.nextInt();
		System.out.print("Masukkan nilai b : ");
		b = in.nextInt();
		
		print_algebra(n, a, b);
		
	}
	
	public static void main(String[] args) {
		new Main();
	}
}
