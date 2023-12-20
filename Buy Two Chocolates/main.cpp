class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = 150;
        int min2 = 150;
        
        for(auto i:prices) {
            if(i<min1) {
                min2 = min1;
                min1=i;
            }
            else if(i<min2) {
                min2 = i;
            }
        }
        
        if(min1+min2<=money) return money-(min1+min2);
        return money;
    }
};