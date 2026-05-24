1class Solution {
2public:
3    int numIslands(vector<vector<char>>& grid) {
4        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
5        int ans=0;
6        for(int i=0;i<grid.size();i++){
7            for(int j=0;j<grid[0].size();j++){
8                if(grid[i][j]=='1'&&!vis[i][j]){
9                    vis[i][j]=true;
10                    hlp(grid,vis,i,j);
11                    ans++;
12                }
13            }
14        }
15        return ans;
16    }
17
18    void hlp(vector<vector<char>>& grid,vector<vector<bool>>& vis,int i,int j){
19        if((i+1)<grid.size()&&grid[i+1][j]=='1'&&!vis[i+1][j]){
20            vis[i+1][j]=true;
21            hlp(grid,vis,i+1,j);
22        }
23        if((i-1)>=0&&grid[i-1][j]=='1'&&!vis[i-1][j]){
24            vis[i-1][j]=true;
25            hlp(grid,vis,i-1,j);
26        }
27        if((j+1)<grid[0].size()&&grid[i][j+1]=='1'&&!vis[i][j+1]){
28            vis[i][j+1]=true;
29            hlp(grid,vis,i,j+1);
30        }
31        if((j-1)>=0&&grid[i][j-1]=='1'&&!vis[i][j-1]){
32            vis[i][j-1]=true;
33            hlp(grid,vis,i,j-1);
34        }
35    }
36};