1class Solution {
2public:
3    vector<string> simplifiedFractions(int n) {
4        vector<string> ans;
5        for(int i=1;i<n;i++){
6            for(int j=i+1;j<=n;j++){
7                //cout<<i<<","<<j<<" = "<<gcd(i,j)<<endl;
8                if(gcd(i,j)==1)ans.push_back(to_string(i)+"/"+to_string(j));
9            }
10        }
11        return ans;
12    }
13};