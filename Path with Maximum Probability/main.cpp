class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adj[n];
        int m = edges.size();
        for(int i = 0; i < m; i++){
            int u = edges[i][0], v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }
        
        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start}); // probability of reaching start node is 1
        
        vector<double> prob(n,0); // maintains the max probability of reaching any node
        prob[start] = 1; // probability of reaching start node
        
        while(!pq.empty()){
            auto top = pq.top();
            int node = top.second;
            double currProb = top.first;
            pq.pop();
            
            if(node == end) return currProb; /* as the priority queue is a max heap it will always give
			a maximum probability of reaching curr node the first time we encounter it */
            
            for(auto &i:adj[node]){
                int adjNode = i.first;
                double p = i.second;
                if(prob[adjNode] < p*currProb){
                    prob[adjNode] = p*currProb;
                    pq.push({p*currProb, adjNode});
                }
            }
        }
        
        return 0; // if end node is unreachable then probability of reaching it is zero
    }
};