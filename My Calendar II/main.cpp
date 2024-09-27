class MyCalendarTwo {
public:
    vector<pair<int,int>> s1;
    vector<pair<int,int>> s2;

    MyCalendarTwo() {
        s1.reserve(1000);
        s2.reserve(1000);
    }
    
    bool book(int start, int end) {
        for(auto i: s2) {
            if(max(i.first,start) < min(i.second,end)) return false;
        }

        for(auto i: s1) {
            int s0 = max(i.first,start);
            int t0 = min(i.second,end);
            if(s0 < t0) s2.push_back({s0,t0});
        }
        s1.push_back({start,end});

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */