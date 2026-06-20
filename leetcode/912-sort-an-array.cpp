1class Solution {
2public:
3    vector<int> sortArray(vector<int>& nums) {
4        sort(nums,0,nums.size()-1);
5        return nums;
6    }
7
8    void sort(vector<int>& num,int i, int j){
9        if(i==j){
10            return;
11        }
12        int mid=(i+j)/2;
13        sort(num,i,mid);
14        sort(num,mid+1,j);
15        merge(num,i,mid,j);
16    }
17    void merge(vector<int>& num,int i,int mid, int j){
18        stack<int> l;
19        stack<int> r;
20        for(int u=mid;u>=i;u--){
21            l.push(num[u]);
22        }
23        for(int u=j;u>mid;u--){
24            r.push(num[u]);
25        }
26        while(!l.empty()&&!r.empty()){
27            if(l.top()>r.top()){
28                num[i]=r.top();
29                r.pop();
30            }else{
31                num[i]=l.top();
32                l.pop();
33            }
34            i++;
35        }
36        while(!l.empty()){
37            num[i]=l.top();
38            l.pop();
39            i++;
40        }
41        while(!r.empty()){
42            num[i]=r.top();
43            r.pop();
44            i++;
45        }
46    }
47};