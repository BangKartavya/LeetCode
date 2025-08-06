class Solution {
private:
    vector<int> fruits;
    vector<int> baskets;
    vector<int> tree;

    void buildTree(int i, int low,int high) {
        if(low == high) {
            tree[i] = baskets[low];
            return;
        }

        int mid = low + (high-low)/2;
        int left = 2*i+1;
        int right = left+1;

        buildTree(left,low,mid);
        buildTree(right,mid+1,high);

        tree[i] = max(tree[left],tree[right]);
    }

    int placeFruit(int i, int low,int high, int value) {
        if(tree[i] < value) return false;

        if(low == high) {
            tree[i] = 0;
            return true;
        }

        int mid = low + (high-low)/2;
        int left = (2 * i) + 1;
        int right = left+1;
        
        bool found = false;

        if(tree[left] >= value) {
            found = placeFruit(left,low,mid,value);    
        }
        else found = placeFruit(right,mid+1,high,value);

        tree[i] = max(tree[left],tree[right]);

        return found;
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        this->fruits = fruits;
        this->baskets = baskets;

        int n = fruits.size();

        tree.resize(4*n,0);

        buildTree(0,0,n-1);

        int count = 0;

        for(int& f: fruits) {
            if(!placeFruit(0,0,n-1,f)) count++;
        }

        return count;
    }
};