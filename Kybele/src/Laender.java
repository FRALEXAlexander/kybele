import java.awt.Color;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.Vector;
import jssc.SerialPort;
import jssc.SerialPortException;

public class Laender {

	HashMap<String, Vector<Integer>> hmap = new HashMap<String, Vector<Integer>>();

	static Color[] LEDStrip = new Color[136];
	String SerialPortName;
	boolean isPortOpened = false;
	SerialPort serialPort;

	public Laender() {
		init();
	}

	private void init() {
		// TODO Auto-generated method stub
		Vector<Integer> tmp = new Vector<Integer>();

		// -------Anfang-Nordamerika
		int i;
		tmp = new Vector<Integer>();
		for (i = 0; i < 2; i++) {
			tmp.add(i);
		}
		hmap.put("Alaska", tmp);
		// 2

		tmp = new Vector<Integer>();
		for (i = 2; i < 5; i++) {
			tmp.add(i);
		}
		hmap.put("Kanada", tmp);
		// 3

		tmp = new Vector<Integer>();
		for (i = 5; i < 8; i++) {
			tmp.add(i);
		}
		hmap.put("USA", tmp);
		// 3

		tmp = new Vector<Integer>();
		for (i = 8; i < 10; i++) {
			tmp.add(i);
		}
		hmap.put("Mexiko", tmp);
		// 2

		// --------------Ende-Nordamerika
		tmp = new Vector<Integer>();
		for (i = 0; i < 10; i++) {
			tmp.add(i);
		}
		hmap.put("Nordamerika", tmp);
		// 5

		// ------------Anfang-Südamerika
		tmp = new Vector<Integer>();
		tmp.add(10);
		hmap.put("Guatemala", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(11);
		hmap.put("Panama", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(12);
		hmap.put("Kuba", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(13);
		hmap.put("Kolumbien", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(14);
		hmap.put("Venezuela", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(15);
		hmap.put("Guyana", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(16);
		hmap.put("Suriname", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(17);
		hmap.put("Ecuador", tmp);
		// 1

		tmp = new Vector<Integer>();
		for (i = 18; i < 20; i++) {
			tmp.add(i);
		}
		hmap.put("Peru", tmp);
		// 2

		tmp = new Vector<Integer>();
		for (i = 20; i < 23; i++) {
			tmp.add(i);
		}
		hmap.put("Brasilien", tmp);
		// 3

		tmp = new Vector<Integer>();
		tmp.add(23);
		hmap.put("Bolivien", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(24);
		hmap.put("Paraguay", tmp);
		// 1

		tmp = new Vector<Integer>();
		for (i = 25; i < 27; i++) {
			tmp.add(i);
		}
		hmap.put("Argentinien", tmp);
		// 2

		// AUS

		tmp = new Vector<Integer>();
		tmp.add(27);
		hmap.put("Uruguay", tmp);
		// 1

		// -----Ende-Südamerika
		tmp = new Vector<Integer>();
		for (i = 10; i < 28; i++) {
			tmp.add(i);
		}
		hmap.put("Nordamerika", tmp);
		// 5

		tmp = new Vector<Integer>();
		for (i = 28; i < 31; i++) {
			tmp.add(i);
		}
		hmap.put("Grönland", tmp);
		// 2

		// -------Anfang-Europa
		tmp = new Vector<Integer>();
		tmp.add(31);
		hmap.put("Island", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(32);
		hmap.put("Irland", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(33);
		hmap.put("England", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(34);
		hmap.put("Norwegen", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(35);
		hmap.put("Schweden", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(36);
		hmap.put("Finnland", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(37);
		hmap.put("Baltische Staaten", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(38);
		hmap.put("Polen", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(39);
		hmap.put("Deutschland", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(40);
		hmap.put("Niederlande", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(41);
		hmap.put("Frankreich", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(42);
		hmap.put("Schweiz", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(43);
		hmap.put("Österreich", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(44);
		hmap.put("Ungarn", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(45);
		hmap.put("Weißrussland", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(46);
		hmap.put("Ukraine", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(47);
		hmap.put("Rumänien", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(48);
		hmap.put("Bulgarien", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(49);
		hmap.put("Serbien", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(50);
		hmap.put("Italien", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(51);
		hmap.put("Griechenland", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(52);
		hmap.put("Spanien", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(53);
		hmap.put("Portugal", tmp);
		// 1

		// ------Ende-Europa
		tmp = new Vector<Integer>();
		for (i = 31; i < 54; i++) {
			tmp.add(i);
		}
		hmap.put("Europa", tmp);
		// 5

		////ALEX INDEX
		
		
		// ------Anfang-Afrika
		tmp = new Vector<Integer>();
		tmp.add(54);
		hmap.put("Marokko", tmp);
		// 1

		tmp = new Vector<Integer>();
		for (i = 55; i < 57; i++) {
			tmp.add(i);
		}
		hmap.put("Algerien", tmp);
		// 2

		tmp = new Vector<Integer>();
		tmp.add(57);
		hmap.put("Libyen", tmp);
		// 1

		// ---------------------------------------

		tmp = new Vector<Integer>();
		tmp.add(58);
		hmap.put("Ägypten", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(59);
		hmap.put("Sudan", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(60);
		hmap.put("Tschad", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(61);
		hmap.put("Niger", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(62);
		hmap.put("Mali", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(63);
		hmap.put("Mauretanien", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(64);
		hmap.put("Sahara", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(65);
		hmap.put("Senegal Gambia", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(66);
		hmap.put("Guinea", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(67);
		hmap.put("Coged'ivoire", tmp);
		// 1

		// --------------------------------

		tmp = new Vector<Integer>();
		tmp.add(68);
		hmap.put("Burkina Faso", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(69);
		hmap.put("Nigeria", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(70);
		hmap.put("Kamerun", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(71);
		hmap.put("Zentralafrika", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(72);
		hmap.put("Äthiopien", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(73);
		hmap.put("Somalia", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(74);
		hmap.put("Kenia", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(75);
		hmap.put("Uganda", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(76);
		hmap.put("Tansanuia", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(77);
		hmap.put("Zaire", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(78);
		hmap.put("Kongo", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(79);
		hmap.put("Gabun", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(80);
		hmap.put("Angola", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(81);
		hmap.put("Sambia", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(82);
		hmap.put("Mosambik", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(83);
		hmap.put("Simbabwe", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(84);
		hmap.put("Botsuana", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(85);
		hmap.put("Namibia", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(86);
		hmap.put("Südafrika", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(87);
		hmap.put("Madagaska", tmp);
		// 1

		// -----Ende-Afrika
		tmp = new Vector<Integer>();
		for (i = 54; i < 88; i++) {
			tmp.add(i);
		}
		hmap.put("Afrika", tmp);
		// 5
		
		//--------Anfang-Asien
		tmp = new Vector<Integer>();
		tmp.add(88);
		hmap.put("Jemen", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(89);
		hmap.put("Oman", tmp);
		// 1

		// ------1LED mehr

		tmp = new Vector<Integer>();
		for (i = 88; i < 91; i++) {
			tmp.add(i);
		}
		hmap.put("Saudi-Arabien", tmp);
		// 2

		tmp = new Vector<Integer>();
		tmp.add(91);
		hmap.put("Irak", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(92);
		hmap.put("Syrien", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(93);
		hmap.put("Türkei", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(94);
		hmap.put("Georgien", tmp);
		// 1

		tmp = new Vector<Integer>();
		for (i = 95; i < 101; i++) {
			tmp.add(i);
		}
		hmap.put("Russland", tmp);
		// 5

		tmp = new Vector<Integer>();
		for (i = 101; i < 103; i++) {
			tmp.add(i);
		}
		hmap.put("Kasachstan", tmp);
		// 2

		tmp = new Vector<Integer>();
		tmp.add(103);
		hmap.put("Usbekistans", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(104);
		hmap.put("Turkmenistan", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(105);

		hmap.put("Iran", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(106);
		hmap.put("Afghanistan", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(107);
		hmap.put("Pakistan", tmp);
		// 1

		tmp = new Vector<Integer>();
		for (i = 108; i < 111; i++) {
			tmp.add(i);
		}
		hmap.put("Indien", tmp);
		// 2

		tmp = new Vector<Integer>();
		for (i = 111; i < 115; i++) {
			tmp.add(i);
		}
		hmap.put("China", tmp);
		// 4

		tmp = new Vector<Integer>();
		tmp.add(115);
		hmap.put("Korea", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(116);
		hmap.put("Japan", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(117);
		hmap.put("Myanmar", tmp);
		// 1

		tmp = new Vector<Integer>();
		tmp.add(118);
		hmap.put("Thailand", tmp);
		// 1

		
		hmap.put("Philippinen", tmp);
		tmp.add(119);
		// 1

		hmap.put("Malaysia", tmp);
		tmp.add(120);
		// 1

		tmp = new Vector<Integer>();
		for (i = 121; i < 125; i++) {
			tmp.add(i);
		}
		hmap.put("Indonesien", tmp);
		// 4

		//------Ende-Asien
		tmp = new Vector<Integer>();
		for (i = 88; i < 125; i++) {
			tmp.add(i);
		}
		hmap.put("Asien", tmp);
		// 5
		
		
		tmp = new Vector<Integer>();
		for (i = 125; i < 129; i++) {
			tmp.add(i);
		}
		hmap.put("Australien", tmp);
		// 3

		tmp = new Vector<Integer>();
		for (i = 129; i < 131; i++) {
			tmp.add(i);
		}
		hmap.put("Neuseeland", tmp);
		// 2

		tmp = new Vector<Integer>();
		for (i = 131; i < 136; i++) {
			tmp.add(i);
		}
		hmap.put("Antarktis", tmp);
		// 5

		// init ledStrip
		for (i = 0; i < LEDStrip.length; i++) {
			LEDStrip[i] = Color.BLACK;
		}

	}

	public static void main(String[] args) throws InterruptedException {
		Laender tmpStrip = new Laender();
		tmpStrip.setSerialPort("COM20");

		// while(true){
		// tmpStrip.setColor("Alaska", Color.green);
		// tmpStrip.sendToLEDs();
		// Thread.sleep(1000);
		// tmpStrip.setColor("Kanada", Color.white);
		// tmpStrip.sendToLEDs();
		// Thread.sleep(1000);

		// //green == blue color
		// //blue == green color
		//
		// }

		while (true) {
			for (int i = 0; i < 28; i++) {
				System.out.println(i);
				LEDStrip[i] = getColor();
				LEDStrip[i + 1] = Color.black;
				tmpStrip.sendToLEDs();
				// Thread.sleep(0);
			}
		}
		//
		// Vector<Integer> tmpReturn = hmap.get("Peru");
		// for (Iterator<Integer> iterator = tmpReturn.iterator();
		// iterator.hasNext();) {
		// Integer integer = (Integer) iterator.next();
		// System.out.println(integer);
		// }

	}

	private static Color getColor() {

		Color c = new Color(((int) (Math.random() * 255)), ((int) (Math.random() * 255)),
				((int) (Math.random() * 255)));

		return c;
	}

	private void setSerialPort(String string) {
		SerialPortName = string;
	}

	private void sendToLEDs() {
		StringBuffer tmpString = new StringBuffer();
		for (int i = 0; i < LEDStrip.length; i++) {
			tmpString.append(LEDStrip[i].getRed() + "," + LEDStrip[i].getBlue() + "," + LEDStrip[i].getGreen());
			// tmpString.append(Math.random()*255 + "," + Math.random()*255 +
			// "," + Math.random()*255);
			if (i + 1 < LEDStrip.length) {
				tmpString.append(':');
			} else {
				tmpString.append('!');
			}
		}
		// tmpString = new StringBuffer("25,25,25:0,0,0:200,150,130!");

		sendToSerial(tmpString.toString());

	}

	private void sendToSerial(String valuesToSend) {
		if (!isPortOpened) {
			initSerial();
		}

		try {
			serialPort.writeString(valuesToSend);
		} catch (SerialPortException e) {
			// TODO Auto-generated catch block
			System.out.println("There are an error on writing string to port т: " + e);
		}
	}

	private void initSerial() {
		serialPort = new SerialPort(SerialPortName);
		try {
			serialPort.openPort();

			serialPort.setParams(SerialPort.BAUDRATE_115200, SerialPort.DATABITS_8, SerialPort.STOPBITS_1,
					SerialPort.PARITY_NONE);

			// serialPort.setFlowControlMode(SerialPort.FLOWCONTROL_RTSCTS_IN |
			// SerialPort.FLOWCONTROL_RTSCTS_OUT);
			Thread.sleep(2000);
			isPortOpened = true;
		} catch (SerialPortException ex) {
			System.out.println("There are an error on writing string to port т: " + ex);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

	}

	private void setColor(String land, Color col_to_set) {
		Vector<Integer> integers = hmap.get(land);
		System.out.println(integers);

		for (Iterator<Integer> iterator = integers.iterator(); iterator.hasNext();) {
			Integer position = (Integer) iterator.next();
			LEDStrip[position] = col_to_set;
		}
	}

}