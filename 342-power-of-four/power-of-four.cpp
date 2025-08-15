class Solution {
public:
    bool isPowerOfFour(int n) {
        long m = n;
        return (m & (m - 1)) == 0 && m % 3 == 1;
    }
};