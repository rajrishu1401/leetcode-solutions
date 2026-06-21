1class Solution {
2public:
3    int kthSmallest(vector<vector<int>>& matrix, int k) {
4        if(k==1){
5            return matrix[0][0];
6        }
7        if(k==matrix.size()*matrix.size()){
8            return matrix[matrix.size()-1][matrix.size()-1];
9        }
10        int ea=matrix[0][0];
11        int ma=matrix[matrix.size()-1][matrix.size()-1];
12        while(ea<=ma){
13            int mid=(ea+ma)/2;
14            int u=fnd(matrix,mid);
15            int v=fnd(matrix,mid+1);
16            //cout<<mid<<" : "<<u<<","<<v<<endl;
17            if(u<v){
18                if(u<k&&k<=v)
19                    return mid;
20                if(k<=u){
21                    ma=mid-1;
22                }else{
23                    ea=mid+1;
24                }
25            }else{
26                if(k<=u){
27                    ma=mid-1;
28                }else{
29                    ea=mid+1;
30                }
31            }
32        }
33        return -1;
34    }
35    int fnd(vector<vector<int>>& matrix,int t){
36        int s=0;
37        int e=matrix.size()-1;
38        int ans=0;
39        while(s<matrix.size()&&e>=0){
40            if(matrix[s][e]>=t){
41                e--;
42            }else if(matrix[s][e]<t){
43                ans+=(e+1);
44                s++;
45            }
46        }
47        return ans;
48    }
49};