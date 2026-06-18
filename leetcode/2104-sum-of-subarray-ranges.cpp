1class Solution {
2public:
3    long long subArrayRanges(vector<int>& nums) {
4        nums.push_back(INT_MIN);
5        stack<pair<int,int>> s;
6        long long ans=0;
7        for(int i:nums){
8            int u=1;
9            while(!s.empty()&&s.top().first>=i){
10                ans+=((long long)s.top().second*(long long)u*s.top().first);
11                u+=s.top().second;
12                s.pop();
13            }
14            s.push({i,u});
15        }
16        nums.pop_back();
17        nums.push_back(INT_MAX);
18        stack<pair<int,int>> st;
19        long long ans2=0;
20        for(int i:nums){
21            int u=1;
22            while(!st.empty()&&st.top().first<=i){
23                ans2+=((long long)st.top().second*(long long)u*st.top().first);
24                u+=st.top().second;
25                st.pop();
26            }
27            st.push({i,u});
28        }
29        //cout<<ans2<<"  "<<ans<<endl;
30        return ans2-ans;
31    }
32};