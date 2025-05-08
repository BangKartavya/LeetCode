05 / 08 / 2025using info = tuple<int, short, short, bool>; // (time, i, j, adjust)
const static int d[5] = {0, 1, 0, -1, 0};
class Solution {
    public:
        inline static bool isOutside(short i, short j, short n, short m) {
            return i < 0 || i >= n || j < 0 || j >= m;
        }

        static int minTimeToReach(vector<vector<int>>& moveTime) {
            short n = moveTime.size(), m = moveTime[0].size();
            vector<vector<int>> time(n, vector<int>(m, INT_MAX));
            priority_queue<info, vector<info>, greater<info>> pq;

            // Start at (0, 0) with time=0 adjust=1
            pq.emplace(0, 0, 0, 1);
            time[0][0] = 0;

            bool adjust = 0;
            while(!pq.empty()) {
                auto [t, i, j, adjust] = pq.top();
                pq.pop();
                //    cout<<" t="<<int(t)<<" i="<<int(i)<<" j="<<int(j)<<" adjust="<<adjust<<endl;
                // reach the destination
                if(i == n - 1 && j == m - 1)
                    return t;

                // Traverse all four directions
                for(int a = 0; a < 4; a++) {
                    int r = i + d[a], s = j + d[a + 1];
                    if(isOutside(r, s, n, m)) continue;

                    // minimum time to reach (r, s)
                    int nextTime = max(t, moveTime[r][s]) + 1 + (!adjust); // Wait if necessary

                    // update if this path having quicker time
                    if(nextTime < time[r][s]) {
                        time[r][s] = nextTime;
                        pq.emplace(nextTime, r, s, !adjust);
                    }
                }
            }

            return -1; // never reach
        }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();