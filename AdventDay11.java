import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import static java.lang.Integer.parseInt;

public class Main {
    static List<int[]> parsedRocks = new ArrayList<>();

    public static void main(String[] args) {
        partOne(args);
    }

    public static void partOne(String[] args) {
        fileReader(args);
        int[] initalRocks = parsedRocks.get(0);
        ArrayList<String> stones = new ArrayList<>();
        for (int val : initalRocks) {
            stones.add(Integer.toString(val));
        }

        int blinks = 25;
        for (int i = 0; i < blinks; i++) {
            ArrayList<String> newStones = new ArrayList<>();
            for (String stone : stones) {
                if (stone.equals("0")) {
                    newStones.add("1");
                }
                else if (stone.length() % 2 == 0) {
                    int middle = stone.length() / 2;
                    String stoneLeft = stone.substring(0, middle);
                    String stoneRight = stone.substring(middle);
                    newStones.add(Integer.toString(Integer.parseInt(stoneLeft)));
                    newStones.add(Integer.toString(Integer.parseInt(stoneRight)));
                }
                else
                {
                    Long multiply = Integer.parseInt(stone) * 2024L;
                    newStones.add(Long.toString(multiply));
                }
            }
            stones = newStones;
        }
        System.out.println("Amount of stones after 25 blinks: " + stones.size());
    }

    public static void partTwo(String[] args) {

    }

    public static void fileReader(String[] args) {

        // step 1: create a file object
        File f = new File("src/data");

        String fileData = "";
        try {
            Scanner s = new Scanner(f);
            while (s.hasNextLine()) {
                String currentLine = s.nextLine();
                fileData += currentLine + "\n";
            }

            // a String array where every item in the array is a line from the file
            String[] fileArray = fileData.split("\n");

            for (String line : fileArray) {
                // split by space, now we have a list of String numbers
                String[] stringNumbers = line.split(" ");

                // create an array of integers
                int[] numbers = new int[stringNumbers.length];

                // convert string numbers into integers
                for (int i = 0; i < numbers.length; i++) {
                    numbers[i] = parseInt(stringNumbers[i]);
                }
                parsedRocks.add(numbers);
            }
        }
        catch (FileNotFoundException fe) {
            System.out.println("File was not found");
            System.exit(1);
        }

    }
}
