class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        int unplaced = 0;

        for(int& fruit: fruits) {
            bool placed = false;
            for(int& basket: baskets) {
                if(fruit <= basket) {
                    placed = true;
                    basket = 0;
                    break;
                }
            }

            if(!placed) unplaced++;
        }

        return unplaced;
    }
};