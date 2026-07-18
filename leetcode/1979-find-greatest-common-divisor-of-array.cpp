1class Solution {
2public:
3    int findGCD(vector<int>& nums) {
4        int s=INT_MAX;
5        int b=0;
6        for(int i:nums){
7            s=min(i,s);
8            b=max(i,b);
9        }
10        return gcd(s,b);
11    }
12};