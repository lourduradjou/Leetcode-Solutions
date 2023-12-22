class Solution {
public:
    int maxScore(string s) {
        //in this type of question first find the count of
        //right one and then move for each value and find 
        //the maximum one
        int maxScore = 0;
        int countOnesRight = count(s.begin(), s.end(), '1');
        int countZerosLeft = 0;

        for(int i = 0; i < s.size()-1; i++) {
            countZerosLeft += (s[i] == '0');
            countOnesRight -= (s[i] == '1');
            maxScore = max(maxScore, (countZerosLeft + countOnesRight));
        }

        return maxScore;
    }
};