class CustomStack {
private:
    int top;
    int* arr;
    int size;
public:

    CustomStack(int maxSize) {
        this->top=-1;
        arr=new int[maxSize];
        this->size=maxSize;
    }
    
    void push(int x) {
        if(top<size-1){
            top++;
            arr[top]=x;
        }
    }
    
    int pop() {
        if(top==-1){
            return -1;
        }
        else{
            int element=arr[top];
            top--;
            return element;
        }
    }
    
    void increment(int k, int val) {
        int n;
        if(k>=top+1){
            n=top+1;
        }
        else{
            n=k;
        }   
        for(int i=0;i<n;i++){
            arr[i]=arr[i]+val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */