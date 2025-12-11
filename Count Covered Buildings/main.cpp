class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,pair<int,int>> xMap; // {x, {y_min, y_max}}
        unordered_map<int,pair<int,int>> yMap; // {y, {x_min, x_max}}

        for(vector<int>& b: buildings) {
            if(xMap.find(b[0]) == xMap.end()) {
                xMap[b[0]] = {b[1],b[1]};
            }
            else {
                xMap[b[0]].first = min(xMap[b[0]].first,b[1]);
                xMap[b[0]].second = max(xMap[b[0]].second,b[1]);
            }
        }

        for(vector<int>& b: buildings) {
            if(yMap.find(b[1]) == yMap.end()) {
                yMap[b[1]] = {b[0],b[0]};
            }
            else {
                yMap[b[1]].first = min(yMap[b[1]].first,b[0]);
                yMap[b[1]].second = max(yMap[b[1]].second,b[0]);
            }
        }
        
        int ans = 0;

        for(vector<int>& b: buildings) {
            int x = b[0];
            int y = b[1];

            if(xMap[x].first < y && xMap[x].second > y) {
                if(yMap[y].first < x && yMap[y].second > x) ans++;
            }
        }

        return ans;

    }
};