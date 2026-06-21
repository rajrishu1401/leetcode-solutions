1class DJS{
2public:
3    vector<int> rank;
4    vector<int> parent;
5    DJS(int n){
6        rank.resize(n+1);
7        for(int i=0;i<=n;i++){
8            parent.push_back(i);
9        }
10    }
11    int par(int i){
12        if(parent[i]==i){
13            return i;
14        }
15        return parent[i]=par(parent[i]);
16    }
17
18    bool join(int u,int v){
19        int up=par(u);
20        int vp=par(v);
21        if(up==vp){
22            return true;
23        }
24        if(rank[up]>rank[vp]){
25            parent[vp]=up;
26        }else if(rank[up]<rank[vp]){
27            parent[up]=vp;
28        }else{
29            parent[up]=vp;
30            rank[vp]++;
31        }
32        return false;
33    }
34
35};
36class Solution {
37public:
38    
39    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
40        DJS d(edges.size());
41        for(int i=0;i<edges.size();i++){
42            if(d.join(edges[i][0],edges[i][1])){
43                return {edges[i][0],edges[i][1]};
44            }
45        }
46        return {};
47    }
48};