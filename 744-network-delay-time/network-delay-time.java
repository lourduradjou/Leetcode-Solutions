class Solution {
    class Node {
        int node, time;
        public Node(int node, int time) {
            this.node = node;
            this.time = time;
        }
    }

    public int networkDelayTime(int[][] times, int n, int k) {
        int[] time = new int[n+1];
        for(int i = 1; i <= n; i++) {
            time[i] = Integer.MAX_VALUE;
        }

        List<Node>[] adj = new List[n+1];
        for(int i = 0; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }
        for(int[] it: times) {
            adj[it[0]].add(new Node(it[1], it[2]));
        }

        Queue<Node> queue = new PriorityQueue<>((n1, n2) -> n1.time - n2.time);
        queue.offer(new Node(k, 0));
        time[k] = 0;

        while( !queue.isEmpty() ) {
            Node it = queue.poll();
            int currNode = it.node;
            int currTime = it.time;

            for(int i = 0; i < adj[currNode].size(); i++) {
                Node nextPair = adj[currNode].get(i);//gets the ith node or pair
                int adjNode = nextPair.node;
                int extraTime = nextPair.time;
                if(currTime + extraTime < time[adjNode]) {
                    time[adjNode] = currTime + extraTime;
                    queue.add(new Node(adjNode, currTime + extraTime)); 
                }
            }
        }

        int ans = 0;
        for(int it: time) {
            ans = Math.max(ans, it);
        }
        return (ans != Integer.MAX_VALUE) ? ans : -1;
    }
}