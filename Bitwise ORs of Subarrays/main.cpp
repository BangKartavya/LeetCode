class Solution {
    public:
        int subarrayBitwiseORs(vector<int>& arr) {
            unordered_set<int> result;
            unordered_set<int> curr;

            for(int& i : arr) {
                unordered_set<int> next;
                next.insert(i);

                for(const int& it : curr) {
                    next.insert(it | i);
                }
                result.insert(begin(next), end(next));
                curr = next;
            }

            return result.size();
        }
};