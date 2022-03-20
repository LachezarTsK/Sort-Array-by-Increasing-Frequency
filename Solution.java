
import java.util.Arrays;

public class Solution {

    private static final int MIN_INPUT_VALUE = -100;
    private static final int MAX_INPUT_VALUE = 100;
    private static final int INPUT_RANGE = Math.abs(MIN_INPUT_VALUE) + MAX_INPUT_VALUE + 1;

    public int[] frequencySort(int[] input) {

        int[] frequency = new int[INPUT_RANGE];
        for (int value : input) {
            frequency[convertValueToIndexFrequency(value)]++;
        }

        final int size = input.length;
        for (int i = 0; i < size; i++) {
            input[i] = frequency[convertValueToIndexFrequency(input[i])] * INPUT_RANGE + MAX_INPUT_VALUE - input[i];
        }

        Arrays.sort(input);
        for (int i = 0; i < size; i++) {
            input[i] = MAX_INPUT_VALUE - input[i] % INPUT_RANGE;
        }

        return input;
    }

    private int convertValueToIndexFrequency(int value) {
        return Math.abs(MIN_INPUT_VALUE) + value;
    }
}
