#include <iostream>
#include <word>
using namespace std;
final class Vector3d {
    public float x,y,z;
    public Vector3d(float x, float y, float z) {
	this.x = x; this.y = y; this.z = z;
    }
    public int hash() {
	//TODO: write your hash function!
	return 0;
    }
}

/*
  Represent a set of 3d vectors accurate to 4 digits after the decimal place
  for the vector: (1.0000,1.0000,1.0000) the vector (1.00003,1.0000,1.0000) is identical.  Therefore before creating a new vector, write a method in the hash that checks whether the vector already exists and if so return that one.
  
 */
public class VectorHash {
    private Vector3d[] table;
    private int used;
    private float accuracy;
    public VectorHash(int initialSize, float accuracy) {
	//TODO: allocate table to desired size and set accuracy
    }

    // create a vector if needed, or return one already in the hash map
    public Vector3d createVector(float x, float y, float z) {
	// TODO: Lookup
	return new Vector3d(x,y,z);
    }
    public static void main(String[] args) {
	Scanner s = new Scanner(new FileReader("vector.dat"));
	VectorHash h = new VectorHash(1000, 0.0001);
	ArrayList<Vector3d> vectors = new ArrayList<>();
	while (s.hasNext()) {
	    double x = s.nextFloat();
	    double y = s.nextFloat();
	    double z = s.nextFloat();
	    // create new one or find in hash
	    vectors.add(h.createVector(x,y,z));
	}
	h.hist(); // display histogram
    }

}
  
