#include "include/BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree():
    root(nullptr)
    {}

BinarySearchTree::~BinarySearchTree(){
    if(root==nullptr)
        return;
    
    std::queue<BinaryTreeNode* > q;
    q.push(root);
    while (!q.empty()){
        int n = q.size();
        
        for (int i = 0; i < n; ++i){
            BinaryTreeNode* temp = q.front();
            q.pop();

            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);

            delete temp;
        }
        
    }
}

void BinarySearchTree::insert(int k){
    BinaryTreeNode* curr = root;
    while (true){
        if(curr==nullptr){
            root = new BinaryTreeNode(k);
            break;
        }
        if(curr->value > k){
            if(curr->left){
                curr = curr->left;
            }else{
                curr->left = new BinaryTreeNode(k);
                break;
            }
        }else if((curr->value < k)){
            if(curr->right){
                curr = curr->right;
            }else{
                curr->right = new BinaryTreeNode(k);
                break;
            }
        }else{
            break;
        }
    }
}

void BinarySearchTree::remove(int k){

}

void BinarySearchTree::in_order(std::vector<int>& vec){
    if(root==nullptr)
        return;
    
    std::stack<BinaryTreeNode*> st;
    // std::stack<int> stval;
    BinaryTreeNode* curr = root;

    while (true){
        // printstack(stval);
        if(curr->left){
            st.push(curr);
            // stval.push(curr->value);
            curr = curr->left;
        }else if(curr->right){
            vec.push_back(curr->value);
            curr = curr->right;
        }else{
            vec.push_back(curr->value);
            
            while(!st.empty() && st.top()->right==nullptr){
                curr = st.top();
                vec.push_back(curr->value);
                st.pop();
                // stval.pop();
            }
            
            if(st.empty())
                break;
            
            curr = st.top();
            vec.push_back(curr->value);
            
            curr = curr->right;
            // stval.pop();
            st.pop();
        }
        // printstack(stval);
        
        // for(int n: vec)
        //     std::cout<<" "<<n;

        // std::cout<<"   CURR = "<<curr->value<<std::endl;
        // std::cout<<std::endl;
        
    }
}

void BinarySearchTree::pre_order(std::vector<int>& vec){
    std::stack<BinaryTreeNode*> st;
    // std::stack<int> stval;
    
    BinaryTreeNode* curr = root;

    while (true){
        // printstack(stval);

        vec.push_back(curr->value);
        if(curr->left && curr->right){
            st.push(curr->right);
            // stval.push(curr->right->value);
            
            curr = curr->left;
        }else if(curr->right){
            curr = curr->right;
        }else{
            if(st.empty())
                break;
            
            curr = st.top();
            st.pop();
            // stval.pop();
        }
    }
}

void BinarySearchTree::post_order(std::vector<int>& vec){


}

void BinarySearchTree::level_order(std::vector<int>& vec){
    std::queue<BinaryTreeNode* > q;
    q.push(root);
    while (!q.empty()){
        int n = q.size();
        
        for (int i = 0; i < n; ++i){
            BinaryTreeNode* temp = q.front();
            q.pop();
            
            vec.push_back(temp->value);

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        
    }
}

void BinarySearchTree::dump(std::ofstream* fout){
    if(root==nullptr)
        return;
    
    if(fout==nullptr){
        fout = new std::ofstream;
        fout->open("binary_tree_dump.dot", std::ios::out);
    }
    (*fout)<<"digraph G {"<<std::endl;
    
    std::queue<BinaryTreeNode* > q;
    q.push(root);
    (*fout)<<"    \""<<root->value<<"\" ;"<<std::endl;
            
    while (!q.empty()){
        int n = q.size();
        
        for (int i = 0; i < n; ++i){
            BinaryTreeNode* temp = q.front();
            q.pop();
                
            if(temp->left){
                (*fout)<<"    \""<<temp->value<<"\" -> \""<<temp->left->value<<"\" ;"<<std::endl;
                q.push(temp->left);
            }
            if(temp->right){
                (*fout)<<"    \""<<temp->value<<"\" -> \""<<temp->right->value<<"\" ;"<<std::endl;
                q.push(temp->right);
            }
        }
        
    }

    (*fout)<<"}"<<std::endl;
}

void BinarySearchTree::printstack(std::stack<int>& st){
    std::stack<int> temp;
    std::cout<<"------";
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    
    while (!temp.empty())
    {
        st.push(temp.top());
        std::cout<<" "<<temp.top();
        temp.pop();
    }
    std::cout<<std::endl;
}