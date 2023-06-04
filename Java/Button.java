import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class Button extends JFrame {
    int i = 0;
    public JButton B0, B1, B2, BC;
    JLabel temp;

    public Button() {
        setTitle("ContentPane과 JFrame");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container contentPane = getContentPane();
        contentPane.setLayout(new FlowLayout());
        B0 = new JButton("0");
        B1 = new JButton("1");
        B2 = new JButton("2");
        BC = new JButton("C");

        B0.setBackground(Color.CYAN);
        B1.setBackground(Color.CYAN);
        B2.setBackground(Color.CYAN);
        BC.setBackground(Color.CYAN);

        B0.addActionListener(new MyActionListener());
        B1.addActionListener(new MyActionListener());
        B2.addActionListener(new MyActionListener());
        BC.addActionListener(new MyActionListener());
        temp = new JLabel("                                                        ", JLabel.CENTER);

        contentPane.add(B0);
        contentPane.add(B1);
        contentPane.add(B2);
        contentPane.add(BC);

        temp.setOpaque(true);
        temp.setBackground(Color.ORANGE);
        contentPane.add(temp);

        setSize(300, 150);
        setVisible(true);
    }

    private class MyActionListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
        	String str = temp.getText();
        	StringBuilder sb = new StringBuilder(str);
        	
            if (e.getSource() == B0) {
            	sb.setCharAt(i, '0');
                str = sb.toString();
                if (i==1 && str.charAt(i-1)=='0') {
                	return;
                }
                i++;
                temp.setText(str);
                
            } else if (e.getSource() == B1) {
            	sb.setCharAt(i, '1');
                i++;
                temp.setText(sb.toString());
            } else if (e.getSource() == B2) {
            	sb.setCharAt(i, '2');
                i++;
                temp.setText(sb.toString());
            } else if (e.getSource() == BC) {
                temp.setText("                                                        ");
                i = 0;
            }
        }
    }

    public static void main(String[] args) {
        new Button();
    }
}