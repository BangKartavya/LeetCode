class MyQueue {
public:
    vector<int> vtk;
    MyQueue() {
        
    }
    
    void push(int x) {
        vtk.push_back(x);
    }
    
    int pop() {
        int x = vtk[0];
        vtk.erase(vtk.begin());
        return x;
    }
    
    int peek() {
        return vtk[0];
    }
    
    bool empty() {
        return vtk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */