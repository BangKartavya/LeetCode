class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange, int numEmpty = 0) {
        if(numBottles != 0) {
            // drink
            return numBottles + maxBottlesDrunk(0,numExchange,numEmpty + numBottles);
        }
        else {
            if(numEmpty >= numExchange) {
                numBottles++;
                numEmpty -= numExchange;
                numExchange++;

                return maxBottlesDrunk(numBottles,numExchange,numEmpty);
            }
            
            return 0;
        }
    }
};