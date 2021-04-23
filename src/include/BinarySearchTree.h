#include<vector>
#include<fstream>
#include <stack>
#include <queue>

struct BinaryTreeNode{

    BinaryTreeNode(int k):
        value(k),
        left(nullptr),
        right(nullptr)
        {}
    
    int value;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;

}typedef BinaryTreeNode;


class BinarySearchTree{

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int k);

    void remove(int k);

    bool search(int k);

    void in_order(std::vector<int>& vec);

    void pre_order(std::vector<int>& vec);
    
    void post_order(std::vector<int>& vec);
    
    void level_order(std::vector<int>& vec);

    void dump(std::ofstream* fout=nullptr);

    void printstack(std::stack<int>& st);
private:
    BinaryTreeNode* root;

};