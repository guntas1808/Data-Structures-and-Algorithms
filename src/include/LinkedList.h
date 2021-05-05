#include <vector>

struct LLNode{
    LLNode(int val=0, struct LLNode* next_ptr=nullptr):
        value(val),
        next(next_ptr)
        {}
    
    int value;
    struct LLNode* next;
}typedef LLNode;

class LinkedList{

public:
    LinkedList();

    LinkedList(int input[], int size);

    LinkedList(std::vector<int>& vec);

    LinkedList(const LinkedList& arg_list);
    
    ~LinkedList();

    /**
     * @return head of the linked list
    */
    LLNode* head();

    /**
     * @return tail of the linked list
    */
    LLNode* tail();

    /**
     * @return number of nodes in the linked list
    */
    int size();

    /**
     * Search for an node in the linked list
     * @param val value to be searched for
     * @return true if exists, false otherwise
    */
    bool find(int val);
    
    /**
     * Insert new node into the linked list
     * @param val
     * @param pos position of insertion.
     * @return true if insertion is succesful or node
     * with the value already exists, false otherwise.
    */
    bool insert(int val, int pos=0);

    /**
     * Append new element at the end of the linked list
     * @param val value of the node
     * @return true on successful append, false otherwise
    */ 
    bool append(int val);

    /**
     * Rotate the linked list clockwise by n nodes
     * @param n
    */
    void rotate(int n);

    /**
     * Reverse the linked list
    */
    void reverse();

    /**
     * Reverse the linked list in groups of k nodes
     * @param k
    */
    void reverse_in_groups(int n);

    /**
     * Sort the linked list using merge sort algorithm
    */
    void merge_sort();

    /**
     * Dump the linked list to stdout
    */
    void dump();

private:
    LLNode* head_ptr;
    LLNode* tail_ptr;
    int size_val;

    /**
     * Merge two sorted chunks ofthe linked list
     * @param start
     * @param mid 
     * @param end
    */
    void merge(LLNode* start, LLNode* mid, LLNode* end);

    /**
     * Helper method for merge sort
     * @param start
     * @param end
    */
    void merge_sort_util(LLNode* start, LLNode* end);
};
