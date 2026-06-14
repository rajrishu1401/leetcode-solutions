1class Solution {
2public:
3    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
4        sort(intervals.begin(),intervals.end());
5        int ans=0;
6        int p=intervals[0][1];
7        for(int i=1;i<intervals.size();i++){
8            //cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
9            if(intervals[i][0]<p){
10                ans++;
11                p=min(p,intervals[i][1]);
12            }else{
13                p=intervals[i][1];
14            }
15
16        }
17        return ans;
18    }
19};