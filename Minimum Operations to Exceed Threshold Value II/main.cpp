class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;

        for(int& i : nums) pq.push(i);

        int operations = 0;

        while(!pq.empty()) {
            if(pq.top() >= k) return operations;
            long long int x = pq.top();
            pq.pop();
            long long int y = pq.top();
            pq.pop();
            operations++;
            long long elem = min(x,y) * 2 + max(x,y);
            pq.push(elem);
        }

        return operations;
    }
};