1class Solution {
2public:
3    int ans=0;
4    bool b=true;
5    int countCompleteComponents(int n, vector<vector<int>>& edges) {
6        vector<vector<int>> node(n);
7        for(vector<int>& i:edges){
8            node[i[0]].push_back(i[1]);
9            node[i[1]].push_back(i[0]);
10        }
11        vector<bool> v(n);
12        for(int i=0;i<n;i++){
13            if(!v[i]){
14                b=true;
15                v[i]=true;
16                int k=1;
17                hlp(node,i,v,node[i].size(),k);
18                if(b){
19                    ans++;
20                }
21            }
22        }
23        return ans;
24    }
25
26    void hlp(vector<vector<int>>& node,int i,vector<bool>& v,int c,int k){
27        if(node[i].size()!=c||k>(c+1)){
28            b=false;
29        }
30        for(int j:node[i]){
31            if(!v[j]){
32                v[j]=true;
33                hlp(node,j,v,c,k+1);
34            }
35        }
36    }
37};