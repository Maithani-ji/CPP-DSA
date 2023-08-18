class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> s{
            "Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday",//IN ZELLERS CALENDAR,WEEK STARTS FROM SATURDAY
        };

        if(month<3){//AND YEAR HAS 14 MONTHS , INCLUDING JANUARY AND FEB OF NEXT YEAR
            month+=12;
            year--;
        
        }
        //using ZELLERS CONGRUENCE FORMULA to calculate day of the week.
        int h = (day + (13 * (month + 1)) / 5 + year + year / 4 - year / 100 + year / 400) % 7;

        return s[h];
        
    }
};