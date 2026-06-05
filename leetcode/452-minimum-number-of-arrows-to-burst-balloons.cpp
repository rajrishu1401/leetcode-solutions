1class Solution {
2public:
3    int findMinArrowShots(vector<vector<int>>& points) {
4        sort(points.begin(),points.end(),[](const vector<int>& a, const vector<int>& b){
5            return a[1]<b[1];
6        });
7        int u=points[0][1];
8        int ans=1;
9        for(int i=1;i<points.size();i++){
10            if(u>=points[i][0]){
11                continue;
12            }else{
13                ans++;
14                u=points[i][1];
15            }
16            
17        }
18        return ans;
19    }
20};