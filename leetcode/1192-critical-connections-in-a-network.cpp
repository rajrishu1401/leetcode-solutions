1class Solution {
2public:
3    vector<bool> edge;
4    vector<bool> v;
5    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
6        edge.resize(connections.size(),true);
7        v.resize(n);
8        vector<vector<pair<int,int>>> nodes(n);
9        int j=0;
10        for(vector<int> i:connections){
11            nodes[i[0]].push_back({i[1],j});
12            nodes[i[1]].push_back({i[0],j});
13            j++;
14        }
15        hlp(nodes,-1,0);
16        vector<vector<int>> ans;
17        for(int i=0;i<edge.size();i++){
18            if(edge[i]){
19                ans.push_back(connections[i]);
20            }
21        }
22        return ans;
23    }
24    unordered_set<int> hlp(vector<vector<pair<int,int>>>& nodes,int pre,int i){
25        unordered_set<int> a;
26        if(v[i]){
27            a.insert(i);
28            return a;
29        }
30        v[i]=true;
31        for(pair<int,int> j:nodes[i]){
32            if(j.first!=pre&&edge[j.second]){
33                unordered_set<int> b=hlp(nodes,i,j.first);
34                if(b.size()!=0){
35                    edge[j.second]=false;
36                }
37                a.merge(b);
38            }
39        }
40        if(a.count(i)){
41            a.erase(i);
42        }
43        return a;
44    }
45};