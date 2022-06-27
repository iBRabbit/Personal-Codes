import java.util.*;

public class Array {
	
	Scanner in = new Scanner(System.in);
	final int MAX = 3;
	
	char[][] arr = new char[100][100];
	boolean isOver = false;
	
	
	void cls() {
		for(int i = 0; i < 50; i++) System.out.println();
	}
	
	void clearArray() {
	    for(int i = 0; i < MAX; i++){
	        for(int j = 0; j < MAX; j++)
	            arr[i][j] = '-';
	    }
	}
	
	void printArray() {
		System.out.println(" 1 2 3");
		for(int i = 0; i < MAX; i++) {
			for(int j = 0; j < MAX; j++)
				System.out.print(arr[i][j]);
			System.out.println();
		}
	}
	
	void check() {
		String checker = "";
		Character [] checkerArr = new Character[3];
		Boolean isFull = false;
		
		for(int i = 0; i < MAX; i++) {
			for(int j = 0; j < MAX; j++) {
				if(arr[i][j] == '-') isFull = false;
			}
		}
		
		for(int i = 0; i < MAX; i++) {
			for(int j = 0; j < MAX ; j++) {
				checkerArr[j] = arr[i][j];
			}
		
			checker = checkerArr.toString();
			
			if(checker.toString().compareTo("XXX") == 0) {
				System.out.println("X Win!");
				isOver = true;
				return;
			} else if(checker.toString().compareTo("OOO") == 0) {
				System.out.println("O Win!");
				isOver = true;
				return;
			}
			
			checker = "";
		}
		
		checker = "";
		
		for(int i = 0; i < MAX; i++) {
			for(int j = 0; j < MAX; j++) {
				checkerArr[j] = arr[j][i];
			}
			
			
			checker = checkerArr.toString();
			
			if(checker.toString().compareTo("XXX") == 0) {
				System.out.println("X Win!");
				isOver = true;
				return;
			} else if(checker.toString().compareTo("OOO") == 0) {
				System.out.println("O Win!");
				isOver = true;
				return;
			}
			
			checker = "";
		}
		
	    if(arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X'){
	        System.out.println("X WIN!");
	        isOver = true;
	        return;
	    } else if(arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O'){
	    	System.out.println("O WIN!");
	        isOver = true;    
	        return;
	    }

	    if(arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X'){
	    	System.out.println("X WIN!");
	        isOver = true;
	        return;
	    } else if(arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O'){
	    	System.out.println("O WIN!");
	        isOver = true;
	        return;
	    }

	    if(isFull == true){
	    	System.out.println("Draw!");
	        isOver = true;
	        return;
	    }
		
			
		
	}
	
	public Array() {
		clearArray();
		int turner = 0;
		
		do {
			cls();
			printArray();
			char playerTurn = 'X';
			int coordX = 0, coordY = 0;
			
			if(turner % 2 == 0) playerTurn = 'X';
			else playerTurn = 'O';
			
			System.out.println("Giliran Pemain : " + playerTurn + " untuk Jalan");
			System.out.println("===============================================");
			
			do {
				System.out.print("Enter X coordinate : ");
				coordX = in.nextInt();
				System.out.print("Enter Y coordinate : ");
				coordY = in.nextInt();
				
	            if(arr[coordY - 1][coordX - 1] != '-') System.out.println("Tempat sudah Terisi!");
	            if(coordX > 3 || coordY > 3 || coordX < 0 || coordY < 0) System.out.println("Input nilai 0 <= x,y <= 3!");
				
			} while((arr[coordY - 1][coordX - 1] != '-' || coordX > 3 || coordY > 3 || coordX < 0 || coordY < 0));
			
			arr[coordY - 1][coordX - 1] = playerTurn;
			cls();
			printArray();
			check();
			turner++;
			
		} while (isOver == false1);
		
	}
		
	public static void main(String[] args) {
		new Array();
	}
	
}
