bool cmp(const vector<int>& a, const vector<int>& b) {
    return (a[0] == b[0]) ? a[1] < b[1] : a[0] > b[0];
}

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(begin(points),end(points),cmp);

        int n = points.size();
        int ans = 0;

        for(int i = 0;i<n-1;i++) {
            int y = INT_MAX;

            for(int j = i+1;j<n;j++) {
                if(points[j][1] >= points[i][1] && y > points[j][1]) {
                    ans++;
                    y = points[j][1];
                }
            }
        }

        return ans;
    }
};