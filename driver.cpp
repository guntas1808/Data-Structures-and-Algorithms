#include <iostream>
#include "src/include/LinkedList.h"
#include "src/include/AlphabetTrie.h"

using namespace std;

int main(){
    /*Linked List driver code*/
    
    vector<int> vec1 = {10, 2, 54, 5, 7, 2, 0, 43};
    vector<int> vec2 = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // LinkedList list1(vec1);
    LinkedList list2(vec2);
    // list1.dump();
    LinkedList list1 = list2;
    list1.dump();
    list2.reverse();
    list1.dump();
    list2.dump();

    // cout<<new_list.size()<<endl;
    // new_list.dump();
    // new_list.rotate(15);
    // new_list.reverse();
    // cout<< new_list.find(10) <<endl;
    // new_list.dump();

//     /*Alphabet Trie driver code*/
//     AlphabetTrie trie("words.txt");
//     trie.insert("guntasbruh");
//     trie.insert("guntas");
//     trie.remove("guntas");
//     trie.dump_trie_words();
    
//     string word;
// begin:
//     cout<<"Enter word to search in trie : ";
//     cin>>word;
//     cout<<trie.contains(word)<<endl;
//     goto begin;
    return 0;
}