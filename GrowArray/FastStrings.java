/**
Original, slow code:

class A {
	public String toString() { return "a"; }
}

class B{

	public String toString() { return "a"; }

}

class C {

	public String toString() { return "a"; }

}

class D {
	private A a1;
	private B b1;
	private C c1;

	public String toString() {
		a1.toString() + "," + b1.toString() + "," + c1.toString();
	}
}
*/

class A {
	public void append(StringBuilder b) { b.append("a"); }
}

class B{

	public void append(StringBuilder b) { b.append("b"); }

}

class C {

	public void append(StringBuilder b) { b.append("c"); }

}

class D {
	private A a1;
	private B b1;
	private C c1;

	public void append(StringBuilder b) {
		a1.append(b);
		b1.append(b);
		c1.append(b);
	}
}

class Test {
	public static void main(String[] args) {
		StringBuilder b = new StringBuilder(1024*1024);
		A a1 =  new A();
		B b1 = new B();
		C c1 = new C();
		D d = new D();
		a1.append(b);


	}
