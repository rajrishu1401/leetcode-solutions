1class Solution {
2public:
3    vector<int> ans;
4    vector<int> countSmaller(vector<int>& nums) {
5        ans=vector<int>(nums.size());
6        vector<pair<int,int>> arr;
7        for(int i=0;i<nums.size();i++){
8            arr.push_back({nums[i],i});
9        }
10        sot(arr,0,nums.size()-1);
11        return ans;
12    }
13
14    void sot(vector<pair<int,int>>& nums,int s,int e){
15        if(s>=e){
16            return;
17        }
18        int mid=(s+e)/2;
19        sot(nums,s,mid);
20        sot(nums,mid+1,e);
21        merge(nums,s,mid,e);
22    }
23    void merge(vector<pair<int,int>>& nums,int s,int mid,int e){
24        vector<pair<int,int>> left;
25        for(int i=s;i<=mid;i++){
26            left.push_back(nums[i]);
27        }
28        vector<pair<int,int>> right;
29        for(int i=mid+1;i<=e;i++){
30            right.push_back(nums[i]);
31        }
32        int l1=0;
33        int l2=0;
34        int u=0;
35        while(l1<left.size()&&l2<right.size()){
36            if(left[l1].first>right[l2].first){
37                u++;
38                l2++;
39            }else{
40                ans[left[l1].second]+=u;
41                l1++;
42            }
43        }
44        while(l1<left.size()){
45            ans[left[l1].second]+=u;
46            l1++;
47        }
48        l1=0;
49        l2=0;
50        while(l1<left.size()&&l2<right.size()){
51            if(left[l1].first>right[l2].first){
52                nums[s]=right[l2];
53                l2++;
54            }else{
55                nums[s]=left[l1];
56                l1++;
57            }
58            s++;
59        }
60        while(l1<left.size()){
61            nums[s]=left[l1];
62            l1++;
63            s++;
64        }
65        while(l2<right.size()){
66            nums[s]=right[l2];
67            l2++;
68            s++;
69        }
70    }
71};