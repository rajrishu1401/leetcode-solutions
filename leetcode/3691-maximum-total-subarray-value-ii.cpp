1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        
5        int r=nums.size();
6        int l=log2(nums.size())+1;
7        vector<vector<int>> sparseMi(r,vector<int>(l,-1));
8        for(int i=0;i<r;i++){
9            sparseMi[i][0]=nums[i];
10        }
11        for(int j=1;j<l;j++){
12            int k=pow(2,j);
13            int pre=pow(2,j-1);
14            for(int i=0;(i+k-1)<r;i++){
15                int u=sparseMi[i][j-1];
16                u=min(u,sparseMi[i+pre][j-1]);
17                sparseMi[i][j]=u;
18            }
19        }
20        vector<vector<int>> sparseMa(r,vector<int>(l,-1));
21        for(int i=0;i<r;i++){
22            sparseMa[i][0]=nums[i];
23        }
24        for(int j=1;j<l;j++){
25            int k=pow(2,j);
26            int pre=pow(2,j-1);
27            for(int i=0;(i+k-1)<r;i++){
28                int u=sparseMa[i][j-1];
29                u=max(u,sparseMa[i+pre][j-1]);
30                sparseMa[i][j]=u;
31            }
32        }
33        priority_queue<pair<int,pair<int,int>>> q;
34        for(int i=0;i<r;i++){
35            q.push({ma(sparseMa,i,r-1)-mi(sparseMi,i,r-1),{i,r-1}});
36        }
37        long long ans=0;
38        while(k){
39            k--;
40            int d=q.top().first;
41            int i=q.top().second.first;
42            int j=q.top().second.second;
43            ans+=d;
44            q.pop();
45            if(i<j)q.push({ma(sparseMa,i,j-1)-mi(sparseMi,i,j-1),{i,j-1}});
46        }
47        return ans;
48    }
49    int mi(vector<vector<int>>& sparse,int i,int j){
50        int n=j-i+1;
51        int k=log2(n);
52        int u=sparse[i][k];
53        int l=n-pow(2,k);
54        u=min(u,sparse[i+l][k]);
55        return u;
56    }
57    int ma(vector<vector<int>>& sparse,int i,int j){
58        int n=j-i+1;
59        int k=log2(n);
60        int u=sparse[i][k];
61        int l=n-pow(2,k);
62        u=max(u,sparse[i+l][k]);
63        return u;
64    }
65};