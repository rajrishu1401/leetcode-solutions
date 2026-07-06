1class Solution {
2public:
3    int removeCoveredIntervals(vector<vector<int>>& intervals) {
4        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>& b){
5            if(a[0]==b[0]){
6                return a[1]>b[1];
7            }
8            return a[0]<b[0];
9        });
10        int ans=intervals.size();
11        int y=intervals[0][1];
12        for(int i=1;i<intervals.size();i++){
13            if(intervals[i][1]<=y){
14                ans--;
15            }else{
16                y=intervals[i][1];
17            }
18        }
19        return ans;
20    }
21};