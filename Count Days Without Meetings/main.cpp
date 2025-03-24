class Solution {
    private:
        void mergeOverlapping(vector<vector<int>>& meetings) {
            vector<vector<int>> result;

            int n = meetings.size();
            int i = 0;

            while(i < n) {
                vector<int> key = meetings[i];
                int j = i + 1;

                while(j < n && meetings[j][0] <= key[1]) {
                    key[1] = max(key[1], meetings[j][1]);
                    j++;
                }
                result.push_back(key);
                i = j;
            }

            meetings = result;
        }

    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(begin(meetings), end(meetings));
            mergeOverlapping(meetings);

            int daysFree = 0;
            int n = meetings.size();

            for(int i = 0; i < n; i++) {
                daysFree += (meetings[i][0] - (i > 0 ? meetings[i - 1][1] + 1 : 1));
            }

            daysFree += max(0, days - meetings[n - 1][1]);

            return daysFree;
        }
};