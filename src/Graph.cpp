#include "include/Graph.h"
#include <iostream>
#include <fstream>

Graph::Graph(int arg_vertex_count,bool arg_is_directed){
    vertex_count = arg_vertex_count;
    adjacency_list = std::vector<AdjListNode* >(arg_vertex_count, nullptr);
    is_directed = arg_is_directed;
}

Graph::Graph(bool arg_is_directed){
    vertex_count = 0;
    adjacency_list = std::vector<AdjListNode* >(vertex_count, nullptr);
    is_directed = arg_is_directed;
}

Graph::~Graph(){
    
    for(int u=0; u<vertex_count; ++u){
        AdjListNode* node = adjacency_list[u];
        AdjListNode* temp = node;
        while(node){
            temp = node->next;
            delete node;
            node = temp;
        }
    }
}

bool Graph::add_edge_util(int u, int v){
    AdjListNode* node = adjacency_list[u];
    AdjListNode* prev = node;
    while (node){
        if(node->vertex == v){
            if(VERBOSE)
                std::cout << "Edge "<<u<<" -> "<<v<<" already exists"<<std::endl;
            return true;
        }
        prev = node;
        node = node->next;
    }
    if(!node){
        if(prev){
            if(VERBOSE)
                std::cout << "Edge added "<<u<<" -> "<<v<<std::endl;
            prev->next = new AdjListNode(v);
        }else{
            if(VERBOSE)
                std::cout << "Edge added "<<u<<" -> "<<v<<std::endl;
            adjacency_list[u] = new AdjListNode(v);
        }
    }
    return true;
}

bool Graph::add_edge(int u, int v){
    if(u>=vertex_count || v>=vertex_count)
        return false;

    bool status = add_edge_util(u, v);

    if(!is_directed && u!=v)
        return (status && add_edge_util(v, u));
    
    return status;
}

bool Graph::add_node(int n){
    adjacency_list.push_back(nullptr);
    ++vertex_count;
    return true;
}

bool Graph::has_cycle_util(int u,std::vector<bool>& visited, std::vector<bool>& visiting){
    if(visited[u])
        return false;
    if(visiting[u])
        return true;
    
    visiting[u] = true;
    AdjListNode* node = adjacency_list[u];

    while (node){
        if(has_cycle_util(node->vertex, visited, visiting))
            return true;
    }

    visiting[u] = false;
    visited[u] = true;

    return false;
}

bool Graph::has_cycle(){
    std::vector<bool> visited(vertex_count, false);
    std::vector<bool> visiting(vertex_count, false);

    for(int u=0; u<vertex_count; ++u){
        if(has_cycle_util(u, visited, visiting))
            return true;
    }
    return false;
}

void Graph::dump(std::string filepath){
    std::ofstream fout;
    fout.open(filepath, std::ios::out);

    if(is_directed)
        fout << "digraph G{" << std::endl;
    else
        fout << "strict graph G{" << std::endl;
    
    for (int u = 0; u < vertex_count; u++){
        AdjListNode* node = adjacency_list[u];
        // fout << "\t" << u << " [ label = \"" <<  << "\"] ;" << std::endl;
        fout << "\t" << u << " ;" << std::endl;
        
        while (node){
            if(is_directed)
                fout<< "\t" << u << " -> " << node->vertex << " ;" <<std::endl;
            else
                fout<< "\t" << u << " -- " << node->vertex << " ;" <<std::endl;
            
            node = node->next;
        }
    }
    
    fout << "}" << std::endl;

}

Graph& generate_graph(int vertex_count,int edge_count, bool has_self_edge, bool is_directed){
    Graph* G = new Graph(vertex_count, is_directed);
    
    std::vector<std::pair<int, int>> edges;
    for(int u=0; u<vertex_count; ++u){
        for(int v=u+1; v<vertex_count; ++v){
            edges.push_back(std::make_pair(u, v));
            if(is_directed)
                edges.push_back(std::make_pair(v, u));
        }
    }

    if(has_self_edge)
        for (int u = 0; u < vertex_count; ++u)
            edges.push_back(std::make_pair(u, u));
        
    srand(time(0));
    
    for(int i=0; i< edge_count; ++i){
        if(edges.size()==0)
            break;
            
        int e = rand()%edges.size();
        
        G->add_edge(edges[e].first, edges[e].second);
        edges.erase(edges.begin()+e);
    }

    return *G;
}