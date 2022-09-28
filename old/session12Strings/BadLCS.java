public class BadLCS {
	public int lcs(String a, String b) {
		// dynamic programming: static int memo[][] = new int[m][n];
		if (a.length() == 0 || b.length() == 0)
		return 0;        //O(1)
	
		if (a.charAt(0) == b.charAt(0))
			return 1 + lcs(a.substr(1), b.substr(1));    //O(min(len(A),len(B))
		return max(lcs(a.substr(1),b), lcs(a,b.substr(1)));    //O(2^n)
	}
}
