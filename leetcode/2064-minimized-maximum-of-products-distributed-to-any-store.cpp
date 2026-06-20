1class Solution {
2public:
3    int minimizedMaximum(int n, vector<int>& quantities) {
4        int e=0;
5        for(int i:quantities){
6            e=max(e,i);
7        }
8        int s=1;
9        e++;
10        while(s<e){
11            int mid=(s+e)/2;
12            int m=0;
13            for(int i=0;i<quantities.size();i++){
14                m+=(quantities[i]/mid)+(quantities[i]%mid?1:0);
15            }
16            if(m>n){
17                s=mid+1;
18            }else{
19                e=mid;
20            }
21        }
22        return e;
23
24    }
25};