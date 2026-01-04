class Solution {
    public int sumFourDivisors(int[] nums) {
        int n = nums.length;
        int ans = 0;

        for (int num: nums) {
            int countDivisors = 0;
            int sum = 0;
            for (int i = 1; i <= Math.sqrt(num); i++) {
                if (num % i == 0) {
                    sum += i;
                    countDivisors += 1;

                    if (i != (num / i)) {
                        sum += (num / i);
                        countDivisors += 1;
                    }
                }
            }
            
            System.out.println(countDivisors + " " + sum);
            if (countDivisors == 4)
                ans += sum;
        }

           return ans;
    }
}