1class DJS{
2public:
3    vector<int> rank;
4    vector<int> parent;
5    DJS(int n){
6        rank.resize(n+1);
7        parent.resize(n+1);
8        for(int i=0;i<=n;i++){
9            parent[i]=i;
10        }
11    }
12    int par(int n){
13        if(parent[n]==n){
14            return n;
15        }
16        return parent[n]=par(parent[n]);
17    }
18    void join(int a,int b){
19        int pa=par(a);
20        int pb=par(b);
21        if(pa==pb){
22            return;
23        }
24        if(rank[pa]>rank[pb]){
25            parent[pb]=pa;
26        }else if(rank[pb]>rank[pa]){
27            parent[pa]=pb;
28        }else{
29            parent[pb]=pa;
30            rank[pa]++;
31        }
32    }
33};
34
35
36class Solution {
37public:
38    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
39        unordered_map<string,pair<string,int>> u;
40        int t=0;
41        for(int i=0;i<a.size();i++){
42            for(int j=1;j<a[i].size();j++){
43                if(u.count(a[i][j])){
44                    continue;
45                }
46                u[a[i][j]]={a[i][0],t};
47                t++;
48            }
49        }
50        DJS d(t);
51        for(int i=0;i<a.size();i++){
52            for(int j=2;j<a[i].size();j++){
53                d.join(u[a[i][j]].second,u[a[i][j-1]].second);
54            }
55        }
56        vector<vector<string>> ans;
57        unordered_map<int,int> r;
58        for(auto it:u){
59            int b=d.par(it.second.second);
60            if(!r.count(b)){
61                ans.push_back({it.second.first,it.first});
62                r[b]=ans.size()-1;
63            }else{
64                ans[r[b]].push_back(it.first);
65            }
66        }
67        for(vector<string>& i:ans){
68            sort(i.begin()+1,i.end());
69        }
70        return ans;
71    }
72};