class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int AlArr[]={stoi(arriveAlice.substr(3,2)),stoi(arriveAlice.substr(0,2))};
        int AlLeave[]={stoi(leaveAlice.substr(3,2)),stoi(leaveAlice.substr(0,2))};
        int BobArr[]={stoi(arriveBob.substr(3,2)),stoi(arriveBob.substr(0,2))};
        int BobLeave[]={stoi(leaveBob.substr(3,2)),stoi(leaveBob.substr(0,2))};
        int ans=0;
        int years[]={0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        for(int i=1;i<366;i++){
            if(i>=years[AlArr[1]-1]+AlArr[0] && i>=years[BobArr[1]-1]+BobArr[0] &&
                i<=years[AlLeave[1]-1]+AlLeave[0] && i<=years[BobLeave[1]-1]+BobLeave[0])ans++;
        }   
        return ans;
    }
};