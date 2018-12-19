import java.applet.*;
import java.awt.event.*;
import java.awt.*;
import java.awt.Graphics;

public class Exp extends Applet implements ActionListener {
    Button red, green, blue;
    public void init() {
        red = new Button("RED");
        green = new Button("GREEN");
        blue = new Button("BLUE");

        add(red);
        add(green);
        add(blue);

        red.addActionListener(this);
        green.addActionListener(this);
        blue.addActionListener(this);
    }

    public void actionPerformed(ActionEvent ae) {
        String s = ae.getActionCommand();

        if(s.equals("RED")) {
            showStatus("You pressed RED");
            setBackground(Color.RED);
        } else if(s.equals("GREEN")) {
            showStatus("You pressed GREEN");
            setBackground(Color.GREEN);
        } else {
            showStatus("You pressed BLUE");
            setBackground(Color.BLUE);
        }
    }

    public void paint(Graphics g) {
        g.drawString("Hello", 1, 1);
    }
}