/*
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
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode *temp=head;
        if(temp==nullptr||head==nullptr){
            return true;
        }
        while(temp!=nullptr){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        int x;
        while(temp!=nullptr&&!st.empty()){
            x=st.top();
            st.pop();
            if(x==temp->val){
                temp=temp->next;
                continue;
            }
            else{
                return false;
            }
        }  
        if (temp != nullptr || !st.empty()) {
            return false;
        }
        return true;
    }
};