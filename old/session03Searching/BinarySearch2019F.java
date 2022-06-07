/*
	What is the complexity of searching for a number > all numbers in the list


 */

public class BinarySearch2019F {
	//O(log n)  omega(1)
	public static int binarySearch(int[] list, int target) {
		int L = 0, R = list.length - 1;
		int mid;
		if (list[0] > target || list[list.length-1] < target)
			return -1;
 		do {
			mid = (L + R) / 2;
			if (list[mid] > target) {
				R = mid - 1;
			} else if (list[mid] < target) {
				L = mid + 1;
			} else {
				return mid;
			}
		} while (L <= R);

		return -1;
	}

	public static int recursiveBinarySearch(int[] list,
																					int L, int R, int target) {
		if (L > R)
			return -1;
		int mid = (L + R) / 2;
		if (list[mid] > target)
			return recursiveBinarySearch(list, L, mid-1, target);
		else if (list[mid] < target)
			return recursiveBinarySearch(list, mid+1, R, target);
		return mid;
	}
	
	public static void main(String[] args) {
		int[] x = {1, 2, 4, 5, 19, 20, 24, 48, 52};
		System.out.println(binarySearch(x, 1));
		System.out.println(binarySearch(x, 52));
		System.out.println(binarySearch(x, 19));
		System.out.println(binarySearch(x, 6));
		System.out.println(binarySearch(x, -1));
		System.out.println(binarySearch(x, 100));
	}
}
