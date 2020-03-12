#include "proj5.hpp"
#include "edge.hpp"
#include "MyPriorityQueue.hpp"
#include <iostream>
#include <random>

using namespace std;

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
    vector<vector<unsigned>> graph = {
        { 0, 12, 12, 13, 17, 9, 7, 14, 3, 17},
        { 12, 0, 8, 8, 8, 18, 19, 5, 15, 8},
        { 12, 8, 0, 12, 15, 19, 17, 12, 9, 8},
        { 13, 8, 12, 0, 6, 15, 14, 3, 10, 4},
        { 17, 8, 15, 6, 0, 21, 19, 3, 14, 10},
        { 9, 18, 19, 15, 21, 0, 11, 18, 10, 11},
        { 7, 19, 17, 14, 19, 11, 0, 17, 10, 18},
        { 14, 5, 12, 3, 3, 18, 17, 0, 11, 7},
        { 3, 15, 9, 10, 14, 10, 10, 11, 0, 14},
        { 17, 8, 8, 4, 10, 11, 18, 7, 14, 0}
    };
    
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
