class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int available_at = 0;
        double total_wait = 0;
        
        for(auto i: customers) {
            int arrival = i[0];
            int time = i[1];
            
            available_at = max(available_at,arrival)+time;
            total_wait += available_at-arrival;
        }
        return total_wait/customers.size();
    }
};