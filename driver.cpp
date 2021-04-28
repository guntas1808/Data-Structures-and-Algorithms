#include <iostream>
#include "src/include/LinkedList.h"
#include "src/include/AlphabetTrie.h"
#include "src/include/BinarySearchTree.h"
#include "src/include/ArrayAlgorithms.h"

using namespace std;


int main(){
    // /*Linked List driver code*/
    
    // vector<int> vec1 = {10, 2, 54, 5, 7, 2, 0, 43};
    // vector<int> vec2 = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // // LinkedList list1(vec1);
    // LinkedList list2(vec2);
    // // list1.dump();
    // LinkedList list1 = list2;
    // list1.dump();
    // list2.reverse();
    // list1.dump();
    // list2.dump();

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


    // /*Binary Tree driver code*/
    // BinarySearchTree B;
    // vector<int> inp = {25, 15, 10, 4, 12, 22, 18, 24, 50, 35, 31, 44, 70, 66, 90};
    // vector<int> vec;
    // for(auto n : inp)
    //     B.insert(n);
    
    // B.level_order(vec);
    // cout<<"LEVELORDER---\n";
    // for(auto n : vec)
    //     cout<<" "<<n;
    // cout<<endl;
    // vec.clear();
    
    // B.in_order(vec);
    // cout<<"INORDER---\n";
    // for(auto n : vec)
    //     cout<<" "<<n;
    // cout<<endl;
    // vec.clear();
    
    // B.pre_order(vec);
    // cout<<"PREORDER---\n";
    // for(auto n : vec)
    //     cout<<" "<<n;
    // cout<<endl;
    // vec.clear();
    
    // B.post_order(vec);
    // cout<<"POSTORDER---\n";
    // for(auto n : vec)
    //     cout<<" "<<n;
    // cout<<endl;
    // vec.clear();
    // B.dump("full.dot");
    // B.remove(70);
    // B.remove(66);
    // B.remove(90);
    // B.remove(50);

    // // B.remove(50);
    // B.dump();


    /*Array driver code*/
    vector<int>vec = {145, 93};
    for(auto i:vec)
        cout<<" "<<i;
    cout<<endl;

    merge_sort(vec);

    for(auto i:vec)
        cout<<" "<<i;
    cout<<endl;

    return 0;
}