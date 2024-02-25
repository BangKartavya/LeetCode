class Solution {
public:
    int n;
    vector<int> prime;
    vector<vector<int>> commonFactor;
    vector<int> num_state;

    vector<bool> isPrime;

    void sieve(int n) {
        isPrime.assign(n+1,1);
        isPrime[0] = 0;
        isPrime[1] = 0;

        for(int i = 2;i*i<=n;i++) {
            if(isPrime[i]) {
                for(int j = i*i;j<=n;j+=i) isPrime[j] = 0;
            }
        }
        prime.reserve((int)log(n));
        for(int i =2;i<=n;i++) if(isPrime[i]) prime.push_back(i);
    }
    void build_commonFactor_path(auto& nums, int M) {
        num_state.assign(M+1, 0);
        commonFactor.resize(M+1, vector<int>());

        for (int x : nums)
            num_state[x] = 1;

        for (int p : prime) {
            if (num_state[p] != 1)
                num_state[p] = -1;

            for (int i = p*2; i <= M; i += p) {
                if (num_state[i] == 1) {
                    commonFactor[i].push_back(p);
                    commonFactor[p].push_back(i);
                }
            }
        }
    }

    void dfs(int i, int& sz) {
        if (num_state[i]==1 && i!=1)
            sz++;
        num_state[i] = 2;

        for (int x : commonFactor[i]) {
            if (num_state[x] == 1 || num_state[x] == -1) {
                dfs(x, sz);
            }
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size()==1) return 1;
        unordered_set<int> numSet(nums.begin(), nums.end());
        if (numSet.count(1)) return 0;
        int n=numSet.size();
        int M=*max_element(numSet.begin(), numSet.end());
        sieve(M);
        build_commonFactor_path(numSet, M);
        for (int i : numSet) {
            if (num_state[i] == 1) {
                int sz=0;
                dfs(i, sz);
                if (sz==n) return 1;
            }
        }
        return 0;
    }
};