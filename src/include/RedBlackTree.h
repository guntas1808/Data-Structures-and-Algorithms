#include <vector>
#include <string>
#include <fstream>

struct RedBlackNode{
    RedBlackNode(int k):
        value(k),
        parent(nullptr),
        left(nullptr),
        right(nullptr),
        is_red(false)
        {}
    
    int value;
    struct RedBlackNode* parent;
    struct RedBlackNode* left;
    struct RedBlackNode* right;
    bool is_red;

}typedef RedBlackNode;


class RedBlackTree{

public:

    RedBlackTree();
    
    ~RedBlackTree();

    void left_rotate(RedBlackNode* arg_node);

    void right_rotate(RedBlackNode* arg_node);

    void insert(int k);

    void remove(int k);

    void in_order(std::vector<int>& vec);

    void pre_order(std::vector<int>& vec);
    
    void post_order(std::vector<int>& vec);
    
    void level_order(std::vector<int>& vec);

    void dump(std::string filepath);

    void dump(std::ofstream* fout=nullptr);

private:
    RedBlackNode* root;
};
