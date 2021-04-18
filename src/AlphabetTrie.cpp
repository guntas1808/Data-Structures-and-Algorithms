#include "include/AlphabetTrie.h"

AlphabetTrie::AlphabetTrie():
    root()
    {}

AlphabetTrie::AlphabetTrie(std::vector<std::string>& input){
    root = new TrieNode();
    TrieNode* curr;
    for(auto word:input){
        curr=root;
        for(auto c: word){
            if(curr->at(c) == nullptr)
                curr->child[c-'a'] = new TrieNode();
            curr = curr->at(c);
        }
        curr->present = true;
    }
}

AlphabetTrie::AlphabetTrie(std::string filepath){
    root = new TrieNode();
    
    std::ifstream fin;
    fin.open(filepath, std::ios::in);
    
    std::string word;
    TrieNode* curr;
    while(getline(fin, word)){
        curr=root;
        for(auto c: word){
            if(curr->at(c) == nullptr)
                curr->child[c-'a'] = new TrieNode();
            curr = curr->at(c);
        }
        curr->present = true;
    }
    
}

void AlphabetTrie::delete_subtrie(TrieNode* arg_root){
    if(arg_root==nullptr)
        return;
    for(auto next : arg_root->child){
        delete_subtrie(next);
    }
    delete arg_root;
}

AlphabetTrie::~AlphabetTrie(){
    delete_subtrie(root);
}

void AlphabetTrie::insert(std::string word){
    TrieNode* curr = root;
    for(auto c: word){
        if(curr->at(c) == nullptr)
            curr->child[c-'a'] = new TrieNode();
        curr = curr->at(c);
    }
    curr->present = true;
}

void AlphabetTrie::remove(std::string word){
    TrieNode* curr = root;
    for(auto c: word){
        if(curr->at(c) == nullptr)
            curr->child[c-'a'] = new TrieNode();
        curr = curr->at(c);
    }
    curr->present = false;
}

bool AlphabetTrie::contains(std::string word){
    TrieNode* curr = root;
    for(auto c:word){
        curr = curr->at(c);
        if(curr==nullptr)
            return false;
    }
    if(curr->present)
        return true;
    return false;
}
