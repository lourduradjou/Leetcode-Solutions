class Solution {
private:
    int findLaseredCellsCount(string laserCode) {
        int laserCnt = 0;
        for(char cell: laserCode) {
            if(cell == '1')
                laserCnt++;
        }
        return laserCnt;
    }
public:
    int numberOfBeams(vector<string>& bank) {
        //just find the previous number of ones and multiply with the current ones
        //which is maximum combination of lasers possible withing themselves.
        int totalLaserBeams = 0;
        int prevLaserCount = 0;

        for(string laserCode: bank) {
            int currLaserCount = findLaseredCellsCount(laserCode);
            if(currLaserCount == 0) continue; 
            totalLaserBeams += (currLaserCount * prevLaserCount);
            prevLaserCount = currLaserCount;
        }

        return totalLaserBeams;
    }
};