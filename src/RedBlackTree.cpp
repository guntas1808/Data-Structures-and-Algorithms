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