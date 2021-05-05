#include "include/RedBlackTree.h"

RedBlackTree::RedBlackTree(){
}

RedBlackTree::~RedBlackTree(){
}

void RedBlackTree::left_rotate(RedBlackNode* arg_node){
    RedBlackNode* temp = arg_node->right;
    if (temp==nullptr)
        return;

    if(temp->left)
        temp->left->parent = arg_node;
    temp->parent = arg_node->parent;
    arg_node->parent = temp;

    arg_node->right = temp->left;
    temp->left = arg_node;

    if(arg_node ==  root)
        root = temp;
    else if(arg_node == arg_node->parent->left)
        arg_node->parent->left = temp;
    else
        arg_node->parent->right = temp; 

}

void RedBlackTree::right_rotate(RedBlackNode* arg_node){
    RedBlackNode* temp = arg_node->left;
    if (temp==nullptr)
        return;

    if(temp->right)
        temp->right->parent = arg_node;
    temp->parent = arg_node->parent;
    arg_node->parent = temp;

    arg_node->left = temp->right;
    temp->right = arg_node;

    if(arg_node ==  root)
        root = temp;
    else if(arg_node == arg_node->parent->right)
        arg_node->parent->right = temp;
    else
        arg_node->parent->left = temp; 

}

void RedBlackTree::dump(std::string filepath){
    if(root==nullptr){
        std::cout<<"EMPTY TREE"<<std::endl;
        return;
    }
    
    std::ofstream* fout = new std::ofstream;
    fout->open(filepath, std::ios::out);
    
    return dump(fout);
}

void RedBlackTree::dump(std::ofstream* fout){
    if(root==nullptr){
        std::cout<<"EMPTY TREE"<<std::endl;
        return;
    }
    if(fout==nullptr){
        fout = new std::ofstream;
        fout->open("binary_tree_dump.dot", std::ios::out);
    }
    (*fout)<<"digraph G {"<<std::endl;
    
    std::queue<RedBlackNode* > q;
    q.push(root);
    if(root->is_red){
        (*fout)<<"    \""<<root->value<<"\" [style = \"filled\", fillcolor = red] ;"<<std::endl;
    }else{
        (*fout)<<"    \""<<root->value<<"\" [style = \"filled\", fillcolor = gray] ;"<<std::endl;
    }
    (*fout)<<"    \""<<root->value<<"\" ;"<<std::endl;        
    while (!q.empty()){
        int n = q.size();
        
        for (int i = 0; i < n; ++i){
            RedBlackNode* temp = q.front();
            q.pop();
                
            if(temp->left){
                if(temp->left->is_red){
                    (*fout)<<"    \""<<temp->left->value<<"\" [style = \"filled\", fillcolor = red] ;"<<std::endl;
                }else{
                    (*fout)<<"    \""<<temp->left->value<<"\" [style = \"filled\", fillcolor = gray] ;"<<std::endl;
                }

                (*fout)<<"    \""<<temp->value<<"\" -> \""<<temp->left->value<<"\" ;"<<std::endl;
                q.push(temp->left);
            }
            if(temp->right){
                if(temp->right->is_red){
                    (*fout)<<"    \""<<temp->left->value<<"\" [style = \"filled\", fillcolor = red] ;"<<std::endl;
                }else{
                    (*fout)<<"    \""<<temp->left->value<<"\" [style = \"filled\", fillcolor = gray] ;"<<std::endl;
                }

                (*fout)<<"    \""<<temp->value<<"\" -> \""<<temp->right->value<<"\" ;"<<std::endl;
                q.push(temp->right);
            }
        }
        
    }

    (*fout)<<"}"<<std::endl;
}