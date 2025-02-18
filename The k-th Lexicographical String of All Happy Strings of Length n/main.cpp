class Solution {
private:
    vector<string> vp;
    int n;

    void solve(char prev,string s) {
        if(s.size() == n) {
            vp.push_back(s);
            return;
        }

        if(prev == 'a') {
            solve('b',s + "b");
            solve('c',s + "c");
        }

        else if(prev == 'b') {
            solve('a',s + "a");
            solve('c',s + "c");
        }

        else if(prev == 'c') {
            solve('a',s + "a");
            solve('b',s + "b");
        }
        else {
            solve('a',s + "a");
            solve('b',s + "b");
            solve('c',s + "c");
        }
    }

public:
    string getHappyString(int n, int k) {
        this->n = n;

        solve('0',"");

        sort(begin(vp),end(vp));

        return k <= vp.size() ? vp[k-1] : "";
    }
};