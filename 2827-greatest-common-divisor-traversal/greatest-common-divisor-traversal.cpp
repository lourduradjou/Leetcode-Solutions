class DisjointSet {
    public:
        vector<int> parent;
        vector<int> rank;
        DisjointSet(int n) {
            parent.resize(n, 0);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++) 
                parent[i] = i;
        }

        int find(int node) {
            return parent[node] = (parent[node] == node) ? node: find(parent[node]);
        }

        void reset(int node) {
            parent[node] = node;
        }

        void Union(int nodeA, int nodeB) {
            int uParA = find(nodeA), uParB = find(nodeB);
            if (uParA != uParB) {
                rank[uParA] < rank[uParB] ? parent[uParA] = uParB : parent[uParB] = uParA;
                rank[uParA] += rank[uParA] == rank[uParB] ? 1: 0;
            }
        }
};

const int MAX = 1e5 + 5;
bool prime[MAX];
int spf[MAX]; //smallest prime factor of a number;
int cnt = 0;

class Solution {
public:
    void sieve() {
        fill(prime, prime + MAX, true);
        for (int i = 1; i < MAX; i++) {
            spf[i] = i;
        }
        prime[0] = prime[1] = false;

        for (int i  = 2; i * i < MAX; i++) {
            if (prime[i]) {
                for (int j = i * i; j < MAX; j += i) {
                    if (prime[j])
                        spf[j] = i; // smallest prime will be this i for
                        //the first time
                    prime[j] = false;
                }
            }
        }
    }

    unordered_set<int> getFactorization(int x) {
        unordered_set<int> st;
        while ( x > 1) {
            st.insert(spf[x]);
            x = x / spf[x];
        }
        return st;
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        sieve();

        int n = nums.size();
        DisjointSet ds(n+1);

        unordered_map<int,vector<int>> mp;
        for (int i = 0; i < n; i++) {
            unordered_set<int> primeFactors = getFactorization(nums[i]);

            for(auto prime: primeFactors) {
                mp[prime].push_back(i);
            }       
        }

        for (auto &it: mp) {
            vector<int> ids = it.second;
            if(ids.size() <= 1) continue;

            for (int i = 1; i < ids.size(); i++) {
                ds.Union(ids[i], ids[i-1]);
            }
        }
        
        for (int i = 1; i < n; i++) {
            if (ds.find(i) != ds.find(i-1)) {
                return false;
            }
        }

        return true;
    }
};


