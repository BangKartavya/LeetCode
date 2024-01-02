class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> um;
        
        for(auto i:nums) um[i]++;
        
        vector<vector<int>> ans;
        
        while(!um.empty()) {
            vector<int> temp;
            vector<int> toErase;
            
            for(auto& [f,s]:um) {
                temp.emplace_back(f);
                s--;
                if(s==0) toErase.emplace_back(f);
            }
            ans.push_back(temp);
            for(auto i: toErase) um.erase(i);
        }
        return ans;
    }
};