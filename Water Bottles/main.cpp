class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange, int numEmpty = 0) {
        if(numBottles == 0 && numEmpty < numExchange) return 0;

        if(numEmpty >= numExchange) {
            numBottles = numEmpty / numExchange;
            numEmpty = numEmpty % numExchange;
        }

        int totalDrunk = numBottles + numWaterBottles(0,numExchange,numEmpty+numBottles);

        return totalDrunk;
    }
};