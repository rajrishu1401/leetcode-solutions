1class Solution {
2public:
3    bool findSafeWalk(vector<vector<int>>& grid, int health) {
4        priority_queue<vector<int>> q;
5        if(grid[0][0]==1){
6            if(health==1){
7                return false;
8            }
9            health--;
10        }
11        q.push({health,0,0});
12        vector<pair<int,int>> d={{0,1},{1,0},{-1,0},{0,-1}};
13        vector<vector<int>> h(grid.size(),vector<int>(grid[0].size()));
14        if(0==(grid.size()-1)&&0==(grid[0].size()-1)){
15            return true;
16        }
17        h[0][0]=health;
18        while(!q.empty()){
19            vector<int> u=q.top();
20            q.pop();
21            for(pair<int,int> t:d){
22                int x=u[1]+t.first;
23                int y=u[2]+t.second;
24                int hel=u[0];
25                if(x>=0&&y>=0&&x<grid.size()&&y<grid[0].size()){
26                    if(grid[x][y]==1){
27                        hel--;
28                        if(hel==0){
29                            continue;
30                        }
31                    }
32                    if(x==(grid.size()-1)&&y==(grid[0].size()-1)){
33                        return true;
34                    }
35                    if(hel>h[x][y]){
36                        h[x][y]=hel;
37                        q.push({hel,x,y});
38                    }
39                }
40                
41            }
42        } 
43        return false;
44    }
45};