class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        int swaps[4] = {0,0,0,0};

        bool canMake[4] = {true,true,true,true};
        int makeEqual = tops[0]; // first case

        for(int i = 0;i<n;i++) {
            if(tops[i] != makeEqual && bottoms[i] == makeEqual) {
                swaps[0]++;
            }
            else if(tops[i] != makeEqual && bottoms[i] != makeEqual) {
                canMake[0] = false;
                break;
            }
        }

        for(int i = 0;i<n;i++) {
            if(bottoms[i] != makeEqual && tops[i] == makeEqual) {
                swaps[1]++;
            }
            else if (bottoms[i] != makeEqual && tops[i] != makeEqual) {
                canMake[1] = false;
                break;
            }
        }

        makeEqual = bottoms[0];

        for(int i = 0;i<n;i++) {
            if(tops[i] != makeEqual && bottoms[i] == makeEqual) {
                swaps[2]++;
            }
            else if (tops[i] != makeEqual && bottoms[i] != makeEqual) {
                canMake[2] = false;
                break;
            }
        }

        for(int i = 0;i<n;i++) {
            if(bottoms[i] != makeEqual && tops[i] == makeEqual) {
                swaps[3]++;
            }
            else if (bottoms[i] != makeEqual && tops[i] != makeEqual) {
                canMake[3] = false;
                break;
            }
        }

        int result = INT_MAX;

        for(int i = 0;i<4;i++) {
            if(canMake[i]) result = min(result,swaps[i]);
        }

        if(result == INT_MAX) return -1;

        return result;

    }
};