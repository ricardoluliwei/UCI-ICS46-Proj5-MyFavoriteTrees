#include "proj5.hpp"
#include "edge.hpp"
#include "MyPriorityQueue.cpp"
#include <iostream>
#include <random>

using namespace std;

void testPriorityQueue(){
    MyPriorityQueue<int> a;
    int size = 100000;
    assert(a.isEmpty());
    assert(a.size() == 0);
    
    for (int i = 0; i < size; i++) {
        a.insert(rand() % (size/2));
    }
    
    assert(!a.isEmpty());
    assert(a.size() == size);
    
    int previous = -1;
    
    for (int i = 0; i < size; i++) {
        assert(previous <= a.min());
        previous = a.min();
        a.extractMin();
    }
    
    assert(a.isEmpty());
    assert(a.size() == 0);
    
    cout << "Pass test" << endl;
}

int main()
{
    testPriorityQueue();
	return 0;
}
