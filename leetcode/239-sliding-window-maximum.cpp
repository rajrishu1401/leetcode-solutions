1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        deque<int> d;
5        int ma=INT_MIN;
6        for(int i=0;i<k;i++){
7            while(!d.empty()&&nums[d.front()]<=nums[i]){
8                d.pop_front();
9            }
10            d.push_front(i);
11            
12        }
13        vector<int> ans (nums.size()-k+1);
14        ans[0]=nums[d.back()];
15        int j=k;
16        for(int i=1;i<ans.size();i++){
17            if(d.back()==(j-k)){
18                d.pop_back();
19            }
20            while(!d.empty()&&nums[d.front()]<=nums[j]){
21                d.pop_front();
22            }
23            d.push_front(j);
24            j++;
25            ans[i]=nums[d.back()];
26        }
27        return ans;
28    }
29};