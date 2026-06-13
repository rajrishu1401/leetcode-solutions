1class Solution {
2public:
3    int ans=0;
4    bool canVisitAllRooms(vector<vector<int>>& rooms) {
5        vector<bool> v(rooms.size());
6        hlp(rooms,0,v);
7        if(ans==rooms.size()){
8            return true;
9        }
10        return false;
11    }
12    void hlp(vector<vector<int>>& rooms,int i,vector<bool>& v){
13        if(v[i]){
14            return;
15        }
16        ans++;
17        v[i]=true;
18        for(int j:rooms[i]){
19            hlp(rooms,j,v);
20        }
21    }
22};