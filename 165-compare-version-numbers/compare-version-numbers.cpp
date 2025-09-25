class Solution {
public:
    int compareVersion(string version1, string version2) {

        int ptr1 = 0, ptr2 = 0;

        while(ptr1 != version1.length() || ptr2 != version2.length()) {

            auto p1 = getNumRevision(version1, ptr1);
            auto p2 = getNumRevision(version2, ptr2);

            ptr1 = p1.first;
            ptr2 = p2.first;

            if (p1.second > p2.second) {
                return 1;
            }
            if (p1.second < p2.second) {
                return -1;
            }
        }

        return 0;
    }

    pair<int, int> getNumRevision(string& version, int start) {
        if (start >= version.length()) return {version.length(),0};
        bool started = false;
        string val = "";
        int i = start;

        for(; i < version.length(); i++) {
            if (version[i] == '.') {
                i++;
                break;
            }

            if (!started && version[i] == '0') {
                continue;
            }
        
            started = true;
            val += (version[i]);
        }

        if (val == "") return {i,0};
        return {i,stoi(val)};
    }
};