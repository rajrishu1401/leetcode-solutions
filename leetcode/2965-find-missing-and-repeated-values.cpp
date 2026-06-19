1class Solution {
2public:
3    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
4        int n=grid.size();
5        n*=n;
6        n=(n*(n+1))/2; 
7        vector<int> d(grid.size()*grid.size());
8        int su=0;
9        int y=0;
10        for(int i=0;i<grid.size();i++){
11            for(int j=0;j<grid.size();j++){
12                d[grid[i][j]-1]++;
13                if(d[grid[i][j]-1]==2){
14                    y=grid[i][j];
15                }
16                su+=grid[i][j];
17            }
18        }
19        su-=y;
20        n-=su;
21        return {y,n};
22    }
23};