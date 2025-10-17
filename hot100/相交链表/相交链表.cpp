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
        ListNode *A = headA;
        ListNode* B = headB;
        int alen = 1;
        int blen = 1;
        while(A->next){++alen; A=A->next;}
        while(B->next){++blen;B=B->next;}
        A=headA;
        B=headB;
        if(alen>blen){
            int diff = alen - blen;
            for(int i = 0; i < diff ; ++i){A=A->next;}
        }
        else{
            int diff = blen - alen;
            for(int i = 0; i < diff; ++i){B=B->next;}
        }
        
        while(A){
            if(A==B) return A;
            if(A->next == NULL) break;
            A=A->next;
            B=B->next;
        }
        return NULL;
        
    }
};