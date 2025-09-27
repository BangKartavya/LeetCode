class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxi = 0;
        int n = points.size();

        for(int i = 0;i<n;i++) {
            for(int j = i+1;j<n;j++) {
                for(int k = j+1;k<n;k++) {
                    int ax = points[i][0];
                    int ay = points[i][1];

                    int bx = points[j][0];
                    int by = points[j][1];
                    
                    int cx = points[k][0];
                    int cy = points[k][1];

                    double a = sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay));
                    double b = sqrt((cx-bx)*(cx-bx) + (cy-by)*(cy-by));
                    double c = sqrt((ax-cx)*(ax-cx) + (ay-cy)*(ay-cy));

                    if(a + b > c && b + c > a && c + a > b) {
                        double s = (a + b + c) / 2;
                        double area = sqrt(s * (s-a) * (s-b) * (s-c));
                        maxi = max(maxi, area);
                    }
                }
            }
        }

        return maxi;
    }
};