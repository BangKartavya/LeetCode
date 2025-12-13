class Solution {
    public:
        vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
            int n = code.size();

            vector<pair<string, string>> temp;

            for(int i = 0; i < n; i++) {
                string c = code[i];
                string b = businessLine[i];
                bool a = isActive[i];

                if(!a) continue;

                if(b == "electronics" || b == "grocery" || b == "pharmacy" || b == "restaurant") {
                    bool isValid = !c.empty();

                    for(char& ch : c) {
                        if(!isalnum(ch) && ch != '_') {
                            isValid = false;
                            break;
                        }
                    }

                    if(isValid) temp.push_back({b, c});
                }
            }

            vector<string> res;

            sort(begin(temp), end(temp));

            for(pair<string, string>& p : temp)
                res.push_back(p.second);

            return res;
        }
};