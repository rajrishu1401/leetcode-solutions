1class Solution {
2public:
3    vector<vector<char>> rotateTheBox(vector<vector<char>>& b) {
4        vector<vector<char>> ans(b[0].size(),vector<char>(b.size()));
5        int l=b.size()-1;
6        for(int j=0;j<b.size();j++){
7            int k=b[0].size();
8            for(int i=b[0].size()-1;i>=0;i--){
9                if(b[j][i]=='*'){
10                    k=i;
11                    ans[i][l]='*';
12                }else if(b[j][i]=='#'){
13                    if((k-1)!=i){
14                        ans[k-1][l]='#';
15                        ans[i][l]='.';
16                    }else{
17                        ans[i][l]='#';
18                    }
19                    k--;
20                }else{
21                    ans[i][l]='.';
22                }
23            }
24            l--;
25        }
26        return ans;
27    }
28};