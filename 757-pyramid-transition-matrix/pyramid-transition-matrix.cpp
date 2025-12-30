class Solution {
public:
    vector<vector<vector<char>>> table;   // 7x7 since chars are A-F (as per constraints)
    unordered_set<string> bad;            // memo for impossible bottom states

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        table.assign(7, vector<vector<char>>(7));   // reset table

        // build fast lookup table
        for (string &s : allowed) {
            int a = s[0]-'A', b = s[1]-'A';
            table[a][b].push_back(s[2]);
        }

        return dfs(bottom);
    }

    bool dfs(string &bottom) {
        if (bottom.size() == 1) 
            return true;

        if (bad.count(bottom))     // already tried & failed
            return false;

        string next(bottom.size()-1, ' ');   // reserve once (no reallocation)

        if (buildNext(0, bottom, next)) 
            return true;

        bad.insert(bottom);
        return false;
    }

    bool buildNext(int idx, string &bottom, string &next) {
        // built one complete upper layer
        if (idx == next.size())
            return dfs(next);

        int a = bottom[idx]-'A';
        int b = bottom[idx+1]-'A';

        // no valid blocks → prune instantly
        if (table[a][b].empty())
            return false;

        for (char c : table[a][b]) {
            next[idx] = c;                   // place char in next row
            if (buildNext(idx+1, bottom, next))
                return true;
        }
        return false;
    }
};
