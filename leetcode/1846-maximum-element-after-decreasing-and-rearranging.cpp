1class Solution {
2public:
3    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
4        sort(arr.begin(),arr.end());
5        int u=0;
6        for(int i=0;i<arr.size();i++){
7            if(arr[i]<=u){
8                u=arr[i];
9            }else{
10                u++;
11            }
12        }
13        return u;
14    }
15};