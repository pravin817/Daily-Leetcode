class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12){
            hour = 0;
        }


        if(minutes == 60){
            minutes = 0;
        }

        double hourAngle = (0.5)*(60*hour + minutes);
        double minutesAngle = 6*minutes;

        double angle = abs(hourAngle - minutesAngle);

        return min(angle, 360- angle);
    }
};

/*
    Analysis:
    Time Complexity : O(1)
    Space Complexity : O(1)
*/    