1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        int c=0;
5        int ans=0;
6        for(int i:gain){
7            c+=i;
8            ans=max(c,ans);
9        }
10        return ans;
11    }
12};