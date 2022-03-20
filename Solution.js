
/**
 * @param {number[]} input
 * @return {number[]}
 */
var frequencySort = function (input) {
    this.MIN_INPUT_VALUE = -100;
    this.MAX_INPUT_VALUE = 100;
    this.INPUT_RANGE = Math.abs(MIN_INPUT_VALUE) + MAX_INPUT_VALUE + 1;

    const frequency = new Array(INPUT_RANGE).fill(0);
    for (let value of input) {
        frequency[convertValueToIndexFrequency(value)]++;
    }

    const size = input.length;
    for (let i = 0; i < size; i++) {
        input[i] = frequency[convertValueToIndexFrequency(input[i])] * INPUT_RANGE + MAX_INPUT_VALUE - input[i];
    }

    input.sort((x, y) => x - y);
    for (let i = 0; i < size; i++) {
        input[i] = MAX_INPUT_VALUE - input[i] % INPUT_RANGE;
    }

    return input;
};

/**
 * @param {number} value
 * @return {number}
 */
function convertValueToIndexFrequency(value) {
    return Math.abs(this.MIN_INPUT_VALUE) + value;
}
