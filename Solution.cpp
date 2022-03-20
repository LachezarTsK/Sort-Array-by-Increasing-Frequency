
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    
    inline static const int MIN_INPUT_VALUE {-100};
    inline static const int MAX_INPUT_VALUE {100};
    inline static const int INPUT_RANGE {-MIN_INPUT_VALUE + MAX_INPUT_VALUE + 1};
    
public:

    vector<int> frequencySort(vector<int>& input) {
        array<int, INPUT_RANGE> frequency{};
        for (const auto& value : input) {
            frequency[convertValueToIndexFrequency(value)]++;
        }

        const size_t size = input.size();
        for (int i = 0; i < size; i++) {
            input[i] = frequency[convertValueToIndexFrequency(input[i])] * INPUT_RANGE + MAX_INPUT_VALUE - input[i];
        }

        sort(input.begin(), input.end());
        for (int i = 0; i < size; i++) {
            input[i] = MAX_INPUT_VALUE - input[i] % INPUT_RANGE;
        }

        return input;
    }
    
private:

    int convertValueToIndexFrequency(int value) {
        return abs(MIN_INPUT_VALUE) + value;
    }
};
