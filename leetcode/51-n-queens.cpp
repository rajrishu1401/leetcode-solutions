1class Solution {
2public:
3    vector<vector<string>> ans;
4    unordered_map<int,string> m;
5    string s;
6    int t;
7    int st;
8    int stp;
9    vector<vector<string>> solveNQueens(int n) {
10        s="";
11        t=n;
12        st=n-1;
13        stp=n+st;
14        for(int i=0;i<n;i++){
15            s+=".";
16        }
17        for(int i=0;i<n;i++){
18            m[i]=s;
19            m[i][i]='Q';
20        }
21        vector<string> a;
22        vector<vector<bool>> v(n+(n-1)+(n-1),vector<bool>(3));
23        hlp(v,a,0);
24        return ans;
25    }
26    void hlp(vector<vector<bool>>& v,vector<string>& a,int k){
27        if(k==t){
28            ans.push_back(a);
29            return;
30        }
31        for(int i=st;i<stp;i++){
32            int u=i-k;
33            int w=i+k;
34            if(!v[i][1]&&!v[u][2]&&!v[w][0]){
35                string b=s;
36                b[i-st]='Q';
37                v[i][1]=true;
38                v[u][2]=true;
39                v[w][0]=true;
40                a.push_back(b);
41                hlp(v,a,k+1);
42                a.pop_back();
43                v[i][1]=false;
44                v[u][2]=false;
45                v[w][0]=false;
46            }
47        }
48    }
49};