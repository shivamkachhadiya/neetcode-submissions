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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>ans;
        ListNode* temp1=list1;

        while(temp1!=NULL){
            ans.push_back(temp1->val);
            temp1=temp1->next;
        }

        ListNode* temp2=list2;
        while(temp2!=NULL){
            ans.push_back(temp2->val);
            temp2=temp2->next;
        }

        sort(ans.begin(),ans.end());

        ListNode* dummyLinklist=new ListNode(0);
        ListNode* dummy_temp=dummyLinklist;
        int n=ans.size();
        int i=0;
        while(i<n){
            dummy_temp->next=new ListNode(ans[i]);
            dummy_temp=dummy_temp->next;
            i++;
        }

        return dummyLinklist->next;

    }
};
