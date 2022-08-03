class MyCalendar {
private:
    vector<pair<int,int>> bookings; 
    
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        for(pair<int,int>& p : this->bookings) {
            if(max(p.first,start) < min(end,p.second)) return false;
        }
        this->bookings.push_back({start,end});
        return true;
    }
};