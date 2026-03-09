class Solution {
public:
    int maxOperations(string s) {
        int length = s.length();
        int numOnes = 0;
        int answer = 0;

        for (int i = 0; i < length - 1; i++) {
            if (s[i] == '1') {
                numOnes++;

                if (s[i + 1] != '1') {
                    answer += numOnes;
                }
            }
        }

        return answer;
    }
};