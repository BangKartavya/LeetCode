struct cmp
{
   bool operator()( const pair<int,int>& a, const pair<int,int>& b ) const {
    if(a.first > b.first) return true;
    else if (a.first == b.first) return a.second > b.second;

    return false;
   }
};

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        int n = nums.size();

        for(int i = 0;i<n;i++) pq.push({nums[i],i});

        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> temp = pq;

        while(!temp.empty()) {
            cout << temp.top().first << " ";
            temp.pop();
        }
        cout << endl;

        while(k) {
            pair<int,int> mini = pq.top();
            pq.pop();
            nums[mini.second] = mini.first*multiplier;
            pq.push({mini.first*multiplier,mini.second});
            k--;
        }

        return nums;
    }
};