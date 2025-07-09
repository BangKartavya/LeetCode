class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;

        if(startTime[0] > 0) freeTime.push_back(startTime[0]);

        int n = startTime.size();

        for(int i = 1;i<n;i++) {
            freeTime.push_back(startTime[i]-endTime[i-1]);
        }

        if(endTime[n-1] < eventTime) freeTime.push_back(eventTime-endTime[n-1]);

        int currFreeTime = 0;

        for(int i = 0;i<=k && i < freeTime.size();i++) {
            currFreeTime += freeTime[i];
        }

        int maxi = currFreeTime;

        for(int i = k+1;i<freeTime.size();i++) {
            currFreeTime -= freeTime[i-(k+1)];
            currFreeTime += freeTime[i];
            maxi = max(maxi,currFreeTime);
        }

        return maxi;
    }
};