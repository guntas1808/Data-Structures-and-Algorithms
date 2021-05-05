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

    ~AlphabetTrie();

    /**
     * Insert a new word into the trie
     * @param word word to be inserted
    */
    void insert(std::string word);

    /**
     * Remove a word from the trie if present\
     * @param word to be removed 
    */
    void remove(std::string word);

    /**
     * Search for a word in the trie
     * @param word word to be searched
     * @return true if word present in the trie, false otherwise
    */
    bool contains(std::string word);
    
    /**
     * Delete the sub-trie roooted at given trie node
     * @param arg_root pointer to root of the sub-trie
    */
    void delete_subtrie(TrieNode* arg_root);

    /**
     * Dump the list of all the words present in the trie
     * @param fout pointer to a std:::ofstream object
    */
    void dump_trie_words(std::ofstream* fout = nullptr);

    /**
     * Dump the trie as a DOT script
     * @param fout pointer to a std::ofstream object
    */
    void dump_trie_structure(std::ofstream* fout = nullptr);

    
private:
    static unsigned long long node_id;

    TrieNode* root;

    /**
     * Helper method for remove
     * @param root current node
     * @param word the word to be searched further
     * @return current node if other words exist in the
     * subtrie rooted at current node, returns null otherwise.
    */TrieNode* remove_util(TrieNode* root, std::string word);

    /**
     * Helper method for dump_trie_words
     * @param root current node
     * @param fout pointer to std::ofstream object
     * @param word the word formed by the path covered till now
    */
    void dump_trie_words_util(TrieNode* root, std::ofstream* fout, std::string word);

    /**
     * Helper method for dump_trie_structure
     * @param root current node
     * @param label alphabet label of current node
     * @param fout pointer to std::ofstream object
     * @param parent_id id of the parent of current node
    */
    void dump_trie_structure_util(TrieNode* root, char label, std::ofstream* fout, unsigned long long parent_id);

};
