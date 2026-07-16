1class Solution {
2public:
3    long long gcdSum(vector<int>& nums) {
4        vector<int> r;
5        int m=0;
6        for(int i:nums){
7            m=max(i,m);
8            r.push_back(gcd(m,i));
9        }
10        sort(r.begin(),r.end());
11        long long ans=0;
12        int i=0;
13        int j=r.size()-1;
14        while(i<j){
15            ans+=gcd(r[i],r[j]);
16            i++;
17            j--;
18        }
19        return ans;
20    }
21};