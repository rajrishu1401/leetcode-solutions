1class Solution {
2public:
3    vector<int> twoSum(vector<int>& numbers, int target) {
4        for(int i=0;i<numbers.size();i++){
5            int u=target-numbers[i];
6            if(u==numbers[i]&&numbers[i+1]==u){
7                return {i+1,i+2};
8            }else{
9                int j=bsrh(numbers,u);
10                if(j>=0){
11                    return {i+1,j+1}; 
12                }
13            }
14        }
15        return {};
16    }
17    int bsrh(vector<int>& numbers,int t){
18        int s=0;
19        int e=numbers.size();
20        while(s<e){
21            int mid=(s+e)/2;
22            if(numbers[mid]==t){
23                return mid;
24            }else if(numbers[mid]>t){
25                e=mid;
26            }else{
27                s=mid+1;
28            }
29        }
30        return -1;
31    }
32
33};