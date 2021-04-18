#include <iostream>
#include "src/include/LinkedList.h"
#include "src/include/AlphabetTrie.h"

using namespace std;

int main(){
    // /*Linked List driver code*/
    // 
    // int arr[8] = {10, 2, 54, 5, 7, 2, 0, 43};
    // vector<int> vec = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // LinkedList new_list(vec);
    // cout<<new_list.size()<<endl;
    // new_list.dump();
    // new_list.merge_sort();
    // new_list.dump();

    AlphabetTrie trie("wordlist_10000.txt");
    trie.insert("guntasbruh");
    trie.insert("bruh");
    trie.remove("bruh");
    
    string word;
begin:
    cout<<"Enter word to search in trie : ";
    cin>>word;
    cout<<trie.contains(word)<<endl;
    goto begin;
    return 0;
}