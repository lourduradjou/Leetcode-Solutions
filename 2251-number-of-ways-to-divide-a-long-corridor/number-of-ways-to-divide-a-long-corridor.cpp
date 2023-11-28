class Solution {
public:
    static const long long MOD = 1000000007;
    int numberOfWays(string corridor) {
        long long seat = 0, res = 1, plant = 0;

        for(char thing: corridor) {
            if(thing == 'S')
                seat += 1;
            else 
                if(seat == 2)
                    plant += 1;
            
            //if seat count is 3 or odd here
            if(seat == 3) {
                res = (res * (plant + 1)) % MOD;
                seat = 1;
                plant = 0;
            }
        }

        return seat != 2 ? 0: res;
    }
};