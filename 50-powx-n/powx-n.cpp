class Solution {
public:
    double myPow(double x, int n) {
        // Handle negative exponents
        if (n < 0) {
            x = 1 / x;
            // Use long long to handle the n = INT_MIN edge case
            return myPow_iterative(x, -(long long)n);
        }
        return myPow_iterative(x, n);
    }

private:
    double myPow_iterative(double x, long long n) {
        double result = 1.0;
        while (n > 0) {
            // If n is odd, multiply the result by the current power of x
            if (n % 2 == 1) {
                result *= x;
            }
            // Square x for the next iteration (equivalent to x^2)
            x *= x;
            // Halve n for the next iteration (equivalent to n/2)
            n /= 2;
        }
        return result;
    }
};