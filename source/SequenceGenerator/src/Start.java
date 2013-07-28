import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;

/**
 * 
 * @author Wojciech Konitzer
 *
 */
public class Start {

	private static String[] basenPaare = { "AT", "TA", "CG", "GC" };

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		createFile();

	}

	private static String generateRandomString(Random random) {
		int max = basenPaare.length;
		StringBuffer buffer = new StringBuffer();
		for (int i = 0; i < 12; i++) {
			int value = random.nextInt(max);
			buffer.append(basenPaare[value]);
		}
		return buffer.toString();
	}
	
	private static void createFile(){
		try{
            PrintWriter pWriter = new PrintWriter(new FileWriter("sequences.txt"));
            Random random = new Random();
    		for (int i = 0; i < 100; i++) {
    			String randomString = generateRandomString(random);
    			pWriter.println(randomString);
    		}
            
            pWriter.flush();
        }catch(IOException ioe){
            ioe.printStackTrace();
        }
	}

}
