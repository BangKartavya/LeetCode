bool cmp(const vector<string>& a, const vector<string>& b) {
    if(stoi(a[1]) == stoi(b[1])) {
        if(a[0] == "OFFLINE") return true;
        if(b[0] == "OFFLINE") return false;
    }
    return stoi(a[1]) < stoi(b[1]);

    
}

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers;
        vector<int> result(n,0);

        sort(begin(events),end(events),cmp);
        
        unordered_map<int,int> offlineMap;

        for(vector<string>& event: events) {
            vector<int> comingOnline;
            for(auto& it: offlineMap) {
                if(stoi(event[1]) >= it.second + 60) comingOnline.push_back(it.first);
            } 

            for(int& it: comingOnline) {
                offlineMap.erase(it);
            }
            
            if(event[0] == "MESSAGE") {

                if(event[2] == "HERE") {
                    for(int i = 0;i<n;i++) {
                        if(offlineMap.find(i) == offlineMap.end()) result[i]++;
                    }
                }

                else if(event[2] == "ALL") {
                    for(int i = 0;i<n;i++) result[i]++;
                }
                else {
                    for(int i = 0;i<event[2].size();i++) {
                        if(isdigit(event[2][i])) {
                            int num = 0;
    
                            while(isdigit(event[2][i])) {
                                num *= 10;
                                num += (event[2][i] - 48);
                                i++;
                            }
                            result[num]++;
                        }
                    }
                }
            }

            if(event[0] == "OFFLINE") {
               offlineMap[stoi(event[2])] = stoi(event[1]); 
            }
        }
        
        
        return result;
    }
};