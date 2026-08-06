class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; ; ++i) {
            int digit_product = 1;
            int current = i;
            while (current > 0) {
                digit_product *= (current % 10);
                current /= 10;
            }
            if (digit_product % t == 0) {
                return i;
            }
        }
    }
};