class Solution {
public:
void dfs(int node, vector<vector<int>>& g, vector<int> &vis, stack<int> &st){
    vis[node] = 1;
    for(auto ch: g[node]){
        if(vis[ch]) continue;
        dfs(ch,g,vis,st);
    }
    st.push(node);
}

void dfs2(int node, vector<vector<int>>& gr, vector<int> &v,vector<int> &temp){
    v[node] = 1;
    if(gr[node].size() == 0) return;
    temp.push_back(node);
    for(auto ch: gr[node]){
        if(v[ch]) continue;
        dfs2(ch,gr,v,temp);
    }
}

void dfs_to_check_outdegree(int v,vector<vector<int>>& g,map<int,int> &mp, vector<int> & visted, bool &flg){
    visted[v] = 1;
    for(auto ch: g[v]){
        if(mp[ch] != 1) {
            flg = false; return;
        }
        if(!visted[ch]){
            dfs_to_check_outdegree(ch,g,mp,visted,flg);
        }
    }
}

vector<string> maxNumOfSubstrings(string s) {
    int n = s.size();
    vector<int> l(26, INT_MAX), r(26, INT_MIN);
    for (int i = 0; i < n; ++i) {
        l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
        r[s[i] - 'a'] = i;
    }

    vector<vector<int>> g(27);
    // graph formation
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            if( l[s[i]-'a'] != INT_MAX ){
                if(l[j] <= i && r[j] >= i){
                    g[j].push_back(s[i]-'a');
                    // cout<<(char)(j+'a')<<" "<<s[i]-'a'<<endl;
                }
            }
        }
    }

    // Step 1
    n = 26;
    stack<int> end_time;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        //  if( l[s[i]-'a'] != INT_MAX ) continue;
        if(!vis[i]){
            dfs(i,g,vis,end_time);
        }
    }
    // Step 2
    vector<vector<int>> gr(n);
    for(int i=0;i<n;i++){
        for(auto ch: g[i]){
            gr[ch].push_back(i);
        }
    }

    // Step 3
    vector<int> v(n,0);
    vector<int> degree(n,0);
    vector<vector<int>> scc;
    for(int i=0;i<n;i++){
        int node = end_time.top(); end_time.pop();
        if(v[node]) continue;
        vector<int> temp;
        dfs2(node,gr,v,temp);
        scc.push_back(temp);
    }

    vector<string> ans;
    for(auto it: scc){
        vector<int> visted(n,0);

        if(it.size()!=0){
            // cout<<(char)(it[0]+'a')<<endl;
            map<int,int> mp;
            for(auto ele: it) mp[ele] = 1;
            bool flg = true;
            dfs_to_check_outdegree(it[0],g,mp,visted,flg);
            if(flg == true){
                // cout<<(char)(it[0]+'a')<<endl;
                int min_l = 1e9, max_r = -1;
                for(auto ele: it){
                    min_l = min(min_l, l[ele]);
                    max_r = max(max_r, r[ele]);
                }
                ans.push_back(s.substr(min_l,max_r-min_l+1));
            }
        }
        
    }

    return ans;
}
};
  
// a -> d e f a d d 
// c -> c c 
// d -> e f a d 