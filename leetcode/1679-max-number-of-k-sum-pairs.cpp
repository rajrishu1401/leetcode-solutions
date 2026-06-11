1class Solution {
2public:
3    int maxOperations(vector<int>& nums, int k) {
4        unordered_map<int,int> m;
5        for(int i:nums){
6            m[i]++;
7        }
8        int ans=0;
9        for(int i:nums){
10            if(m.count(i)){
11                if(i==(k-i)){
12                    ans+=(m[i]/2);
13                }else if(m.count(k-i)){
14                    ans+=min(m[k-i],m[i]);
15                    m.erase(k-i);
16                }
17                m.erase(i);
18            }
19            if(m.size()==0){
20                break;
21            }
22        }
23        return ans;
24    }
25};