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

    LLNode* head();

    LLNode* tail();

    int size();

    bool find(int val);
    
    bool insert(int val, int pos=0);

    bool append(int val);

    void rotate(int n);

    void reverse();

    void reverse_in_groups(int n);

    void merge_sort();

    void dump();

// private:
    LLNode* head_ptr;
    LLNode* tail_ptr;
    int size_val;

    void merge(LLNode* start, LLNode* mid, LLNode* end);

    void merge_sort_util(LLNode* start, LLNode* end);
};
