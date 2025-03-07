void p(vector<bool>& primes) {
    primes[0] = primes[1] = false;
    for(int i = 2;i*i<primes.size();i++) {
        if(primes[i]) {
            for(long long int j = (long long)i*(long long)i;j<primes.size();j+=i) {
                primes[j] = false;
            }
        }
    }
}



class Solution {
private:
    vector<bool>primes;
public:

    Solution() {
        primes.resize(1e6+5,true);
        p(primes);
    }

    vector<int> closestPrimes(int left, int right) {
        int mini = INT_MAX;
        vector<int> result = {-1,-1};
        vector<int> prime;

        for(int i = left;i<=right;i++) if(primes[i]) prime.push_back(i);

        for (int i = 1; i < prime.size(); i++) {
            int gap = prime[i] - prime[i - 1];
            if (gap < mini) {
                mini = gap;
                result = {prime[i - 1], prime[i]};
            }
        }

        return result;

    }
};