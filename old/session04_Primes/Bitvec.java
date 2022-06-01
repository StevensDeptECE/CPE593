public class Bitvec {
	private int size;
	private long[] bits;
	public Bitvec(int size, boolean b) {
		this.size = size;
		final int WORDSIZE = (size + 63) / 64;
		this.bits = new long[WORDSIZE];
		long val = b ? 0xFFFFFFFFFFFFFFFFL : 0;
		for (int i = 0; i < WORDSIZE; i++)
			bits[i] = val;
	}
	/*
		0000000000x00000
    0000000000000001 << pos
    0000000000100000

	 */
  public void set(int i) {
		bits[i / 64] |= 1 << (i % 64);
		//		bits[i >> 6] |= 1 << (i & 0x3f);
	}

  	/*
		yyyyyyyyyyxyyyyy
    1111111111111110 << pos
    1111111111011111

	 */
	public void clear(int i) {
	bits[i / 64] &= ~(1 << (i % 64));
	//		bits[i >> 6] &= (1 << (i & 0x3f));
	}

	public boolean test(int i) {
		return (bits[i / 64] & (1 << (i % 64))) != 0;
	}

	public static void main(String[]args) {
		Bitvec b = new Bitvec(1024, false);
		System.out.println(b.test(65));
		b.set(128);
		System.out.println(b.test(128));
	}
}
