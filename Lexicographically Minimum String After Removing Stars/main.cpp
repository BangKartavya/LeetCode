7/20class cmp {
    public:
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
            if(a.first > b.first) return true;
            else if(a.first < b.first) return false;
            else {
                if(a.second > b.second) return false;
            }

            return true;
        }
};

class Solution {
    public:
        string clearStars(string s) {
            priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;

            for(int i = 0; i < s.size(); i++) {
                char ch = s[i];
                if(ch != '*') pq.push({ch, i});
                else pq.pop();
            }

            map<int, char> mp;

            while(!pq.empty()) {
                mp[pq.top().second] = pq.top().first;
                pq.pop();
            }

            string result;

            for(auto it = mp.begin(); it != mp.end(); it++) {
                result += it->second;
            }

            return result;
        }
};