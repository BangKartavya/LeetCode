class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();

        int result = 0;

        queue<int> q;
        unordered_set<int> foundKeys;
        unordered_set<int> foundBoxes;

        for(int& box : initialBoxes) {
            foundBoxes.insert(box);
            q.push(box);
            if(status[box] == 1) {
                result += candies[box];
                status[box] = -1;
            }
            for(int& key: keys[box]) foundKeys.insert(key);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int& box: containedBoxes[node]) {
                foundBoxes.insert(box);
                if((foundKeys.find(box) != foundKeys.end() && status[box] != -1) || status[box] == 1) {
                    q.push(box);
                    result += candies[box];
                    status[box] = -1;
                    for(int& key: keys[box]) foundKeys.insert(key);
                }
            }
        }

        for(const int& box : foundBoxes) {
            if(status[box] == 1) {
                result += candies[box];
                status[box] = -1;
            }
            else if(status[box] == 0) {
                if(foundKeys.find(box) != foundKeys.end()) {
                    result += candies[box];
                    status[box] = -1;
                }
            }
        }

        return result;

    }
};