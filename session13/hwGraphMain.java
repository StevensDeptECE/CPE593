public class hwGraphMain {
	public static void main(String[] args) {
		CSR csr = new CSR("hwgraph.dat");
		csr.dfs(0); // print out vertices starting with vertex 0 = 0 1 2 4 3 5
		csr.bfs(0); // 0 1 3 2 4 5
		float [] dist = new float[6*6];
		csr.floydWarshall(dist);

		int c = 0;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++)
				System.out.print(dist[c++] + "\t");
			System.out.println();
		}
		
	}

}
