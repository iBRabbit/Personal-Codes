import java.io.File;
import java.io.FileReader;
import java.util.*;

import javax.xml.transform.Templates;

public class ReadFile {
	
	
	public ReadFile() {
		int size = 0;
		int testcase = 0, num1, num2, num3;
		
		try {
			String temp[];
			File fptr = new File("data.txt");
			
			if(fptr.exists() == false) {
				System.out.println("Data not found!");
			} else {
				
				Scanner sc = new Scanner(new FileReader("data.txt"));
				while(sc.hasNextLine()) {
					temp = sc.nextLine().split("\n");

				}
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	
		
	}
	
	public static void main(String[] args) {
		new ReadFile();
	}
}
