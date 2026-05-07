1class Solution {
2public:
3    int findPairs(vector<int>& nums, int k) {
4        int ans=0;
5        if(k==0){
6            unordered_map<int,int> s;
7            for(int i:nums){
8                if(!s.count(i)){
9                    s[i]=1;
10                }else if(s[i]!=-1){
11                    s[i]=-1;
12                    ans++;
13                }
14            }
15            return ans;
16        }
17        unordered_set<int> s;
18        for(int i:nums){
19            s.insert(i);
20        }
21        
22        for(int i:nums){
23            if(!s.count(i)){
24                continue;
25            }
26            if(s.count(i-k)){
27                ans++;
28            }
29            if(s.count(i+k)){
30                ans++;
31            }
32            s.erase(i);
33        }
34        return ans;
35    }
36};