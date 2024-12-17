    class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;
        for(auto i: s) mp[i]++;
        string ans;
        priority_queue<pair<char,int>> pq;

        for(auto it: mp) pq.push({it.first,it.second});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int cnt = it.second;
            char ch = it.first;
            int use = min(cnt,repeatLimit);
            ans.append(use,ch);
            cnt -= repeatLimit;
            if(cnt > 0) {
                if (!pq.empty()) {
                    auto sc = pq.top(); 
                    pq.pop();
                    char nextChar = sc.first;
                    int nextCnt = sc.second;
                    ans.push_back(nextChar);
                    nextCnt--;
                    if (nextCnt > 0) {
                        pq.push({nextChar, nextCnt});
                    }
                }
                else {
                    break;
                }
                pq.push({ch, cnt});
            } 
        }
        return ans;
    }
};