1class Solution {
2public:
3    vector<vector<int>> generateMatrix(int n) {
4        vector<vector<int>> ans(n,vector<int>(n));
5        int i=0;
6        int j=0;
7        int u=n*n;
8        int m=n;
9        int b=1;
10        int s=0;
11        while(b<u){
12            while(j<n){
13                ans[i][j]=b;
14                cout<<i<<" , "<<j<<" : "<<b<<endl;
15                b++;
16                j++;
17            }
18            j--;
19            i++;
20            while(i<n){
21                ans[i][j]=b;
22                cout<<i<<" , "<<j<<" : "<<b<<endl;
23                b++;
24                i++;
25            }
26            i--;
27            j--;
28            while(j>=s){
29                ans[i][j]=b;
30                cout<<i<<" , "<<j<<" : "<<b<<endl;
31                b++;
32                j--;
33            }
34            j++;
35            i--;
36            while(i>s){
37                ans[i][j]=b;
38                cout<<i<<" , "<<j<<" : "<<b<<endl;
39                b++;
40                i--;
41            }
42            s++;
43            n--;
44            i=s;
45            j=s;
46            cout<<i<<" , "<<j<<" ->: "<<b<<endl;
47            
48        }
49        if(m&1)ans[i][j]=u;
50        return ans;
51    }
52};