1class Solution {
2public:
3    vector<pair<int,int>> d={{0,1},{1,0},{-1,0},{0,-1}};
4    int m=0;
5    int maximumSafenessFactor(vector<vector<int>>& grid) {
6        int n=grid.size();
7        if(grid[0][0]==1||grid[n-1][n-1]){
8            return 0;
9        }
10        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
11        bfs(grid,dis);
12        
13        // for(int i=0;i<n;i++){
14        //     for(int j=0;j<n;j++){
15        //         cout<<dis[i][j]<<" ";
16        //     }
17        //     cout<<endl;
18        // }
19        // cout<<m<<endl;
20        int s=0;
21        int e=m;
22        while(s<e){
23            int mid=s+(e-s+1)/2;
24            if(srch(mid,dis)){
25                s=mid;
26            }else{
27                e=mid-1;
28            }
29        }
30        return s;
31    }
32    bool srch(int mid,vector<vector<int>>& dis){
33        if(dis[0][0]<mid){
34            return false;
35        }
36        int n=dis.size();
37        vector<vector<bool>> v(n,vector<bool>(n));
38        v[0][0]=true;
39        queue<vector<int>> q;
40        q.push({0,0});
41        while(!q.empty()){
42            vector<int> u=q.front();
43            q.pop();
44            if(u[0]==n-1&&u[0]==u[1]){
45                return true;
46            }
47            for(pair<int,int> j:d){
48                int x=u[0]+j.first;
49                int y=u[1]+j.second;
50                if(x>=0&&y>=0&&x<n&&y<n&&!v[x][y]&&dis[x][y]>=mid){
51                    v[x][y]=true;
52                    q.push({x,y});
53                }
54            }
55        }
56        return false;
57    }
58    void bfs(vector<vector<int>>& grid,vector<vector<int>>& dis){
59        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
60        int n=dis.size();
61        for(int i=0;i<n;i++){
62            for(int j=0;j<n;j++){
63                if(grid[i][j]==1){
64                    q.push({0,i,j});
65                    dis[i][j]=0;
66                }
67                
68            }
69        }
70        while(!q.empty()){
71            vector<int> u=q.top();
72            q.pop();
73            dis[u[1]][u[2]]=u[0];
74            m=max(m,u[0]);
75            for(pair<int,int> j:d){
76                int x=u[1]+j.first;
77                int y=u[2]+j.second;
78                if(x>=0&&y>=0&&x<n&&y<n&&dis[x][y]>(u[0]+1)){
79                    dis[x][y]=u[0]+1;
80                    q.push({u[0]+1,x,y});
81                }
82            }
83        }
84    }
85};