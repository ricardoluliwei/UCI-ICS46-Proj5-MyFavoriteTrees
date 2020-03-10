#include "proj5.hpp"
#include "edge.hpp"
#include "MyPriorityQueue.hpp"
#include <iostream>

using namespace std;

void testSink(){
    MyPriorityQueue<int> a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(6);
    a.extractMin();
    cout << a.min() << endl;
}

int main()
{
    testSink();
	return 0;
}
