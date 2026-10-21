class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<char> isSub(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = words[i].size(), b = words[j].size();

                if (a < b) {
                    if (!isSub[i] &&
                        words[j].find(words[i]) != string::npos) {
                        isSub[i] = 1;
                    }
                } 
                else if (b < a) {
                    if (!isSub[j] &&
                        words[i].find(words[j]) != string::npos) {
                        isSub[j] = 1;
                    }
                }
            }
        }

        vector<string> ans;
        ans.reserve(n);

        for (int i = 0; i < n; i++) {
            if (isSub[i]) ans.push_back(words[i]);
        }

        return ans;
    }
};