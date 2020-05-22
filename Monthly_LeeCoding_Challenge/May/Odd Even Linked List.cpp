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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* odd;
        ListNode* even;
        ListNode* o = head;
        ListNode* e = head->next;
        
        odd = o;
        even = e;
        
        while(e and e->next){
            //cout<<" i ";
            o->next = e->next;
            o = o->next;

            e->next = o->next;
            e = e->next;
        }
        
        o->next = even;
        
        return odd;
        
        
    }
};