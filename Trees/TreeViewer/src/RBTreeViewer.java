import javax.swing.*;
import java.awt.*;
import java.util.Observable;
import java.util.Observer;

public class RBTreeViewer extends JPanel {
	private RBTree t;
	public RBTreeViewer(RBTree t) {
		this.t = t;
	}
	public void paint(Graphics g) {
    Rectangle r = new Rectangle();
    int d = 30;
    g.getClipBounds(r);
    RBTree.Node p = t.getRoot();
    if (p == null)
      return;
		p.draw(g, r.width/2, d, d, 50,50);
	}
}

		
