class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);
        queue<pair<int,int>> q;
        q.push({node1,0});

        while(!q.empty()) {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            if(d < dist1[node]) dist1[node] = d;

            if(edges[node] != -1 && (d + 1) < dist1[edges[node]]) {
                q.push({edges[node],d+1});
            }
        }
        q.push({node2,0});
        while(!q.empty()) {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();

            if(d < dist2[node]) dist2[node] = d;

            if(edges[node] != -1 && (d + 1) < dist2[edges[node]]) {
                q.push({edges[node],d+1});
            }
        }
        int result = INT_MAX;
        int idx = -1;

        for(int i = 0;i<n;i++) {
            if(result > max(dist1[i],dist2[i])) {
                idx = i;
                result = max(dist1[i],dist2[i]);
            }
        }

        return idx;
    }
};