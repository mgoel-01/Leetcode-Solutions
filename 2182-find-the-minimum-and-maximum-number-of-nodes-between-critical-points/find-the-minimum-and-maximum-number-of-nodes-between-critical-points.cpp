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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* cur=head->next;
        ListNode* ahead=cur->next;
        if(!ahead)return {-1,-1};
        vector<int> ans={INT_MAX,INT_MIN};
        vector<int> maxi(2,-1);
        vector<int> mini(2,-1);
        int pos=2;
        while(ahead){
            if(cur->val>prev->val && cur->val>ahead->val){
                if(maxi[0]==-1)maxi[0]=pos;
                else{
                    maxi[1]=pos;
                }
                if(mini[0]==-1)mini[0]=pos;
                else{
                    mini[1]=pos;
                    ans[0]=min(ans[0],mini[1]-mini[0]);
                    mini[0]=pos;
                }
            }
            if(cur->val<prev->val && cur->val<ahead->val){
                if(maxi[0]==-1)maxi[0]=pos;
                else{
                    maxi[1]=pos;
                }
                if(mini[0]==-1)mini[0]=pos;
                else{
                    mini[1]=pos;
                    ans[0]=min(ans[0],mini[1]-mini[0]);
                    mini[0]=pos;
                }
            }
            ahead=ahead->next;
            prev=prev->next;
            cur=cur->next;
            pos++;
        }
        if(mini[1]==-1)return {-1,-1};
        ans[1]=maxi[1]-maxi[0];
        return ans;
    }
};