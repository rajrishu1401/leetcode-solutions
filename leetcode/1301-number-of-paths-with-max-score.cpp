1class Solution {
2public:
3    int mod=1e9+7;
4    vector<int> pathsWithMaxScore(vector<string>& board) {
5        vector<vector<vector<int>>> dp(board.size(),vector<vector<int>>(board.size(),vector<int>(2,-1)));
6        return hlp(board,dp,board.size()-1,board.size()-1);
7    }
8
9    vector<int> hlp(vector<string>& b,vector<vector<vector<int>>>& dp,int i,int j){
10       if(i<0||j<0||b[i][j]=='X'){
11        return {0,0};
12       } 
13       if(i==0&&j==0){
14        return {0,1};
15       }
16       if(dp[i][j][0]!=-1){
17        return dp[i][j];
18       }
19       vector<int> r=hlp(b,dp,i-1,j);
20       vector<int> p=hlp(b,dp,i,j-1);
21       if(p[0]>r[0]){
22        r=p;
23       }else if(p[0]==r[0]){
24        long long u=(long long)r[1]+p[1];
25        u%=mod;
26        r[1]=u;
27       }
28       p=hlp(b,dp,i-1,j-1);
29       if(p[0]>r[0]){
30        r=p;
31       }else if(p[0]==r[0]){
32        long long u=(long long)r[1]+p[1];
33        u%=mod;
34        r[1]=u;
35       }
36       //cout<<i<<"  "<<j<<endl;
37       //cout<<r[0]<<"  - >  "<<r[1]<<endl;
38       if(r[1]==0){
39        dp[i][j]={0,0};
40        return {0,0};
41       }
42       if(b[i][j]!='S')r[0]+=(b[i][j]-'0');
43       dp[i][j]=r;
44       return dp[i][j];
45    }
46};