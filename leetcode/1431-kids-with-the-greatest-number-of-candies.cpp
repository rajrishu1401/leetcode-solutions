1class Solution {
2public:
3    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
4        int su=0;
5        for(int i:candies ){
6            su=max(su,i);
7        }
8        vector<bool> ans;
9        for(int i=0;i<candies.size();i++){
10            if(su<=(candies[i]+extraCandies)){
11                ans.push_back(true);
12            }else{
13                ans.push_back(false);
14            }
15        }
16        return ans;
17    }
18};