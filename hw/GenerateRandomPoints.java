import java.util.*;
import java.io.*;

public class GenerateRandomPoints {
	public static void main(String[] args) throws IOException {
		int n = Integer.parseInt(args[0]);
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("randompts.dat")));
		Random r = new Random();
		for (int i = 0; i < n; i++) {
			out.printf("%6.5f %6.5f\n", r.nextDouble(), r.nextDouble());
		}
		out.close();
	}
}
			
