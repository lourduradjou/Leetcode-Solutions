class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //just a simple greedy approach and two pointer
        int score = 0;
        int n = tokens.size();

        int low = 0;
        int high = n - 1;
        sort(tokens.begin(), tokens.end());
        int maxScore = 0;

        while (low <= high) {
            if (tokens[low] <= power) {
                power = power - tokens[low];
                score++;
                low++;
            }
            else if (score > 0) {
                score--;
                power += tokens[high];
                high--;
            } 
            else {
                return maxScore;
            }
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};