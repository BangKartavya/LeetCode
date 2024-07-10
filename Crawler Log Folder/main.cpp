class Solution {
public:
    int minOperations(vector<string>& logs) {
        int step = 0;
        
        for(auto i : logs) {
            if(i == "../") {
                if(step > 0) step--;
            }
            else if(i != "./") step++;
        }
        return step;
    }
};