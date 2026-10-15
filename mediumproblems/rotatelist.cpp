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
    ListNode* rotateRight(ListNode* head, int k) {

        //SHORT CIRCUIT AND EDGE CASES//
        
        if(!k || !head ){
            return head;
        }
        if(!head->next){
            return head;
        }
        if(!head->next->next){
            if(k%2 == 0){
                return head;
            }
            else{
                ListNode* sec = head->next;
                sec->next = head;
                head->next = nullptr;
                return sec; 
            }
        }
        

           ///-----///


       
        ListNode* counter = head;
        int N = 0;
        while(counter){
            N++;
            counter = counter->next;
        }
        k = k%N; //optimising k

       //three pointers, one leads, one lags and another keeps recalculating the beginning. 
       ListNode* lag = head;
       ListNode* lead = head->next;
       ListNode* begin = head;
       
       //advance lag and lead till lead is in last element.
       while(lead->next){
        lead = lead->next;
        lag = lag->next;

       }
       for(int i = 0; i<k; i++){
        lead->next = begin;
        lag->next = NULL;
        begin = lead;
        lead = lag;
        lag = begin;

        while(lag->next != lead){
            lag = lag->next;

       }   
       // places the final node at the beginning, changes begin variable to the beginning, new lead is the lag, lag is set to beginning initially and then moved to the element before lead, for k times.
     

    }
     return begin;  
    }
};
