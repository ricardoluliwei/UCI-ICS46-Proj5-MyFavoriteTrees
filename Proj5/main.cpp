#include "proj5.hpp"
#include "edge.hpp"
#include "MyPriorityQueue.cpp"
#include <iostream>
#include <random>

using namespace std;

void testPriorityQueue(){
    MyPriorityQueue<int> a;
    for (int i = 0; i < 10000; i++) {
        a.insert(rand() % 5000);
    }
    
    int max = -1;
    
    for (int i = 0; i < 10000; i++) {
        int head = a.min();
        if (head < max) {
            cout << "Error" << endl;
            return;
        }
        max = head;
        a.extractMin();
    }
    
    cout << a.isEmpty() << endl;
    cout << (a.size() == 0) << endl;
    cout << "Pass test" << endl;
}

int main()
{
    testPriorityQueue();
	return 0;
}
