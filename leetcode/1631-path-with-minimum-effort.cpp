1class Solution {
2public:
3    vector<pair<int,int>> r={{1,0},{-1,0},{0,1},{0,-1}};
4    int c;
5    int minimumEffortPath(vector<vector<int>>& h) {
6        int mi=INT_MAX;
7        int mx=0;
8        for(int i=0;i<h.size();i++){
9            for(int j=0;j<h[0].size();j++){
10                mi=min(mi,h[i][j]);
11                mx=max(mx,h[i][j]);
12            }
13        }
14        if(mi==mx){
15            return 0;
16        }
17        mx=mx-mi;
18        mi=0;
19        
20        while(mi<mx){
21            int mid=(mi+mx)/2;
22            vector<vector<bool>> v(h.size(),vector<bool>(h[0].size()));
23            if(hlp(h,mid,0,0,0,v)){
24               mx=c;
25            }else{
26                mi=mid+1;
27            }
28        }
29        return mx;
30        
31    }
32    bool hlp(vector<vector<int>>& h,int& k, int i,int j,int u,vector<vector<bool>>& v){
33        v[i][j]=true;
34        for(pair<int,int> p:r){
35            int x=i+p.first;
36            int y=j+p.second;
37            if(x>=0&&y>=0&&x<h.size()&&y<h[0].size()&&!v[x][y]){
38                int o=abs(h[i][j]-h[x][y]);
39                if(o<=k) {
40                    int t=max(u,o); 
41                    if(x==(h.size()-1)&&y==(h[0].size()-1)){ 
42                        c=t;
43                        return true; 
44                    }
45                    if(hlp(h,k,x,y,t,v)){
46                        return true;
47                    }
48                }
49            }
50        }
51        return false;
52    }
53    
54};