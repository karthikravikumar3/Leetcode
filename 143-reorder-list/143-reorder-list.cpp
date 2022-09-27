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
    void reorderList(ListNode* head) {
        if(!head||!head->next||!head->next->next){
            return;
        }
        stack<ListNode*> st;
        ListNode* h = head;
        int siz=0;
        while(h!=NULL){
            st.push(h);
            h=h->next;
            siz++;
        }
        ListNode* t= head;
        for(int i=0;i<siz/2;i++){
            ListNode* j = st.top();
            st.pop();
            j->next = t->next;
            t->next=j;
            t=t->next->next;
        }
        t->next=NULL;
        //j->next=NULL;
        //return head;
    }
};