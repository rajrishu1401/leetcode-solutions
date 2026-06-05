1class Solution {
2public:
3    int swimInWater(vector<vector<int>>& grid) {
4        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
5        q.push({grid[0][0],0,0});
6        vector<vector<bool>> vis(grid.size(),vector<bool>(grid.size()));
7        vis[0][0]==true;
8        vector<pair<int,int>> d={{0,1},{1,0},{-1,0},{0,-1}};
9        int ans=grid[0][0];
10        while(!q.empty()){
11            vector<int> u=q.top();
12            ans=max(ans,u[0]);
13            if(u[1]==(grid.size()-1)&&u[1]==u[2]){
14                return ans;
15            }
16            q.pop();
17            for(pair<int,int> l:d){
18                int i1=u[1]+l.first;
19                int j1=u[2]+l.second;
20                if(i1>=0&&i1<grid.size()&&j1>=0&&j1<grid.size()&&!vis[i1][j1]){
21                    vis[i1][j1]=true;
22                    q.push({grid[i1][j1],i1,j1});
23                }
24            }
25        }
26        return ans;
27    }
28};