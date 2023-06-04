import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
public class Layer extends JFrame {
	private final int FLYING_UNIT = 10;
	private JButton la = new JButton("버튼");
	public Layer() {
		setTitle("상,하,좌,우 키를 이용하여 버튼 움직이기");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(null);
		c.addKeyListener(new MyKeyListener());
		la.setLocation(50,50);
		la.setSize(100,20);
		c.add(la);
		setSize(300,300);
		setVisible(true);
		c.setFocusable(true);
		c.requestFocus();
		c.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				Component com = (Component)e.getSource();
				com.setFocusable(true);
				com.requestFocus();
			}
		});
	}
	class MyKeyListener extends KeyAdapter {
		public void keyPressed(KeyEvent e) {
			int keyCode = e.getKeyCode();

			switch(keyCode) {
			case KeyEvent.VK_UP:
				la.setLocation(la.getX(), la.getY()-FLYING_UNIT);
				break;
			case KeyEvent.VK_DOWN:
				la.setLocation(la.getX(), la.getY()+FLYING_UNIT);
				break;
			case KeyEvent.VK_LEFT:
				la.setLocation(la.getX()-FLYING_UNIT, la.getY());
				break;
			case KeyEvent.VK_RIGHT:
				la.setLocation(la.getX()+FLYING_UNIT, la.getY());
				break;
			}
			if(la.getX() <0) {
				la.setLocation(la.getX()+FLYING_UNIT,la.getY());
			}
			if (la.getX() >=200) {
				la.setLocation(la.getX()-FLYING_UNIT,la.getY());
			}
			if(la.getY() <0) {
				la.setLocation(la.getX(),la.getY()+FLYING_UNIT);
			}
			if (la.getY() >=250) {
				la.setLocation(la.getX(),la.getY()-FLYING_UNIT);
			}
		}
	}
	public static void main(String [] args) {
		new Layer();
	}
}