class Solution {
    private:
        const int MOD = 1e9 + 7;

    public:
        int numOfSubarrays(vector<int>& arr) {
            int n = arr.size();

            int curSum = 0;
            int result = 0;
            int evenCount = 0;
            int oddCount = 0;

            for(int i = 0; i < n; i++) {
                curSum += arr[i];
                if(curSum % 2 == 0) {
                    evenCount++;
                    result = (oddCount + result) % MOD;
                } else {
                    result = (evenCount + 1 + result) % MOD;
                    oddCount++;
                }
            }

            return result;
        }
};