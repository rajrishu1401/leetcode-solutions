1class Solution {
2public:
3    long long numberOfWeeks(vector<int>& mil) {
4        long long ans=0;
5        int m=0;
6        for(int i:mil){
7            m=max(i,m);
8            ans+=i;
9        }
10        ans-=m;
11        if(m<=(ans+1)){
12            return ans+m;
13        }
14        return (ans*2)+1;
15    }
16};