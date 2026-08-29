1class Solution {
2public:
3    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
4        unordered_map<int,queue<int>> r;
5        for(int i=0;i<nums.size();i++){
6            r[nums[i]].push(i);
7        }
8        sort(nums.begin(),nums.end());
9        vector<int> ans(nums.size(),-1);
10        vector<int> mi;
11        mi.push_back(r[nums[0]].front());
12        r[nums[0]].pop();
13        int c=1;
14        for(int i=1;i<nums.size();i++){
15            if((nums[i]-nums[i-1])>limit){
16                sort(mi.begin(),mi.end());
17                for(int j=0;j<mi.size();j++){
18                    ans[mi[j]]=nums[i-c];
19                    c--;
20                }
21                c=1;
22                mi=vector<int>();
23            }else{
24                c++;
25            }
26            mi.push_back(r[nums[i]].front());
27            r[nums[i]].pop();
28        }
29        sort(mi.begin(),mi.end());
30        for(int j=0;j<mi.size();j++){
31            ans[mi[j]]=nums[nums.size()-c];
32            c--;
33        }
34        return ans;
35    }
36};