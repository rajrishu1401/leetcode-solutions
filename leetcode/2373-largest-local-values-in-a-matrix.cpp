1class Solution {
2public:
3    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
4        vector<vector<int>> ans(grid.size()-2,vector<int>(grid.size()-2));
5        for(int i=0;i<grid.size();i++){
6            for(int j=0;j<grid.size();j++){
7                int si=max(i-2,0);
8                int sj=max(j-2,0);
9                int ri=min(i,(int)ans.size()-1);
10                int rj=min(j,(int)ans.size()-1);
11                for(int y=si;y<=ri;y++){
12                    for(int x=sj;x<=rj;x++){
13                        ans[y][x]=max(ans[y][x],grid[i][j]);
14                    }
15                }
16            }
17        }
18        return ans;
19    }
20};