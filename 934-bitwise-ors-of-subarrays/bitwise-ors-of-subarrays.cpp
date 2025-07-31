class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) 
    {
        unordered_set<int> distinctORS;
        unordered_set<int> runningORS;

        for(int i : arr) {
            unordered_set<int> newOrs;
            for (int j : runningORS) {
                newOrs.insert(i | j);
            }
            newOrs.insert(i);
            runningORS = newOrs;
            distinctORS.insert(runningORS.begin(), runningORS.end());
        }

        return distinctORS.size();

    }
};