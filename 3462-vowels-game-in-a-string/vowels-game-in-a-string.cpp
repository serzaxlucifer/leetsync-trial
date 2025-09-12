class Solution {
public:
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    bool doesAliceWin(string s) {
        int numVowels = 0;
        int firstVowel = -1, lastVowel = -1;
        int j = 0;

        for (char a : s) {
            for (int i = 0; i < 5; i++) {
                if (vowels[i] == a) {
                    numVowels++;
                    if (firstVowel == -1) {
                        firstVowel = j;
                    }
                    lastVowel = j;
                }
            }
            j++;
        }

        // Now Alice makes a move optimally.

        if (numVowels < 1) return false;
        return true;
    }
};