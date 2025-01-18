class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        vector<vector<bool>> vis(n,vector<bool> (m, 0));;

        pq.push({0,{0,0}});

  

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
 
        while(!pq.empty())
        {
            int cost = pq.top().first;

            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();
            
            if(vis[i][j]==true)
                continue;

            
            if(i==n-1 && j==m-1){
                return cost;
            }

            vis[i][j] = true;           

            for(int k=0;k<4;k++)
            {
                int ni = dx[k]+i;
                int nj = dy[k]+j;

                if(ni>=0 && nj>=0 && ni<n && nj<m)
                {
                    int newCost = cost ;
                    newCost += k+1==grid[i][j] ? 0 : 1;
                    pq.push({newCost,{ni,nj}});
                }
            }
        }
        return 0;

    }
};

/*
1 -> 0, 1
2 -> 0, -1
3 -> 1, 0
4 -> -1, 0
*/