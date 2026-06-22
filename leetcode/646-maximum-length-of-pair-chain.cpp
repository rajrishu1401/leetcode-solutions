1class Solution {
2public:
3    int findLongestChain(vector<vector<int>>& pairs) {
4        sort(pairs.begin(),pairs.end(),[](vector<int>& a,vector<int>& b){
5            if(a[1]==b[1]){
6                return a[0] < b[0];
7            }
8            return a[1] < b[1];
9        });
10        // for(vector<int> i:pairs){
11        //     cout<<i[0]<<"  "<<i[1]<<endl;
12        // }
13        int ans=1;
14        int last=pairs[0][1];
15        for(int i=1;i<pairs.size();i++){
16            if(last<pairs[i][0]){
17                ans++;
18                last=pairs[i][1];
19            }
20        }
21        return ans;
22    }
23};