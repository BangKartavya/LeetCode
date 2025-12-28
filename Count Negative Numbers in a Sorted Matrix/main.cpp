#include <algorithm>
#include <iterator>
#include <vector>

class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int m = size(grid);
        int n = size(grid[0]);

        int res = 0;

        for(int i = 0;i<m;i++) {
            int numLessThan0 = (std::lower_bound(std::rbegin(grid[i]), std::rend(grid[i]),0) - std::rbegin(grid[i]));

            res += numLessThan0;
        }

        return res;
    }
};
