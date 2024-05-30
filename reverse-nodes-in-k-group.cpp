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
ListNode* reverseLinkedList(ListNode *head){
    ListNode* temp = head;
    ListNode* prev = nullptr;  
        while(temp != nullptr){  
        ListNode* front = temp->next;  
        temp->next = prev;  
        prev = temp;  
        temp = front; 
   }
   return prev;  
}
    ListNode *getkthnode(ListNode *temp,int k){
        while(temp!=nullptr&&k>1){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        ListNode *prevlast=nullptr;
        while(temp!=nullptr){
            ListNode *kthnode=getkthnode(temp,k);
            if(kthnode==nullptr){
                if(prevlast)
                    prevlast->next=temp;
                    break;
                
            }
                ListNode *nextnode=kthnode->next;
                kthnode->next=nullptr;
                reverseLinkedList(temp);
                if(temp==head){
                    head=kthnode;
                }
                else{
                    prevlast->next=kthnode;
                }
                prevlast=temp;
                temp=nextnode;
        }
        return head;
    }
};
