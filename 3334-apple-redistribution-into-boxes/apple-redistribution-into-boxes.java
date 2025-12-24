

class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int minBoxes = 0;
        int totalApples = 0;
        int i = capacity.length - 1;
        Arrays.sort(capacity);

        for (int app: apple) {
            totalApples += app;
        }

        while (totalApples > 0 && i >= 0) {
            minBoxes += 1;
            totalApples -= capacity[i];
            i--;
        }

        return minBoxes;
    }
}