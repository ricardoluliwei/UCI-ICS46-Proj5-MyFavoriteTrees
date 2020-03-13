#include "proj5.hpp"
#include "edge.hpp"
#include "MyPriorityQueue.hpp"
#include <iostream>
#include <random>

using namespace std;

vector<vector<unsigned>> createGraph(int size){
    vector<vector<unsigned>> graph;
    for (int i = 0; i < size; i++) {
        graph.push_back(vector<unsigned>(size));
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                int rd = rand() % size + 1;
                graph[i][j] = rd;
                graph[j][i] = rd;
            }
        }
    }
    return graph;
}

void printGraph(vector<vector<unsigned>> &graph){
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
    

void testPriorityQueue(){
    MyPriorityQueue<Edge> a;
    int size = 100000;
    assert(a.isEmpty());
    assert(a.size() == 0);
    
    for (int i = 0; i < size; i++) {
        a.insert(Edge(0,0,rand() % (size/2)));
    }
    
    assert(!a.isEmpty());
    assert(a.size() == size);
    
    Edge previous = a.min();
    
    for (int i = 0; i < size; i++) {
        assert(!(a.min() < previous));
        previous = a.min();
        a.extractMin();
    }
    
    assert(a.isEmpty());
    assert(a.size() == 0);
    
    cout << "Pass test" << endl;
}


void testMST(){
    vector<vector<unsigned>> graph = createGraph(5);
    printGraph(graph);
    
    vector<Edge> mst = compute_mst(graph);
    
    for (auto i : mst) {
        cout << i.pt1 << " --> " << i.pt2 << " : " << i.weight << endl;
    }
}

int main()
{
    testMST();
	return 0;
}
