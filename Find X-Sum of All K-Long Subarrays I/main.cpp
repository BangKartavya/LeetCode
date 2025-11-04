class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int,int> mp;
        int i = 0;
        int j = 0;
        int n = nums.size();

        vector<int> result(n-k+1);

        for(;j<k-1;j++) mp[nums[j]]++;

        while(j < n) {
            mp[nums[j]]++;
            priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

            // push map
            for(auto& it: mp) {
                if(pq.size() < x)
                    pq.push({it.second,it.first});
                else {
                    if(pq.top().first < it.second) {
                        pq.pop();
                        pq.push({it.second,it.first});
                    }
                    else if(pq.top().first == it.second && abs(pq.top().second) < it.first) {
                        pq.pop();
                        pq.push({it.second,it.first});
                    }
                }
            }

            while(!pq.empty()) {
                result[i] += pq.top().first * (pq.top().second);
                pq.pop();
            }

            // finally inc i and j

            mp[nums[i]]--;
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
            i++;
            j++;
        }

        return result;
    }
};