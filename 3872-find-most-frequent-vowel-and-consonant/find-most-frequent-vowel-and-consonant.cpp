class Solution {
public:
    const char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    int maxFreqSum(string s) {
        int frequency[26] = {0};
        for (char a : s) {
            frequency[a - 'a']++;
        }
        int c = 0, v = 0;
        bool vowelFound = false;

        for(int i = 0; i < 26; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == vowels[j] - 'a') {
                    v = max(v, frequency[i]);
                    vowelFound = true;
                    continue;
                }
            }
            if (!vowelFound) {
                c = max(c, frequency[i]);
            }
            vowelFound = false;
        }

        return v+c;
    }
};