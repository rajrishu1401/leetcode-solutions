1class Solution {
2public:
3    int mod=1e9+7;
4    int assignEdgeWeights(vector<vector<int>>& edges) {
5        vector<vector<int>> n(edges.size()+2);
6        for(int i=0;i<edges.size();i++){
7            n[edges[i][0]].push_back(edges[i][1]);
8            n[edges[i][1]].push_back(edges[i][0]);
9        }
10        vector<bool> v(edges.size()+2);
11        queue<int> q;
12        q.push(1);
13        v[1]=true;
14        int c=0;
15        while(!q.empty()){
16            queue<int> p;
17            while(!q.empty()){
18                int u=q.front();
19                q.pop();
20                for(int j:n[u]){
21                    if(!v[j]){
22                        v[j]=true;
23                        p.push(j);
24                    }
25                    
26                }
27            }
28            q=move(p);
29            c++;
30        }
31        c-=2;
32        long long ans=1;
33        while(c){
34            if(c>30){
35                ans*=pow(2,30);
36                ans%=mod;
37                c-=30;
38            }else{
39                ans*=pow(2,c);
40                ans%=mod;
41                return ans;
42            }
43        }
44        return ans;
45    }
46};