class Solution {
public:
    int longestBalanced(string s) {
        int answer = 0;

        for(int i = 0; i < s.length(); i++) {
            int frequency[26] = {0};
            for(int j = i; j < s.length(); j++) {
                frequency[s[j] - 'a']++;
                if (isBalanced(frequency, 26)) {
                    answer = max(answer, j - i + 1);
                }
            }
        }

        return answer;
    }

    bool isBalanced(int frequency[], int size) {
        int val = 0;
        for (int i = 0; i < size; i++) {
            if (frequency[i] != 0) {
                if (val == 0) {
                    val = frequency[i];
                } else if (val != frequency[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};