class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        sort(begin(potions),end(potions));
        
        vector<int> result(n);

        for(int i = 0;i<n;i++) {
            long long int sp = spells[i];

            int s = 0;
            int e = m-1;
            int ans = 0;

            while(s <= e) {
                int mid = s + (e-s)/2;

                if(sp*(long long)potions[mid] < success) {
                    s = mid+1;
                }
                else {
                    ans = m-mid;
                    e = mid - 1;
                }
            }
            result[i] = ans;
        }

        return result;
    }
};