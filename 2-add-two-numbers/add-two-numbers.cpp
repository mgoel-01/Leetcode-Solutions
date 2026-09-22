/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* ans=nullptr;
       ListNode* tail=nullptr;
       ListNode* temp1=l1;
       ListNode* temp2=l2;
       int isCarry=0;
       while(temp1||temp2||isCarry){
        int sum=isCarry;
        if(temp1){
            sum+=temp1->val;
            temp1=temp1->next;
        }
        if(temp2){
            sum+=temp2->val;
            temp2=temp2->next;
        }
        isCarry=sum/10;
        sum=sum%10;
        ListNode* l=new ListNode(sum);
        if(ans!=NULL){
            tail->next=l;
            tail=l;
        }
        else{
            ans=l;
            tail=l;
        }        
       }
       return ans;
    }
};