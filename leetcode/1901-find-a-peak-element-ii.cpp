1class Solution {
2public:
3    int n;
4    int m;
5    vector<int> findPeakGrid(vector<vector<int>>& mat) {
6        n=mat.size();
7        m=mat[0].size();
8        if(m==1&&n==1){
9            return {0,0};
10        }
11        if(m>n){
12            for(int i=0;i<n;i++){
13                vector<int> u=hlp(mat,i);
14                if(u[0]!=-1){
15                    return u;
16                }
17            }
18        }else{
19            for(int i=0;i<m;i++){
20                vector<int> u=hlp2(mat,i);
21                if(u[0]!=-1){
22                    return u;
23                }
24            }
25        }
26        
27        return {-2,-2};
28    }
29    vector<int> hlp(vector<vector<int>>& mat,int i){
30        int s=0;
31        int e=m;
32        while(s<e){
33            int mid=(e+s)/2;
34            if((mid+1)<m&&mat[i][mid]<mat[i][mid+1]){
35                s=mid+1;
36            }else if((mid-1)>=0&&mat[i][mid]<mat[i][mid-1]){
37                e=mid;
38            }else{
39                if((i==0||mat[i-1][mid]<mat[i][mid])&&((i+1)>=n||mat[i+1][mid]<mat[i][mid])){
40                    return {i,mid};
41                }
42                return hlp2(mat,mid);
43            }
44        }
45        return {-1,-1};
46    }
47    vector<int> hlp2(vector<vector<int>>& mat,int j){
48        int s=0;
49        int e=n;
50        while(s<e){
51            int mid=(e+s)/2;
52            if((mid+1)<n&&mat[mid][j]<mat[mid+1][j]){
53                s=mid+1;
54            }else if((mid-1)>=0&&mat[mid][j]<mat[mid-1][j]){
55                e=mid;
56            }else{
57                if((j==0||mat[mid][j-1]<mat[mid][j])&&((j+1)>=m||mat[mid][j+1]<mat[mid][j])){
58                    return {mid,j};
59                }
60                return hlp(mat,mid);
61            }
62        }
63        return {-1,-1};
64    }
65};