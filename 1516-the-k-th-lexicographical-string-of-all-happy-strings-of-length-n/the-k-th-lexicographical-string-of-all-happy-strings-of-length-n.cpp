class Solution {
public:
    string getHappyString(int n, int k) {

        int total = 3 * (1 << (n-1));
        if (k > total) return "";

        k--; // make 0-indexed

        string res;

        // first character
        int block = 1 << (n-1);
        res += "abc"[k / block];
        k %= block;

        for (int i = 1; i < n; i++) {

            block >>= 1;

            string choices = "";
            for(char c : "abc")
                if(c != res.back())
                    choices += c;

            res += choices[k / block];
            k %= block;
        }

        return res;
    }
};