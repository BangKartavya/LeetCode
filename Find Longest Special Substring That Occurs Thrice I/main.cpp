class Solution {
private:
    string str;
    int n;

    bool isPossible(int max_len) {
        for(int i  = 0;i<n;i++) {
            for(int j = 1;j<=n;j++) {
                string sub = str.substr(i,j);
                if(count(begin(sub),end(sub),sub[0]) != sub.size()) break;
                int res = -1;
                int cnt = 0;

                while((res = str.find(sub,res+1)) != string::npos) {
                    cnt++;
                }
                if(cnt >= 3 && sub.size() >= max_len) return true;
            }
        }
        return false;
    }

public:
    int maximumLength(string str) {
        int s = 0;
        this->str = str;
        n = str.size();
        int e = n;
        int ans = -1;

        while(s <= e) {
            int mid = s + (e-s)/2;

            if(isPossible(mid)) {
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }

        return ans;

    }
};