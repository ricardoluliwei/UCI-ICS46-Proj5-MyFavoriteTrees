#include "proj5.hpp"
#include "MyPriorityQueue.hpp"


// As a reminder, for this project, edges have positive cost, g[i][j] = 0 means no edge.
std::vector<Edge> compute_mst(std::vector< std::vector<unsigned>> & graph)
{
    std::vector<Edge> mst;
    std::vector<bool> intree(graph.size());
    MyPriorityQueue<Edge> pq;
    intree[0] = true;
    
    for (int i = 1; i < graph.size(); i++) {
        intree[i] = false;
        if (graph[0][i] != 0)
            pq.insert(Edge(0,i,graph[0][i]));
    }
    
    for (int i = 0; i < graph.size() - 1; i++) {
        unsigned v = pq.min().pt2;
        if (!intree[v]) {
            mst.push_back(pq.min());
            pq.extractMin();
        } else {
            i--;
            pq.extractMin();
            continue;
        }
        
        intree[v] = true;
        for (int j = 0; j < graph.size(); j++) {
            if (!intree[j] && graph[v][j] != 0) {
                pq.insert(Edge(v,j,graph[v][j]));
            }
        }
    }
    
    return mst;
}


// Returns the cost of the edges in the given vector,
// This does not confirm that it is a MST at all.  
unsigned mstCost(const std::vector<Edge> & vE) 
{
    unsigned sum =0;
    for(auto e: vE)
    {
        sum += e.weight;
    }
    return sum;
}
