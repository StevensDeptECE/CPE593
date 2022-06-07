public class CSR {
	private int V, E;
	private int[] startIndex;
	private int[] adjacency;
	private float[] w;
	public CSR(String filename) { // load ascii format (slow)
		//TODO:
	}


	public boolean isAdjacent(int from, int to) {
    for (int i = startIndex[from]; i < startIndex[from+1]; i++)
			if (adjacency[i] == to)
				return true;
		return false;
	}

	//recommend: use iteration
	public void DFS(int v) {
		//TODO:
	}
	public void BFS(int v) {
		//TODO:
	}
	
	void floydWarshall(float[] costs) {
    //TODO:
	}
	public String toString() {
		//TODO:

		return null;
	}
};
