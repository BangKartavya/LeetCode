class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int losses[n];
        memset(losses,0,sizeof(losses));
        
        for(auto i: edges) losses[i[1]]++;
        
        int champ = -1;
        
        for(int i = 0;i<n;i++) {
            if(losses[i] == 0) {
                if(champ != -1) return -1;
                
                champ = i;
            }
        }
        
        return champ;
    }
};