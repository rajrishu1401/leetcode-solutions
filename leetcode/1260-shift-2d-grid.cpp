1class Solution {
2public:
3    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
4        int n=grid.size();
5        int m=grid[0].size();
6        k%=(n*m);
7        vector<vector<int>> r(n,vector<int>(m));
8        int u=k/m;
9        u%=n;
10        int v=k%m;
11        for(int i=0;i<n;i++){
12            for(int j=0;j<m;j++){
13                int u1=grid[i][j];
14                r[u][v]=u1;
15                v++;
16                if(v==m){
17                    v=0;
18                    u++;
19                    if(u==n){
20                        u=0;
21                    }
22                }
23            }
24        }
25        return r;
26    }
27};