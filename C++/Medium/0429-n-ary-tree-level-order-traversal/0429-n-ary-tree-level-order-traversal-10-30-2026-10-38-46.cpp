/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>res;
        if(root==nullptr) return res;
        while(!q.empty()){
            int N=q.size();
            vector<int>r;
            while(N--){
                auto curr=q.front();q.pop();
                r.push_back(curr->val);
                for(auto&z:curr->children){
                    if(z!=nullptr) q.push(z);
                }
            }
            res.push_back(r);
        }
        return res;
    }
};