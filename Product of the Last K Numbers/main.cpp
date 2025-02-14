class ProductOfNumbers {
private:
    vector<int> v;
public:
    ProductOfNumbers() {
        v.clear();
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        if(k == 1) return v.back();

        int prod = 1;
        int endIdx = v.size()-k;
        for(int i = v.size()-1;i >= endIdx;i--) prod *= v[i];

        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */