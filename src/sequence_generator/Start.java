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
    Integer length = 12;

    if (args.length == 1)
      length = Integer.parseInt(args[0]);

    for (int i=0; i<100; i++)
      System.out.println(generateRandomString(length));

  }

  private static String generateRandomString(Integer length) {
    Random random = new Random();
    int max = basenPaare.length;
    StringBuffer buffer = new StringBuffer();

    for (int i = 0; i < length; i++) {
      int value = random.nextInt(max);
      buffer.append(basenPaare[value]);
    }

    return buffer.toString();
  }
}

