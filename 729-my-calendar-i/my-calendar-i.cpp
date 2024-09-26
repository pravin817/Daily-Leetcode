class MyCalendar {

private:
        std::vector<std::pair<int, int>> bookings;

public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {

        for(auto& booking: bookings)
        {
            int bookedStart = booking.first;
            int bookedEnd = booking.second;

            if(start < bookedEnd && end > bookedStart)
            {
                return false;
            }
        }

        // No overlap , we can book the event
        bookings.push_back({start,end});
        return true;
    }
};


/*
    Analysis:
    Time Complexity : O(N)  ----> Where N is the number of the bookings
    Space Complexity : O(N) ----> Where N is the number of the bookings
*/    

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */