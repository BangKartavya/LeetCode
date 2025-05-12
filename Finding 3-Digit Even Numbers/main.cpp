class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        unordered_set<int> s;
        int n = digits.size();

        for(int i = 0;i<n;i++) {
            if(digits[i] == 0) continue;
            for(int j = 0;j<n;j++) {
                if(i == j) continue;

                for(int k = 0;k<n;k++) {
                    if(i == k || k == j) continue;

                    else {
                        if(digits[k]%2 == 0) {
                            int num = 100*digits[i] + 10 * digits[j] + digits[k];
                            if(s.find(num) == s.end()) {
                                result.push_back(num);
                                s.insert(num);
                            }
                        }
                    }
                }
            }
        }
        sort(begin(result),end(result));
        return result;
    }
};