class Solution {
public:
    int calc(string row) {
        int total = 0;
        for(auto s: row) total+= s-'0';
        return total;
    }
    int numberOfBeams(vector<string>& bank) {
        int total = 0;
        int prevRow = 0;
        
        for(auto row:bank) {
            int currRow = calc(row);
            
            if(currRow==0) continue;
            
            total+= prevRow*currRow;
            prevRow = currRow;
        }
        return total;
    }
};