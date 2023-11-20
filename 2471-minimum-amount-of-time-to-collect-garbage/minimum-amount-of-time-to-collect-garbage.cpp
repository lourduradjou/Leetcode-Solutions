class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        long long totalMinutes = 0;
        long long currentTravelTime = 0;

        totalMinutes += garbage[0].size();

        vector<int> lastGarbageIndices(3, -1);

        for(int houseIndex = 1; houseIndex < garbage.size(); houseIndex++) {
            totalMinutes += garbage[houseIndex].size();

            if(garbage[houseIndex].find("M") != garbage[houseIndex].npos)
                lastGarbageIndices[0] = houseIndex - 1;
            if(garbage[houseIndex].find("P") != garbage[houseIndex].npos)
                lastGarbageIndices[1] = houseIndex - 1;
            if(garbage[houseIndex].find("G") != garbage[houseIndex].npos)
                lastGarbageIndices[2] = houseIndex - 1;
            
        }


        for(int truckTravelIndex = 0; truckTravelIndex < travel.size(); truckTravelIndex++) {
            currentTravelTime += travel[truckTravelIndex];

            for(int iter = 0; iter < 3; iter++) {
                if(lastGarbageIndices[iter] == truckTravelIndex)
                    totalMinutes += currentTravelTime;
            }
        }

        return totalMinutes;
    }
};