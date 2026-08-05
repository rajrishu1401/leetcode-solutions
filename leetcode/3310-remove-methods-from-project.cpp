1class Solution {
2public:
3    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
4        vector<vector<int>> nodes(n);
5        for(vector<int> i:invocations){
6            nodes[i[0]].push_back(i[1]);
7        }
8        vector<bool> v(n);
9        vector<bool> d(n);
10        v[k]=true;
11        d[k]=true;
12        dfs(nodes,k,v,d);
13        vector<int> a;
14        for(int i=0;i<n;i++){
15            if(!v[i]){
16                v[i]=true;
17                if(df(nodes,i,v,d)){
18                    for(int i=0;i<n;i++){
19                        a.push_back(i);
20                    }
21                    return a;
22                }
23            }
24        }
25        for(int i=0;i<n;i++){
26            if(!d[i]){
27                a.push_back(i);
28            }
29        }
30        return a;
31    }
32    bool df(vector<vector<int>>& nodes,int i,vector<bool>& v,vector<bool>& d){
33        for(int j:nodes[i]){
34            if(d[j]){
35                return true;
36            }
37            if(!v[j]){
38                v[j]=true;
39                if(df(nodes,j,v,d)){
40                    return true;
41                }
42            }
43        }
44        return false;
45    }
46    void dfs(vector<vector<int>>& nodes,int i,vector<bool>& v,vector<bool>& d){
47        for(int j:nodes[i]){
48            if(!v[j]){
49                v[j]=true;
50                d[j]=true;
51                dfs(nodes,j,v,d);
52            }
53        }
54    }
55
56};