#include "include/AlphabetTrie.h"

unsigned long long AlphabetTrie::node_id = 1;

AlphabetTrie::AlphabetTrie():
    root(new TrieNode)
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
    
    try
    {
        fin.open(filepath, std::ios::in);
        if(!fin.is_open()){   
            std::cerr << "\nERROR : Invalid filepath (Check input filepath for AlphabetTrie)\n" << '\n';
            throw filepath;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
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
    if(root==nullptr)
        root = new TrieNode;
    
    TrieNode* curr = root;
    for(auto c: word){
        if(curr->at(c) == nullptr)
            curr->child[c-'a'] = new TrieNode();
        curr = curr->at(c);
    }
    curr->present = true;
}

void AlphabetTrie::remove(std::string word){
    
    remove_util(root, word);
    
    if(root == nullptr)
        root = new TrieNode;
}

TrieNode* AlphabetTrie::remove_util(TrieNode* root, std::string word){
    if(root==NULL)
        return NULL;
    
    if(word == ""){
        root->present=false;
        for(char c='a'; c<='z'; ++c){
            if(root->at(c))
                return root;
        }
        delete root;
        return NULL;
    }

    root->child[word[0]-'a'] =  remove_util(root->at(word[0]), word.substr(1));
    
    for(char c='a'; c<='z'; ++c){
        if(root->at(c))
            return root;
    }
    
    delete root;
    return NULL;
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

void AlphabetTrie::dump_trie_structure(std::ofstream* fout){
    if(fout==nullptr){
        fout = new std::ofstream;
        fout->open("trie_dump_1.dot", std::ios::out);
    }
    (*fout)<<"digraph G {"<<std::endl;
    (*fout)<<"    0 [label = \"ROOT\"];"<<std::endl;
    
    for(char c='a'; c<='z'; ++c){
        if(root->at(c)){
            dump_trie_structure_util(root->at(c), c, fout, 0);
        }
    }
    (*fout)<<"}"<<std::endl;
}

void AlphabetTrie::dump_trie_structure_util(TrieNode* root, char label, std::ofstream* fout, unsigned long long parent_id){
    if(root==NULL)
        return;
    
    unsigned long long my_id = node_id++;
    
    (*fout)<<"    "<<my_id<<" [label = \""<<label<<" , "<<root->present<<"\"];"<<std::endl;
    (*fout)<<"    "<<parent_id<<" -> "<<my_id<<";"<<std::endl;
    
    for(char c='a'; c<='z'; ++c){
        if(root->at(c)){
            dump_trie_structure_util(root->at(c), c, fout, my_id);
        }
    }
}
