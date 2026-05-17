1class Solution {
2public:
3    bool canReach(vector<int>& arr, int start) {
4        queue<int> q;
5        q.push(start);
6        vector<bool> vis(arr.size());
7        vis[start]=true;
8        while(!q.empty()){
9            queue<int> p;
10            while(!q.empty()){
11                int u=q.front();
12                q.pop();
13                if(arr[u]==0){
14                    return true;
15                }
16                int v=u+arr[u];
17                if(v<arr.size()&&!vis[v]){
18                    vis[v]=true;
19                    q.push(v);
20                }
21                v=u-arr[u];
22                if(v>=0&&!vis[v]){
23                    vis[v]=true;
24                    q.push(v);
25                }
26            }
27            q=p;
28        }
29        return false;
30    }
31};