
// in front is size of the block = 4 bytes 8
// 8 bytes
class Elephant {
	private int x; // 4 bytes of dead space
}

public class memory {

	public static void main(String[] args) {
		Elephant e = new Elephant();
		Elephant[] ea =new Elephant[100]; // 100*4
		ea[0] = e; // + 100*16
	}


	/* C++

   class Elephant {
   private:
     int x;
   };
   Elephant ea[100]; // 400 bytes



   Elephant* eap[100]
