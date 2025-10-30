class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int result = target[0];
        int n = target.size();

        for(int i = 1;i<n;i++) result += max(0,target[i]-target[i-1]);

        return result;
    }
};