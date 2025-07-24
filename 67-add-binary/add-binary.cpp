class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry == 1) {
            int sum_digits = carry;

            if (i >= 0) {
                sum_digits += a[i] - '0'; // Convert char to int
                i--;
            }
            if (j >= 0) {
                sum_digits += b[j] - '0'; // Convert char to int
                j--;
            }

            result.push_back((sum_digits % 2) + '0'); // Convert int to char and append
            carry = sum_digits / 2;
        }

        std::reverse(result.begin(), result.end()); // Reverse the result string

        return result;
    }
};