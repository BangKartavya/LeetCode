class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int> p;

        int i =0;
        int diff = 0;
        for(i= 0;i<h.size()-1;i++) {
            diff = h[i+1]-h[i];
            if(diff<=0) continue;
            bricks-=diff;
            p.push(diff);
            if(bricks<0) {
                bricks+=p.top();
                p.pop();
                ladders--;
            }
            if(ladders<0) break;
        }
        return i;
    }
};