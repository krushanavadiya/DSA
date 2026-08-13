class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle=6*minutes; //minute hand moved in 1 min = 360/60 = 6 degree
        double hourAngle=30*(hour%12)+0.5*minutes;  // hour hand moved in 1 min= 360/720 =0.5 degree  and hour hand moved in 1 hour= 360/12= 30degree

        double diff=abs(minAngle- hourAngle);

        return min(diff, 360-diff);
    }
};