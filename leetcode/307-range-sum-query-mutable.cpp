1class NumArray {
2public:
3    vector<int> sT;
4    vector<int> num;
5    NumArray(vector<int>& nums) {
6        sT=vector<int>(4*nums.size());
7        num=nums;
8        build(0,0,num.size()-1);
9    }
10
11    void build(int indx,int low,int high){
12        if(high==low){
13            sT[indx]=num[high];
14            return;
15        }
16        int mid=(low+high)/2;
17        build(2*indx+1,low,mid);
18        build(2*indx+2,mid+1,high);
19        sT[indx]=sT[2*indx+1]+sT[2*indx+2];
20    }
21    
22    void update(int index, int val) {
23        upd(0,0,num.size()-1,index,val);
24    }
25    void upd(int indx,int low,int high,int pos,int val){
26        if(low==high){
27            sT[indx]=val;
28            return;
29        }
30        int mid=(low+high)/2;
31        if(pos>=low&&pos<=mid) {
32            upd(2*indx+1,low,mid,pos,val);
33        }else{
34            upd(2*indx+2,mid+1,high,pos,val);
35        }
36        sT[indx]=sT[2*indx+1]+sT[2*indx+2];
37    }
38    
39    int sumRange(int left, int right) {
40        return sum(0,0,num.size()-1,left,right);
41    }
42    int sum(int indx,int low,int high,int left,int right){
43        if(low==high){
44            return sT[indx];
45        }
46        if(left<=low&&right>=high){
47            return sT[indx];
48        }
49        int mid=(low+high)/2;
50        int su=0;
51        if(left<=mid){
52            su=sum(2*indx+1,low,mid,left,right);
53        }
54        if(right>=(mid+1)){
55            su+=sum(2*indx+2,mid+1,high,left,right);
56        }
57        return su;
58    }
59};
60
61/**
62 * Your NumArray object will be instantiated and called as such:
63 * NumArray* obj = new NumArray(nums);
64 * obj->update(index,val);
65 * int param_2 = obj->sumRange(left,right);
66 */