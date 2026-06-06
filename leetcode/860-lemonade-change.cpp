1class Solution {
2public:
3    bool lemonadeChange(vector<int>& bills) {
4        int ar[]={0,0};
5        for(int i:bills){
6            if(i==10){
7                if(ar[0]==0){
8                    return false;
9                }else{
10                    ar[0]--;
11                    ar[1]++;
12                }
13            }else if(i==20){
14                if(ar[0]==0||(ar[1]==0&&ar[0]<3)){
15                    return false;
16                }else if(ar[1]!=0){
17                    ar[1]--;
18                    ar[0]--;
19                }else{
20                    ar[0]-=3;
21                }
22            }else{
23                ar[0]++;
24            }
25        }
26        return true;
27    }
28};