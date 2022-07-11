
 // Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head) return head; 
        
        int n=0;
        ListNode *it = head;
        while(it) n++, it = it->next;
        k%=n;
        if(k%n==0) return head;
        
        it = head;
        for(int i=1; i<=n-k-1; i++)
            it = it->next;
        
        ListNode *newhead = it->next;
        it->next = NULL;
        
        it = newhead;
        while(it->next) it = it->next;
        it->next = head;
        
        return newhead;
    }
};
