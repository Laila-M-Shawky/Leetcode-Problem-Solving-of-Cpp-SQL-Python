#include <limits> // Required for std::numeric_limits

class Solution {
public:
    int reverse(int x) {
        long long reversed_num = 0; // Use long long to safely store intermediate results

        while (x != 0) {
            int digit = x % 10; // Get the last digit of x
            x /= 10;            // Remove the last digit from x

            // Check for potential overflow before multiplying and adding the digit
            // For positive overflow:
            if (reversed_num > std::numeric_limits<int>::max() / 10 ||
                (reversed_num == std::numeric_limits<int>::max() / 10 && digit > 7)) {
                return 0; // If it will overflow INT_MAX, return 0
            }
            // For negative overflow (underflow):
            if (reversed_num < std::numeric_limits<int>::min() / 10 ||
                (reversed_num == std::numeric_limits<int>::min() / 10 && digit < -8)) {
                return 0; // If it will underflow INT_MIN, return 0
            }

            reversed_num = reversed_num * 10 + digit; // Build the reversed number
        }

        // Cast the long long result back to int for the final return
        return static_cast<int>(reversed_num);
    }
};