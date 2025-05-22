class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int> available;
        priority_queue<int,vector<int>,greater<int>> used;
        const int n = nums.size();

        sort(begin(queries),end(queries));

        int count = 0;
        int j = 0;

        for(int i = 0;i<n;i++) {
            while(j < queries.size() && queries[j][0] == i) {
                available.push(queries[j][1]);
                j++;
            }

            if(used.empty()) {
                if(available.size() < nums[i]) return -1;
                
                while(!available.empty() && used.size() < nums[i]) {
                    if(available.top() >= i) {
                        used.push(available.top());
                        count++;
                    }
                    available.pop();
                }

                if(used.size() < nums[i]) return -1;

            }
            else {
                if(used.size() < nums[i]) {
                    if(used.size() + available.size() < nums[i]) return -1;

                    while(!available.empty() && used.size() < nums[i]) {
                        if(available.top() >= i) {
                            used.push(available.top());
                            count++;
                        }
                        available.pop();
                    }
                    if(used.size() < nums[i]) return -1;
                }
            }

            while(!used.empty() && used.top() <= i) {
                used.pop();
            }
/*
            cout << "i : " << i << endl;
            cout << "count : " << count << endl;
            cout << "avai : " << available.size() << endl;
            cout << "used : " << used.size() << endl;
            cout << endl;
*/
        }

        return queries.size() - count;
    }
};