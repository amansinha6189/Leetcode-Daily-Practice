class MyCalendarThree {
private:
    int ans = 1;
    map<int,int> u;
public:
    MyCalendarThree() {
    }
    int book(int start, int end) {
        u[start]++, u[end]--;
        int eventCount = 0;
        for(auto it: u){
            eventCount += it.second;
            ans = max(ans, eventCount);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */