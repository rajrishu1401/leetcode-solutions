1class TreeAncestor {
2public:
3    vector<vector<int>> c;
4    TreeAncestor(int n, vector<int>& parent) {
5        c.resize(n,vector<int>(log2(n)+1,-1));
6        for(int i=1;i<n;i++){
7            c[i][0]=parent[i];
8        }
9        for(int i=1;i<c[0].size();i++){
10            for(int j=1;j<n;j++){
11                if(c[j][i-1]<0){
12                    continue;
13                }
14                c[j][i]=c[c[j][i-1]][i-1];
15            }
16        }
17    }
18    
19    int getKthAncestor(int node, int k) {
20        while(k>0){
21            int u=log2(k);
22            k-=pow(2,u);
23            node=c[node][u];
24            if(node==-1){
25                return -1;
26            }
27        }
28        return node;
29    }
30};
31
32/**
33 * Your TreeAncestor object will be instantiated and called as such:
34 * TreeAncestor* obj = new TreeAncestor(n, parent);
35 * int param_1 = obj->getKthAncestor(node,k);
36 */