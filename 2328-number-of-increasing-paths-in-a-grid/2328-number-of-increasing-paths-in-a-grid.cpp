static int MOD = 1e9 +7;
static vector<int> dirs = {0,1,0,-1,0};
class Solution {
public:

    vector<vector<long>> memo;
    
    long dp(vector<vector<int>> & grid, int i, int j){
        long result = 1;
        if(memo[i][j] != -1) return memo[i][j];
        
        for(int d = 0; d<4; d++){
            int x = i + dirs[d], y = j +dirs[d+1];
        if (x>=0 && y>=0 && x< grid.size() && y < grid[0].size() && grid[x][y] > grid[i][j]){
            result = (result + dp(grid,x,y)) % MOD;
        }


    }
    return memo[i][j] = result;
    }


    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memo.resize(m,vector<long>(n,-1));

        long result = 0;
         
        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                result =(result + dp(grid,i,j)) % MOD;
            }
        }

        return result;
        
    }
};