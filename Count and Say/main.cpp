class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string cns = countAndSay(n-1);
        vector<pair<char,int>> vps;

        for(int i = 0;i<cns.size();i++) {
            if(vps.empty()) {
                vps.push_back({cns[i],1});
            }
            else {
                if(vps.back().first == cns[i]) {
                    vps.back().second++;
                }
                else {
                    vps.push_back({cns[i],1});
                }
            }
        }


        string res;

        for(pair<char,int> p: vps) {
            res += to_string(p.second)+p.first;
        }

        return res;

    }
};