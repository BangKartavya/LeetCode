#include <numeric>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumBoxes(std::vector<int>& apple, std::vector<int>& capacity) {
        int m = capacity.size();

        std::sort(rbegin(capacity),rend(capacity));

        int totalApples = std::accumulate(begin(apple),end(apple),0);

        int i =0;
        int totalCap = 0;

        for(;i<m;i++) {
            totalCap += capacity[i];
            if(totalCap >= totalApples) break;
        }

        return i+1;

    }
};
