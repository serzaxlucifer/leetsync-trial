class Solution {
public:
    unordered_set<string> bad; // memo for failed states

    bool pyramidTransition(string bottom, vector<string>& allowed) 
    {
        unordered_map<string, vector<char>> transitionMap;

        for (string s : allowed) {
            string key = s.substr(0, 2);
            char top = s[2];
            transitionMap[key].push_back(top);
        }

        return plough(bottom, transitionMap);

    }

    bool plough(string bottomLayer, unordered_map<string, vector<char>>& transitionMap) {
        if (bottomLayer.length() == 1) 
            return true;

        if (bad.count(bottomLayer)) // seen before & failed
            return false;

        vector<string> possibleTops = generatePossibleTopLayers(bottomLayer, transitionMap);

        if (possibleTops.empty()) {
            bad.insert(bottomLayer);
            return false;
        }

        for (int i = 0; i < possibleTops.size(); i++) {
            if (plough(possibleTops[i], transitionMap))
                return true;
        }

        bad.insert(bottomLayer);
        return false;
    }

    vector<string> generatePossibleTopLayers(string bottomLayer, unordered_map<string, vector<char>>& transitionMap) {

        vector<string> possibleTops{""};  // initially one empty string

        for (int i = 0; i < bottomLayer.size() - 1; i++) {

            string key = bottomLayer.substr(i, 2);  
            if (!transitionMap.count(key))
                return {};   // no transition possible

            vector<string> intermediate;
            vector<char>& candidates = transitionMap[key];

            for (char c : candidates) {
                for (string s : possibleTops) {
                    intermediate.push_back(s + c);
                }
            }

            possibleTops = intermediate;
        }
        return possibleTops;
    }
};