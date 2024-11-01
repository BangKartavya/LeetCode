class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> v;

        string temp = "";
        
        for(auto i: sentence) {
            if(i == ' ') {
                v.push_back(temp);
                temp = "";
            }
            else temp+=i;
        }
        v.push_back(temp);

        int n = v.size();
        
        for(int i = 0;i<n;i++) {
            
            if(i == n-1) {
                if(v[i][v[i].size()-1] != v[0][0]) return false;

                else return true;
            }
            if(v[i][v[i].size()-1] != v[i+1][0]) return false;
        }

        return true;
    }
};