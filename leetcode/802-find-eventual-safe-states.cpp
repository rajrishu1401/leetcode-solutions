1class Solution {
2public:
3    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
4        vector<vector<int>> h(graph.size());
5        vector<int> ans;
6        queue<int> q;
7        for(int i=0;i<graph.size();i++){
8            if(graph[i].empty()){
9                q.push(i);
10                continue;
11            }
12            for(int j=0;j<graph[i].size();j++){
13                h[graph[i][j]].push_back(i);
14            }
15        }
16        unordered_set<int> v;
17        while(!q.empty()){
18            int u=q.front();
19            q.pop();
20            ans.push_back(u);
21            v.insert(u);
22            for(int k:h[u]){
23                bool l=true;
24                for(int y:graph[k]){
25                    if(!v.count(y)){
26                        l=false;
27                        break;
28                    }
29                }
30                if(l) q.push(k);
31            }
32        }
33        sort(ans.begin(),ans.end());
34        return ans;
35    }
36};