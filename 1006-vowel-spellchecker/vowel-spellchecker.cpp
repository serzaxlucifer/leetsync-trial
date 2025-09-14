class Solution {
public:
    string normalize(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] - 'a' < 0 && s[i] != '?') {
                s[i] = s[i] - 'A' + 'a';
            }
        }
        return s;
    }

    string normalizeVowel(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                s[i] = '?';
            }
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) 
    {
        unordered_map<string, int> index;
        unordered_map<string, int> indexCapitalized;
        unordered_map<string, int> vowel;
        vector<string> answer; // aiF --> ??F
        bool enableDebug = false;

        for (int i = 0; i < wordlist.size(); i++) {
            if (index.find(normalize(wordlist[i])) == index.end()) {
                index[normalize(wordlist[i])] = i;
            }
            indexCapitalized[wordlist[i]] = i;
            if (vowel.find(normalize(normalizeVowel(wordlist[i]))) == vowel.end()) {
                vowel[normalize(normalizeVowel(wordlist[i]))] = i;
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            if (indexCapitalized.find(queries[i]) != indexCapitalized.end()) {
                answer.push_back(queries[i]);
            }
            else if (index.find(normalize(queries[i])) != index.end()) {
                answer.push_back(wordlist[index[normalize(queries[i])]]);
            }
            else if (vowel.find(normalize(normalizeVowel(queries[i]))) != vowel.end()) {
                answer.push_back(wordlist[vowel[normalize(normalizeVowel(queries[i]))]]);
            }
            else {
                answer.push_back("");
            }
        }
        return answer;
    }
};