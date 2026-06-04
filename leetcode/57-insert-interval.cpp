1class Solution {
2public:
3    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
4        int i=hlp(a,b[0],1);
5        int j=hlp(a,b[1],0);
6        if(i>j){
7            a.insert(a.begin()+i,b);
8        }else{
9            b[0]=min(b[0],a[i][0]);
10            b[1]=max(b[1],a[j][1]);
11            a.erase(a.begin()+i,a.begin()+j+1);
12            a.insert(a.begin()+i,b);
13        }
14        return a;
15    }
16    int hlp(vector<vector<int>>& a, int b,int j){
17        int s=0;
18        int e=a.size();
19        while(s<e){
20            int mid=(s+e)/2;
21            if(a[mid][j]==b){
22                return mid;
23            }else if(a[mid][j]>b){
24                e=mid;
25            }else{
26                s=mid+1;
27            }
28        }
29        if(j==1){
30            return s;
31        }
32        return s-1;
33    }
34};