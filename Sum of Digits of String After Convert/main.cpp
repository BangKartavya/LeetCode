class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";

        for(auto i: s) num += to_string(i-'a' + 1);

        while(k--) {
            int temp = 0;
            for(auto i: num) temp += (i-'0');
            num = to_string(temp);
        }
        return stoi(num);
    }
};