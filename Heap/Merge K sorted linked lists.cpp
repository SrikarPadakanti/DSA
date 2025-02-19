Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list, then return the head of the merged linked list.

Examples:

Input: arr[] = [1 -> 2 -> 3, 4 -> 5, 5 -> 6, 7 -> 8]
Output: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6 -> 7 -> 8
Explanation:
The arr[] has 4 sorted linked list of size 3, 2, 2, 2.
1st list: 1 -> 2-> 3
2nd list: 4 -> 5
3rd list: 5 -> 6
4th list: 7 -> 8
 
Input: arr[] = [1 -> 3, 8, 4 -> 5 -> 6]
Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
Explanation:
The arr[] has 3 sorted linked list of size 2, 3, 1.
1st list: 1 -> 3
2nd list: 8
3rd list: 4 -> 5 -> 6

Constraints
1 <= total no. of nodes <= 105
1 <= node->data <= 103


class Compare{
    public:
    bool operator() (Node* a, Node* b){
        return a->data > b->data;
    }
};
class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<Node*, vector<Node*>, Compare> pq;
        
        for(Node* head : arr){
            if(head != nullptr) pq.push(head);
        }
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        
        while(!pq.empty()){
            Node* top = pq.top();
            pq.pop();
            
            tail->next = top;
            tail = top;
            
            if(top->next != nullptr){
                pq.push(top->next);
            }
        }
        return dummy->next;
    }
};
