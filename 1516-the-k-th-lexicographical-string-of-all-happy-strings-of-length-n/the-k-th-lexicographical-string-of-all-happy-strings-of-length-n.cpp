class Solution {
public:
    string getHappyString(int n, int k) {
        int numStrings = getTotalCombos(n);
        if (numStrings < k) {
            return "";
        }

        string answer = "";
        int perLetter = numStrings / 3;

        if (k <= perLetter) {
            answer += 'a';
        } else if (k <= perLetter*2) {
            answer += 'b';
        } else {
            answer += 'c';
        }
        k--;


        answer += getChar(answer[0], n - 1, k % perLetter);
        // now deal with n - 1 letters.

        return answer;
    }

    string getChar(char prevLetter, int bound, int partition) { // 2 // 0
        if (bound == 0) {
            return "";
        }

        string res = "";

        int possibilities = pow(2, bound); // 4
        if (partition < possibilities / 2) {
            res += getAppropriateChar(prevLetter, true);
        } else {
            res += getAppropriateChar(prevLetter, false);
        }

        res += getChar(res[0], bound - 1, partition % (possibilities / 2));

        return res;

    }

    int getTotalCombos(int n) {
        if (n == 1) {
            return 3;
        } 
        return 3 * pow(2, n - 1); 
    }

    char getAppropriateChar(char currentChar, bool mode) {
        if (currentChar == 'a') {
            return mode ? 'b' : 'c';
        } else if (currentChar == 'b') {
            return mode ? 'a' : 'c';
        } else {
            return mode ? 'a' : 'b';
        }

    }
};