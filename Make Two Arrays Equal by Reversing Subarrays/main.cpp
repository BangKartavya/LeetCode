class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> v(1001,0);
        int n = target.size();

        for(int i =0;i<n;i++) {
            v[target[i]]++;
            v[arr[i]]--;
        }

        for(auto i: v) if(i != 0) return false;

        return true;
    }
};