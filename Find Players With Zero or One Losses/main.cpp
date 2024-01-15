class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> loose;
        set<int> play;
        
        for(auto i: matches) {
            loose[i[1]]++;
            play.insert(i[0]);
            play.insert(i[1]);
        }
        
        vector<vector<int>> ans;
        
        vector<int> notLost;
        vector<int> oneLoss;
        
        for(auto i: play) {
            if(loose.find(i)== loose.end()) notLost.push_back(i);
            else {
                if(loose[i] == 1) oneLoss.push_back(i);
            }
        }
        ans.push_back(notLost);
        ans.push_back(oneLoss);
        
        return ans;
    }
};