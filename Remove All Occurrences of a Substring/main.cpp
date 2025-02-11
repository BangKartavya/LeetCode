class Solution {
    public:
        string removeOccurrences(string s, string part) {
            string prev;
            string curr = s;

            while(true) {
                if(curr == prev || curr.empty()) break;
                for(int i = 0; i < curr.size(); i++) {
                    if(curr.substr(i, part.size()) == part) {
                        curr = curr.substr(0, i) + curr.substr(i + part.size(), curr.size() - i - part.size());
                        cout << "curr : " << curr << endl;
                        break;
                    }
                    prev = curr;
                }
            }

            return curr;
        }
};