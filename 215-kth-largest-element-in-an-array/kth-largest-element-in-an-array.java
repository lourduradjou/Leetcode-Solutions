class Solution {
    public int findKthLargest(int[] arr, int k) {
       PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
       int n = arr.length;

       for (int i = 0; i < n; i++) {
           pq.add(arr[i]);
       }

       for (int i = 0; i < k - 1; i++) {
           pq.poll();
       }

       return pq.peek();
    }
}