1class Solution {
2public:
3    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
4        vector<vector<pair<int,double>>> node(n);
5        for(int i=0;i<edges.size();i++){
6            node[edges[i][0]].push_back({edges[i][1],succProb[i]});
7            node[edges[i][1]].push_back({edges[i][0],succProb[i]});
8        }
9        priority_queue<pair<double,int>> q;
10        q.push({1,start_node});
11        vector<double> v(n,0);
12        v[start_node]=1;
13        while(!q.empty()){
14            pair<double,int> u=q.top();
15            q.pop();
16            if(u.second==end_node){
17                return u.first;
18            }
19            for(pair<int,double>& t:node[u.second]){
20                double g=t.second*u.first;
21                if(v[t.first]<g){
22                    v[t.first]=g;
23                    q.push({g,t.first});
24                }
25            }
26        } 
27        return 0;
28    }
29};