1class Solution {
2public:
3    vector<pair<int,int>> k={{2,-1},{2,1},{1,2},{1,-2},{-1,2},{-1,-2},{-2,1},{-2,-1}};
4    bool checkValidGrid(vector<vector<int>>& grid) {
5        if(grid[0][0]!=0){
6            return false;
7        }
8        int c=1;
9        int n=grid.size()*grid.size();
10        n--;
11        int i=0;
12        int j=0;
13        while(c<=n){
14            bool p=true;
15            //cout<<i<<"  "<<j<<endl;
16            for(pair<int,int> d:k){
17                int u=i+d.first;
18                int v=j+d.second;
19                if(u>=0&&u<grid.size()&&v>=0&&v<grid.size()&&grid[u][v]==c){
20                    c++;
21                    i=u;
22                    j=v;
23                    p=false;
24                    break;
25                }
26            }
27            if(p){
28                return false;
29            }
30            //cout<<"next"<<endl;
31        }
32
33        return true;
34
35    }
36};