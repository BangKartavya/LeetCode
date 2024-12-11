class Solution {
    public:
        long long pickGifts(vector<int>& gifts, int k) {
            long long ans = 0;

            priority_queue<int, vector<int>> pq;

            for(auto i : gifts) {
                ans += i;
                pq.push(i);
            }

            while(k) {
                int t = pq.top();
                ans -= (t - sqrt(t));
                pq.pop();
                pq.push(sqrt(t));
                k--;
            }
            return ans;
        }
};