import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
/**
 *
 * @author dkruger
 */
public class TestRBTreeViewer extends JFrame {
  private RBTree t;
  private int currentV;
  private RBTreeViewer rbv;
  public TestRBTreeViewer() {
    super("RB-Tree Viewer");
    setSize(1000,1000);
    Container c = getContentPane();
    t = new RBTree();
    rbv = new RBTreeViewer(t);
    c.add(rbv, BorderLayout.CENTER);
    JButton b = new JButton("add");
    b.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        t.add(++currentV);
        rbv.repaint();
      }
    });
    c.add(b, BorderLayout.SOUTH);
    setVisible(true);
  }
  public static void main(String[] args) {
    new TestRBTreeViewer();
  }  
}
