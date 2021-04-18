#include <vector>
#include <iostream>
#include <fstream>

 struct TrieNode{
     TrieNode():
        present(false),
        child(std::vector<struct TrieNode*>(26, nullptr))
        {}
    
    struct TrieNode* at(char c){
        if(c<'a' || c>'z'){
            std::cerr<<"INVALID INDEX (Must be a character a-z)"<<std::endl;
            return nullptr;
        }
        return child[c-'a'];
    }
     
     bool present;
     std::vector<struct TrieNode*> child;
 }typedef TrieNode;
 
class AlphabetTrie{

public:
    AlphabetTrie();
    
    AlphabetTrie(std::vector<std::string>& input);

    AlphabetTrie(std::string filepath);

    void insert(std::string word);

    void remove(std::string word);

    bool contains(std::string word);
    
    void delete_subtrie(TrieNode* arg_root);

    ~AlphabetTrie();

private:

    TrieNode* root;
};
