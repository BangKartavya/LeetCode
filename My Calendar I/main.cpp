class MyCalendar {
public:
  map<int, int> mp;
  MyCalendar() {}

  bool book(int start, int end) {
    auto p = mp.upper_bound(start);

    if (p == mp.end() || end <= p->second) {
      mp[end] = start;
      return true;
    }
    return false;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */