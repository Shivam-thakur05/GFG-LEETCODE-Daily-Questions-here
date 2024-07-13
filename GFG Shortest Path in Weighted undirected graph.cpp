class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        vector<int>ans;
        queue<int>pq;
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=INT_MAX;
        }
        dp[1][0]=0;
        
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        pq.push(1);
        while(!pq.empty())
        {
            int x=pq.front();
            for(auto itr:adj[x])
            {
                if(dp[x][0]+itr.second<dp[itr.first][0])
                {
                    dp[itr.first][0]=dp[x][0]+itr.second;
                    dp[itr.first][1]=x;
                    pq.push(itr.first);
                }
            }
            pq.pop();
        }
        if(dp[n][1]==-1)
        {
            return {-1};
        }
        ans.push_back(dp[n][0]);
        int i=n;
        while(i>=1)
        {
            ans.push_back(i);
            i=dp[i][1];
        }
        reverse(ans.begin()+1,ans.end());
      
        
        return ans;
    }
};
