class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> r(n);
        vector<vector<int>> c(m);

        map<int,pair<int,int>> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[mat[i][j]] = {i,j};
            }
        }

        for(int i=0;i<n*m;i++)
        {
            auto it = mp[arr[i]];
            int ki = it.first;
            int kj = it.second;

            r[ki].push_back(arr[i]);
            c[kj].push_back(arr[i]);
            
            
            if(r[ki].size()==m || c[kj].size()==n)
                return i;       
        }

        return -1;
    }
};