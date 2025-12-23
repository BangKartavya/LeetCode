#include <vector>
#include <algorithm>

class Solution {
public:
    int maxTwoEvents(std::vector<std::vector<int>>& events) {
        std::sort(begin(events),end(events));
        int n = events.size();
        std::vector<int> suf(n);
        suf[n-1] = events[n-1][2];

        for(int i = n-2;i>=0;i--) {
            suf[i] = std::max(events[i][2],suf[i+1]);
        }

        int maxi = 0;

        for(int i = 0;i<n;i++) {
            int s = i+1;
            int e = n-1;
            int next = -1;

            while(s <= e) {
                int mid = s + (e-s)/2;
                if(events[mid][0] > events[i][1]) {
                    next = mid;
                    e = mid-1;
                }
                else s = mid+1;
            }

            if(next != -1) maxi = std::max(maxi,events[i][2]+suf[next]);

            maxi = std::max(maxi,events[i][2]);
        }

        return maxi;
    }
};
