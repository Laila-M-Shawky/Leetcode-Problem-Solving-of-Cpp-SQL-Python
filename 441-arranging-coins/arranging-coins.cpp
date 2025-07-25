class Solution {
public:
    int arrangeCoins(int n) {
        long long k = 0; // Use long long to prevent overflow
        while (n >= k + 1) {
            k++;
            n -= k;
        }
        return k;
    }
};