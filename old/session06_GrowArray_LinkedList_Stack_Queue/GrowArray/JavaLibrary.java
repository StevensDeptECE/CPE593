import java.util.*;

public class JavaLibrary {
	public static void main(String[] args) {
		final int n  = Integer.parseInt(args[0]);
		ArrayList<Integer> list = new ArrayList<>(n);
		for (int i = 0; i < n; i++)
			list.add(i); // .add(new Integer(i)
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += list.get(i);
		System.out.println(sum);

		

	}
}
