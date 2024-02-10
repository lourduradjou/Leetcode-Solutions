class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        //we have to make a map of mail and its corresponding component
        unordered_map<string, int> mailsInfo;
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                int node = i;
                //if the mail is not there is the map store it
                if(mailsInfo.find(mail) == mailsInfo.end()) //it is not there 
                {
                    mailsInfo[mail] = node;   
                } else {
                    //if already there in the map connect their components
                    ds.unionBySize(i, mailsInfo[mail]);
                }
            }
        }
        
        // step 2 is to iterate over the map an create the merged mail list 
        vector<string> mailList[n];
        for(auto it: mailsInfo) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mailList[node].push_back(mail);
        }
        
        //finally merge the entire mail vector with their respective names in sorted order
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(mailList[i].size() == 0) continue; //there is no mail in this place
            sort(mailList[i].begin(), mailList[i].end());
            
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto mail: mailList[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};