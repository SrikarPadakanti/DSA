-:GFG:-
Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target. 

Examples:

Input: root = [7, 3, 8, 2, 4, N, 9], target = 12
Output: True
Explanation: In the binary tree above, there are two nodes (8 and 4) that add up to 12.

Input: root = [9, 5, 10, 2, 6, N, 12], target = 23
Output: False
Explanation: In the binary tree above, there are no such two nodes exists that add up to 23.

Constraints:
1 ≤ Number of Nodes ≤ 105
1 ≤ target ≤ 106


class Solution {
  public:
    bool dfs(Node* root, unordered_set<int> &st, int target){
        if(root == nullptr) 
            return false;
        
        if(st.find(target - root->data) != st.end())
            return true;
        
        st.insert(root->data);
        return dfs(root->left, st, target) || dfs(root->right, st, target);
    }
    
    bool findTarget(Node *root, int target) {
        
        unordered_set<int> st;
        return dfs(root, st, target);
    }
};
