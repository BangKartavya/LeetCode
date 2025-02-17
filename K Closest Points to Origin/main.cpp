//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Point {
        int x;
        int y;
        int dist;
};

bool cmp(const Point& a, const Point& b) {
    return a.dist <= b.dist;
}

class Solution {
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            vector<Point> vp;

            for(vector<int>& i : points) {
                vp.push_back({i[0], i[1], i[0] * i[0] + i[1] * i[1]});
            }

            sort(begin(vp), end(vp), cmp);

            vector<vector<int>> res;

            for(int i = 0; i < k; i++) {
                res.push_back({vp[i].x, vp[i].y});
            }

            return res;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for(int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for(const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends