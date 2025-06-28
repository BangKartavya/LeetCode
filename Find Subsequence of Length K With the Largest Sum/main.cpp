bool cmp(const pair<int,int>& p1,const pair<int,int>& p2) {
    return p1.second < p2.second;
}

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> maxHeap;
        int n = nums.size();

        for(int i = 0;i<n;i++) maxHeap.push({nums[i],i});

        vector<pair<int,int>> result;

        while(k > 0) {
            result.push_back(maxHeap.top());
            maxHeap.pop();
            k--;
        }

        sort(begin(result),end(result),cmp);

        vector<int> answer;

        for(pair<int,int>& i: result) answer.push_back(i.first);

        return answer;
    }
};