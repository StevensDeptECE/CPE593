import java.util.Stack;
public class GraphMatrix {
	private double[][] w;
	private int V;
	public GraphMatrix(int V) {
		w = new double[V][V];
		this.V = V;
    for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)		
				w[i][j] = Double.POSITIVE_INFINITY;
	}
	public void set(int i, int j, double w) {
		this.w[i][j] = w;
		this.w[j][i] = w;
	}
	public double adjacent(int i, int j) {
		return w[i][j];
	}
	public void DFS(int v) {
		boolean[] visited = new boolean[V]; // all false in Java
		Stack<Integer> todo = new Stack<>();
		visited[v] = true;
		todo.push(v);
		while (!todo.isEmpty()) {
			int v2 = todo.pop();
			System.out.print(v2);
			for (int j = 0; j < V; j++)
				if (j != v2 && w[v2][j] < Double.POSITIVE_INFINITY && !visited[j]) {
          visited[j] = true;
					todo.push(j);
				}
		}
	}
	public static void main(String[] args) {
		GraphMatrix g = new GraphMatrix(5);
		g.set(0,1, 1.0);
		g.set(1,2, 1.5);
		g.set(2,3, 2.0);
		g.set(3,4, 2.5);
		g.DFS(0);
	}
}
