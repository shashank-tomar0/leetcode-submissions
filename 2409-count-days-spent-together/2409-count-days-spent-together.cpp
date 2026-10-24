class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string start = max(arriveAlice , arriveBob);
        string end = min(leaveAlice , leaveBob);
        if(start > end)
            return 0;
        return daysCount(end) - daysCount(start) + 1;
    }
    int daysCount(string time){
        vector<int> months = {31 , 28 , 31 , 30 , 31, 30 , 31 , 31 , 30 , 31 , 30 , 31};
        int month = stoi(time.substr(0 , 2));
        int day = stoi(time.substr(3 , 2));
        int totaldays = 0;
        for(int i = 0; i < month - 1; i++){
            totaldays += months[i];
        }
        return totaldays + day;
    }
};