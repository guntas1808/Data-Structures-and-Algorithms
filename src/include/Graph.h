#include <vector>
#include <string>

struct AdjListNode{

    AdjListNode(int u, int weight = 1, AdjListNode* ptr = nullptr):
        vertex(u),
        weight(weight),
        next(ptr)
        {}

    int vertex;
    int weight;
    struct AdjListNode* next;
}typedef AdjListNode;

class Graph{
public:
    /**
     * Log all method calls and actions to stdout
    */
    bool VERBOSE = false;

    Graph(int arg_vertex_count = 0,bool is_directed = true);

    Graph(bool arg_is_directed);

    ~Graph();
    
    /**
     * Add a new edge to the graph between u and v.
     * (Directed from u to v in case of a directed graph)
     * @param u
     * @param v 
     * @param weight weight of the edge, default 1
    */
    bool add_edge(int u, int v, int weight = 1);

    /**
     * Add new nodes to the graph
     * @param n number of nodes to add to the graph 
     * @return true on successful adddition, false otherwise
    */
    bool add_node(int n);
    
    /**
     * Checks for a cycle in the graph using DFS traversal 
     * @return true if a cycle detected, false otherwise
    */
    bool has_cycle();

    /**
     * Dump the graph as a DOT script
     * @param filepath path to the file where the graph has to be dumped
    */
    void dump(std::string filepath = "graph_dump.dot");

private:
    unsigned long long vertex_count;
    std::vector<AdjListNode* > adjacency_list;
    bool is_directed;

    /**
     * Helper method for add_edge
    */
    bool add_edge_util(int u, int v, int weight);

    /**
     * Helper method for has_cycle
    */
    bool has_cycle_util(int u, std::vector<bool>& visited, std::vector<bool>& visiting);

};


/**
 * Generate a random graph
 * @param vertex_count number of vertices required in the graph
 * @param edge_count number of edges to be added
 * @param has_self_edges set to true if self edges are allowed
 * @param is_directed is the graph directed
 * @return reference to the Graph object (allocated on heap memory)
 * @note the returned object is allocated on the heap not on the stack
*/
Graph& generate_graph(int vertex_count,int edge_count, bool is_directed = true, std::vector<int> weight_params = {1,1}, bool has_self_edge = false);