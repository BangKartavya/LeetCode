
struct person {
    string name;
    int height;
};

bool cmp(person a,person b) {
    return a.height > b.height;
}

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<person> v;
        
        for(int i =0;i<names.size();i++) {
            v.push_back({names[i],heights[i]});    
        }
        
        sort(begin(v),end(v),cmp);
        
        vector<string> ans;
        
        for(auto i: v) {
            ans.push_back(i.name);
        }
        return ans;
    }
};