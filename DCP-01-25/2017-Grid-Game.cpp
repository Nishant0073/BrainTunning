class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topsum = 0;
        long long butsum = 0;
        int n = grid[0].size();

        for(int i=0;i<n;i++){
            topsum+=grid[0][i];
        }
        long long result = LLONG_MAX;
        for(int i=0;i<n;i++){
            topsum -= grid[0][i];
            result = min(result,max(topsum,butsum));
            butsum += grid[1][i];
            cout<<topsum<<" "<<butsum<<endl;
        }
        return result;
    }
};