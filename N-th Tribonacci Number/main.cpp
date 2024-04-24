class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;

        int x = 0;
        int y = 1;
        int z = 1;
        int w = x+y+z;
        
        for(int i =3;i<n;i++) {
            x = y;
            y = z;
            z = w;
            w = x+y+z;
        }
        return w;
    }
};