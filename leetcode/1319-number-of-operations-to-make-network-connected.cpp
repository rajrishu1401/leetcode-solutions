1class Solution {
2public:
3    vector<pair<int,int>> vir;
4    int u=0;
5    int makeConnected(int n, vector<vector<int>>& connections) {
6        vector<vector<int>> nodes(n);
7        for(vector<int> i:connections){
8            nodes[i[0]].push_back(i[1]);
9            nodes[i[1]].push_back(i[0]);
10        }
11        int c=0;
12        vector<bool> vis(n);
13        for(int i=0;i<n;i++){
14            if(vis[i]){
15                continue;
16            }
17            c++;
18            vir.push_back({0,0});
19            trav(nodes,i,-1,vis);
20            vir[u].second/=2;
21            u++;
22        }
23        int ex=0;
24        int ans=0;
25        for(int i=0;i<u;i++){
26            ex+=(vir[i].second-vir[i].first);
27            ex++;
28        }
29        if(c>(ex+1)){
30            return -1;
31        }
32        return c-1;
33    }
34
35    void trav(vector<vector<int>>& nodes,int i,int pre,vector<bool>& vis){
36        if(vis[i]){
37            return;
38        }
39        vis[i]=true;
40        vir[u].first++;
41        vir[u].second+=nodes[i].size();
42        for(int j:nodes[i]){
43            if(j!=pre){
44                trav(nodes,j,i,vis);
45            }
46        }
47    }
48};