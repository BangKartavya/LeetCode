class Solution {
public:
    vector<int> resultsArray(vector<int>& arr, int k) {
        vector<int> ans;
        int n = arr.size();
        int i = 0;
        int j = k;
        
        while(j <= n) {
            bool sorted = true;
            
            for(int k = i;k<j-1;k++) {
                if(arr[k] > arr[k+1] || arr[k+1] != arr[k]+1) sorted = false;
            }
            
            if(sorted) ans.push_back(arr[j-1]);
            else ans.push_back(-1);
            
            i++;
            j++;
        }
        
        return ans;
    }
};