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
    BinaryTreeNode* curr = root;
    BinaryTreeNode* pred = curr;
    bool is_right = false;
    
    while (curr){
        if(curr->value > k){
            pred = curr;
            curr = curr->left;
            is_right = false;
        }else if(curr->value < k) {
            pred = curr;
            curr = curr->right;
            is_right = true;
        }else{
            break;
        }
    }

    if(curr == nullptr)
        return;
    if(curr->right && curr->left){
        BinaryTreeNode* temp = curr->right;
        
        if(temp->left == nullptr){
            
            if(is_right)
                pred->right = temp;
            else
                pred->left = temp;
            temp->left = curr->left;
            
            delete curr;
        }else{
            BinaryTreeNode* temp_pred;
            std::cout<<"hello "<<temp->left<<std::endl;
                
            while (temp->left){
                temp_pred = temp;
                temp = temp->left;
            }
            
            temp_pred->left = temp->right;
            temp->right = curr->right;
            temp->left = curr->left;
            
            if(is_right)
                pred->right = temp;
            else
                pred->left = temp;
            
            delete curr;
        }

    }else if(curr->right){
        if(is_right)
            pred->right = curr->right;
        else
            pred->left = curr->right;
        
        delete curr;

    }else{
        if(is_right)
            pred->right = curr->left;
        else
            pred->left = curr->left;

        delete curr;

    }      
}

bool BinarySearchTree::search(int k){
    BinaryTreeNode* curr = root;
    
    while (curr){
        if(curr->value > k){
            curr = curr->left;
        }else if(curr->value < k){
            curr = curr->right;
        }else{
            return true;
        }
    }
    return false;
}

void BinarySearchTree::in_order(std::vector<int>& vec){
    if(root==nullptr)
        return;
    
    vec.clear();
    std::stack<BinaryTreeNode*> st;
    BinaryTreeNode* curr = root;

    while (true){

        if(curr->left){
            st.push(curr);
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
            }
            
            if(st.empty())
                break;
            
            curr = st.top();
            vec.push_back(curr->value);
            
            curr = curr->right;
            st.pop();
        }
    }
}

void BinarySearchTree::pre_order(std::vector<int>& vec){
    if(root==nullptr)
        return;
    
    vec.clear();
    std::stack<BinaryTreeNode*> st;
    BinaryTreeNode* curr = root;

    while (true){

        vec.push_back(curr->value);
        if(curr->left && curr->right){
            st.push(curr->right);
            curr = curr->left;

        }else if(curr->right){
            curr = curr->right;
        
        }else if(curr->left){
            curr = curr->left;
        
        }else{
            if(st.empty())
                break;
            
            curr = st.top();
            st.pop();
        }
    }
}

void BinarySearchTree::post_order(std::vector<int>& vec){
    if(root==nullptr)
        return;
    
    vec.clear();
    std::stack<BinaryTreeNode*> st;
    BinaryTreeNode* curr = root;

    while (true){
        if(curr->left && curr->right){
            st.push(curr->right);
            st.push(curr);
            curr = curr->left;

        }else if(curr->right){
            st.push(curr);
            curr = curr->right;
        
        }else if(curr->left){
            st.push(curr);
            curr = curr->left;
        
        }else{
            vec.push_back(curr->value);

            BinaryTreeNode* temp = st.top();
            st.pop();
            if(st.top()==temp->right){
                curr  = st.top();
                st.pop();
                st.push(temp);
            }else{
                while(!st.empty() && st.top()!=temp->right){
                    vec.push_back(temp->value);
                    temp = st.top();
                    st.pop();
                }
                
                if(st.empty()){
                    vec.push_back(temp->value);
                    break;
                }

                curr  = st.top();
                st.pop();
                st.push(temp);
            }
        }
    }
}

void BinarySearchTree::level_order(std::vector<int>& vec){
    if(root==nullptr)
        return;
    
    vec.clear();
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

void BinarySearchTree::dump(std::string filepath){
    if(root==nullptr){
        std::cout<<"EMPTY TREE"<<std::endl;
        return;
    }
    
    std::ofstream* fout = new std::ofstream;
    fout->open(filepath, std::ios::out);
    
    return dump(fout);
}

void BinarySearchTree::dump(std::ofstream* fout){
    if(root==nullptr){
        std::cout<<"EMPTY TREE"<<std::endl;
        return;
    }
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