import java.util.*;
import java.io.*;

public class GenerateRandomPoints {
	public static void main(String[]args) throws Exception {
		int n = Integer.parseInt(args[0]);
		Random r = new Random();
		PrintWriter p = new PrintWriter(new FileWriter("randompts.dat"));
		for (int i = 0; i < n; i++)
			p.printf("%.6f % .6f\n", r.nextDouble(), r.nextDouble());
		p.close();
	}
}
			
	
