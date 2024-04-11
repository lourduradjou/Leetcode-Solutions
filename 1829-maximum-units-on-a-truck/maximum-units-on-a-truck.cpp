class Solution {
private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[1] > b[1];
    }

public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // we have to maximize the number of units that the truckSize could accomodate
        //ofcourse a maximization greedy problem

        int maximumBoxes = 0;
        sort(boxTypes.begin(), boxTypes.end(), cmp);

        for (auto box: boxTypes) {
            //check if that box is accomotable in the truck
            if (box[0] <= truckSize)
            {
                maximumBoxes += (box[0] * box[1]);
                truckSize -= box[0];
            }
            else {
                maximumBoxes += (truckSize * box[1]);
                break;
            }
        }

        return maximumBoxes;
    }
};