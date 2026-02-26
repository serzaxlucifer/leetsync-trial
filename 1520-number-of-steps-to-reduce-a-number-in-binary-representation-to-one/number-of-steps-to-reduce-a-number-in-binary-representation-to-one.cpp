class Solution {
public:
    int numSteps(string s) {
        int answer = 0;
        int carry = 0;

        for(int i = s.length() - 1; i >= 0; i--) {
            int val = s[i] == '0' ? 0 : 1;
            int trueVal = val + carry;

            if (trueVal == 0) {
                answer++;
            } else if (trueVal == 1) {
                if (i != 0) {
                    carry = 1;
                    answer += 2;
                }
            } else {
                carry = 1;
                answer++;
            }
        }

        return answer;
        
    }
};