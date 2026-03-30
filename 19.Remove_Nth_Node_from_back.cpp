#include <iostream>
#include <vector>
using namespace std;
 
 
 //Definition for singly-linked list.
  struct ListNode
{
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    public:

        void AddNodes(ListNode* head, vector<int> values)
        {
            ListNode* current = head;
            for(int i=0; i<values.size(); i++)
            {
                current->next = new ListNode(values[i],nullptr);
                current = current->next;
            }
        }

        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            //Start both ptrs at dummy
            //Advance fast by n+1
            //Iterate till fast == nullptr
            //Delete slow->next          
            
            ListNode dummy(0,head);
            ListNode* slow = &dummy;
            ListNode* fast = &dummy;
    
            for(int i=0; i<=n; i++)
            {
                fast = fast->next;
            }
    
            while(fast != nullptr)
            {
                fast = fast->next;
                slow = slow->next;
            }
    
            ListNode* toDelete = slow->next;
            slow->next = slow->next->next;
            delete toDelete;
            
            return dummy.next;
        }
    };

    int main()
    {
        Solution s;
        vector<int> v1 = {2,3,4,5};
        int n1 = 2;

        vector<int> v2;
        int n2 = 1;


        ListNode* head1 = new ListNode(1);
        ListNode* head2 = new ListNode(1);

        s.AddNodes(head1,v1);
        s.AddNodes(head2,v2);
    
        ListNode* result1 = s.removeNthFromEnd(head1, n1);
        ListNode* result2 = s.removeNthFromEnd(head2, n2);
    
        while(result1 != nullptr)
        {
            cout << result1->val << " ";
            result1 = result1->next;
            if(result1 == nullptr)
            {
                cout << "NULLPTR" << endl;
            }
        }

        cout << endl;
        
        while(result2 != nullptr)
        {
            cout << result2->val << " ";
            result2 = result2->next;
            if(result2 == nullptr)
            {
                cout << "NULLPTR" << endl;
            }
        }

        return 0;
    }

       // We will not get the length
            // slow ptr ------(n+1)(index = n)-----> fast pointer
            // dummy      1        2        3        4          5         nullptr
            // slow                        fast
            //           slow                       fast    
            //                    slow                         fast 
            //                            (slow)<-predecessor           (fast)
    
            //dummy       1        nullptr
            //(slow)<-predecessor  (fast)