#include <climits>
#include <string>
#include <vector>

class Solution {
public:
    int bestClosingTime(std::string customers) {
        int n = size(customers);

        std::vector<int> pref(n);
        std::vector<int> suf(n+1);

        for(int i = 0;i<n;i++) {
            pref[i] = (i > 0 ? pref[i-1] : 0) + (customers[i] == 'N');
        }

        for(int i = n-1;i>=0;i--) {
            suf[i] = suf[i+1] + (customers[i] == 'Y');
        }

        int mini = INT_MAX;
        int res = -1;

        for(int i =0;i<=n;i++) {
            if(((i > 0 ? pref[i-1] : 0) + suf[i]) < mini) {
                mini = (i > 0 ? pref[i-1] : 0) + suf[i];
                res = i;
            }
        }

        return res;
    }
};
