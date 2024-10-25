class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string, int> mp;
        vector<string> res;

        sort(folder.begin(), folder.end());

        for (auto& c : folder) {
            string word = "";
            bool isSubfolder = false;

            for (int i = 1; i < c.size(); ++i) {
                if (c[i] == '/') {
                    word = c.substr(0, i);
                    if (mp.count(word)) {
                        isSubfolder = true;
                        break;
                    }
                }
            }

            if (!isSubfolder) {
                res.push_back(c);
                mp[c] = 1;
            }
        }
        return res;
    }
};
