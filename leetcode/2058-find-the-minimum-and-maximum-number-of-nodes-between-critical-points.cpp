1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
14        ListNode* pre=head;
15        head=head->next;
16        vector<int> a;
17        int u=1;
18        while(head->next!=nullptr){
19            if((pre->val<head->val&&head->val>head->next->val)||(pre->val>head->val&&head->val<head->next->val)){
20                a.push_back(u);
21            }
22            u++;
23            pre=head;
24            head=head->next;
25        }
26        if(a.size()<2){
27            return {-1,-1};
28        }
29        vector<int> ans(2,INT_MAX);
30        for(int i=1;i<a.size();i++){
31            ans[0]=min(ans[0],a[i]-a[i-1]);
32            
33        }
34        ans[1]=a.back()-a.front();
35        return ans;
36    }
37};