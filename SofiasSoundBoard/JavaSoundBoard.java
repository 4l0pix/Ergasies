package GUI;
import java.awt. *;
import javax.swing. *;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.SourceDataLine;

public class Main {

	public static void main(String[] args) {
		gui.window();
	}

}


class gui{
	public static void window() {
		JFrame frame = new JFrame("Sofia");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new FlowLayout());
		// fitaxnoume ena adeio label gia na katevasei katw ta koumpia
		JLabel emptyLabel = new JLabel(" ");
        emptyLabel.setPreferredSize(new Dimension(600, 200)); // epeksergazomaste tis diastaseis analogos gia na tairiazoun sto parathiro
        frame.getContentPane().add(emptyLabel);
		// koumpi 400
		JButton b400 = new JButton("400");
		b400.addActionListener(new mesazontas(400,5000));
		b400.setSize(50,50);
		frame.getContentPane().add(b400);
		
		// koumpi 800
		JButton b800 = new JButton("800");
		b800.addActionListener(new mesazontas(800,5000));
		b800.setSize(50,50);
		frame.getContentPane().add(b800);
		
		// koumpi 1000
		JButton b1000 = new JButton("1000");
		b1000.addActionListener(new mesazontas(1000,5000));
		b1000.setSize(50,50);
		frame.getContentPane().add(b1000);
		
		// koumpi 1200
		JButton b1200 = new JButton("1200");
		b1200.addActionListener(new mesazontas(1200,5000));
		b1200.setSize(50,50);
		frame.getContentPane().add(b1200);
		
		frame.setSize(600,300);
		frame.setVisible(true);
	}
	
}

class mesazontas implements ActionListener{
	private int sixnotita;
	private int diarkeia;
	
	public mesazontas(int sixnotita,int diarkeia) {
		this.sixnotita = sixnotita;
		this.diarkeia = diarkeia;
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		paikseHxo(sixnotita,diarkeia);
	}
	
	void paikseHxo(int sixnotita,int diarkeia) {
		try {
			AudioFormat af = new AudioFormat(44100, 8, 1, true,true);
			SourceDataLine line = AudioSystem.getSourceDataLine(af);
			line.open(af);
			line.start();
			int amplitude = 127;
			int samples = (int)((diarkeia*44100)/1000);
			byte [] buffer = new byte[samples];
			for (int i = 0; i<buffer.length;i++) {
				buffer[i] = (byte)(amplitude*Math.sin(2*Math.PI*sixnotita*i/44100));
			}
			line.write(buffer, 0, buffer.length);
			line.drain();
			line.close();
		} catch(Exception ex){
			ex.printStackTrace();
		}
	}
	
}
