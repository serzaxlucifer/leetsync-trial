class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        sort(arr2.begin(), arr2.end());
        int answer = 0;

        for (int i = 0; i < arr1.size(); i++) {
            int remnant1 = arr1[i] - d;     // larger than this
            int remnant2 = arr1[i] + d;     // smaller than this

            auto lb1 = lower_bound(arr2.begin(), arr2.end(), remnant1);

            if (lb1 != arr2.end() && *lb1 <= remnant2)
            {
                continue;
            }
            answer++;
        }

        return answer;
    }
};