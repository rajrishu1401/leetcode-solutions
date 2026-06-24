1class Solution {
2public:
3    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
4        unordered_set<int> col[4];
5        queue<int> q;
6        vector<vector<int>> nodes(n);
7        for(vector<int> i:paths){
8            nodes[i[0]-1].push_back(i[1]-1);
9            nodes[i[1]-1].push_back(i[0]-1);
10        }
11        vector<int> v(n,-1);
12        for(int e=0;e<n;e++){
13            if(v[e]!=-1){
14                continue;
15            }
16            q.push(e);
17            while(!q.empty()){
18                int u=q.front();
19                q.pop();
20                if(v[u]!=-1){
21                    continue;
22                }
23                int c=-1;
24                for(int i=0;i<4;i++){
25                    if(!col[i].count(u)){
26                        c=i;
27                        break;
28                    }
29                }
30                v[u]=c+1;
31                for(int j:nodes[u]){
32                    col[c].insert(j);
33                    q.push(j);
34                }
35            }
36        }
37        
38        return v;
39    }
40};