1class Solution {
2public:
3    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
4        vector<int> d(n);
5        for(vector<int> i:bookings){
6            d[i[0]-1]+=i[2];
7            if((i[1])<n) d[i[1]]-=i[2];
8        }
9        for(int i=1;i<n;i++){
10            d[i]+=d[i-1];
11        }
12        return d;
13    }
14};