1class Solution {
2public:
3    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
4        unordered_map<double,long long> m;
5        for(vector<int> i:rectangles){
6            double j=(double)i[0]/i[1];
7            m[j]++;
8        }
9        long long ans=0;
10        for(auto t:m){
11            ans+=((t.second*(t.second-1))/2);
12        }
13        return ans;
14    }
15};