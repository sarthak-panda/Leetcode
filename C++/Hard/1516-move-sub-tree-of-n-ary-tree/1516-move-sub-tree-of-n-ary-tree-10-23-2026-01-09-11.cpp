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

unordered_map<int,Node*>mp;

void dfs(Node* node,Node* par){
    mp[node->val]=par;
    for(auto&c:node->children){
        dfs(c,node);
    }
}

class Solution {
public:
    Node* moveSubTree(Node* root, Node* p, Node* q) {
        mp={}; dfs(root,nullptr);
        if(mp[p->val]==q) return root;//p is direct child [special case]
        bool case1=false;
        auto q_ances=mp[q->val];
        while(q_ances!=nullptr){
            if(q_ances==p){case1=true;break;}
            q_ances=mp[q_ances->val];
        }
        if(case1){
            //remove q from it's parent
            auto it=find(mp[q->val]->children.begin(),mp[q->val]->children.end(),q);
            mp[q->val]->children.erase(it);
            //replace p with q in p's par (if exists!)
            if(mp[p->val]!=nullptr){
                auto it1=find(mp[p->val]->children.begin(),mp[p->val]->children.end(),p);
                *it1=q;
            }
            //add to last child of q
            (q->children).push_back(p);
            if(mp[p->val]==nullptr) return q;
        }
        else{//case2 or case3
            //remove p from it's parent
            auto it=find(mp[p->val]->children.begin(),mp[p->val]->children.end(),p);
            mp[p->val]->children.erase(it);
            //add to last child of q
            (q->children).push_back(p);
        }
        return root;
    }
};