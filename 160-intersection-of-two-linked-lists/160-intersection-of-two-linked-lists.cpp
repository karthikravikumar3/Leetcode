/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a1 =0;
        int a2=0;
        ListNode* h1 = headA;
        ListNode* h2 = headB;
        while(h1){
            a1++;
            h1=h1->next;
        }
              while(h2){
            a2++;
            h2=h2->next;
        }
       // cout<<"a1-"<<a1<<" a2-"<<a2<<endl;
        int k = abs(a1-a2);
        h1=headA;
        h2=headB;
        if(a1>a2){
            while(k){
                h1=h1->next;
                k--;
            }
        }else if(a1<a2){
            while(k){
            h2=h2->next;
                k--;
            }
        }
        while(h1){
            if(h1==h2){
                return h1;
            }
            h1=h1->next;
            h2=h2->next;
        }
        return h2;
    }
};