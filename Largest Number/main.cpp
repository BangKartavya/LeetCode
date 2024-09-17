class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> n;

        for(auto i: nums) n.push_back(to_string(i));

        sort(begin(n),end(n),[](const string& a,const string& b) {
            return (b+a) < (a+b);
        });

        if(n[0] == "0") return "0";

        string target;

        for(auto i: n) target += i;

        return target;

    }
};