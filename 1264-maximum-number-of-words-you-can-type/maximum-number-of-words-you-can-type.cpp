class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int answer = 0;
        bool broken[26] = {0};

        for (char brokenKey : brokenLetters) {
            broken[brokenKey - 'a'] = true;
        }

        bool canType = true;

        for (char a : text) {
            if (a == ' ') {
                if (canType) answer++;
                canType = true;
            } else {
                if (broken[a - 'a']) {
                    canType = false;
                }
            }
        }

        if (canType) answer++;

        return answer;
    }
};