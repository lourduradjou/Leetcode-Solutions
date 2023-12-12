class Solution {
public:
    int maxheightrect(vector<int>& height){
        int n=height.size();
        vector<int> lheit(n),rheit(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and height[st.top()]>=height[i]) st.pop();

            if(st.empty()) lheit[i]=0;
            else lheit[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and height[st.top()]>=height[i]) st.pop();

            if(st.empty()) rheit[i]=n-1;
            else rheit[i]=st.top()-1;
            st.push(i);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,height[i]*(rheit[i]-lheit[i]+1));
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // cout<<n<<" "<<m<<endl;
        int maxi=0;
        vector<int> height(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')height[j]++;
                else height[j]=0;
            }
            int longest = maxheightrect(height);
            maxi=max(maxi,longest);
        }
        return maxi;
    }
};