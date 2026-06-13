1class Solution {
2public:
3    vector<vector<int>> ans;
4    int t;
5    vector<vector<int>> combinationSum3(int k, int n) {
6        t=n; 
7        vector<int> a;
8        hlp(k,a,1,0);
9        return ans;       
10    }
11    void hlp(int k,vector<int>& a,int i,int su){
12        if(k<=0||i>9){
13            return;
14        }
15        //cout<<i<<endl;
16        hlp(k,a,i+1,su);
17        su+=i;
18        a.push_back(i);
19        k--;
20        if(su==t&&k==0){
21            ans.push_back(a);
22        }else{
23            hlp(k,a,i+1,su);
24        }
25        a.pop_back();
26    }
27};