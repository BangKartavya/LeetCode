#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool judgePoint24(vector<int>& cards) {
            vector<double> a(cards.begin(), cards.end());
            return dfs(a);
        }

    private:
        static constexpr double EPS = 1e-6;

        bool dfs(vector<double>& a) {
            int n = (int)a.size();
            if(n == 1) return fabs(a[0] - 24.0) < EPS;

            for(int i = 0; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    double x = a[i], y = a[j];

                    vector<double> rest;
                    rest.reserve(n - 1);
                    for(int k = 0; k < n; ++k)
                        if(k != i && k != j) rest.push_back(a[k]);
                    rest.push_back(x + y);
                    if(dfs(rest)) return true;

                    rest.back() = x * y;
                    if(dfs(rest)) return true;

                    rest.back() = x - y;
                    if(dfs(rest)) return true;

                    rest.back() = y - x;
                    if(dfs(rest)) return true;

                    if(fabs(y) > EPS) {
                        rest.back() = x / y;
                        if(dfs(rest)) return true;
                    }
                    if(fabs(x) > EPS) {
                        rest.back() = y / x;
                        if(dfs(rest)) return true;
                    }
                }
            }
            return false;
        }
};