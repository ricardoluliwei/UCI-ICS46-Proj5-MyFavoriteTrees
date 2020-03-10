#ifndef __PROJ5_PRIORITY_QUEUE_HPP
#define __PROJ5_PRIORITY_QUEUE_HPP

#include "runtimeexcept.hpp"
#include <vector>

class PriorityQueueEmptyException : public RuntimeException 
{
public:
	PriorityQueueEmptyException(const std::string & err) : RuntimeException(err) {}
};



template<typename Object>
class MyPriorityQueue
{
private:
    std::vector<Object> minHeap;
    void swap(size_t i, size_t j); //swap two element
    void sink(size_t index); //sink the element at index
    void floating(size_t index); //float the element at index
    
public:

    MyPriorityQueue();
    ~MyPriorityQueue();

    size_t size() const noexcept;
	bool isEmpty() const noexcept;

	void insert(const Object & elem);


	// Note:  no non-const version of this one.  This is on purpose because
	// the interior contents should not be able to be modified due to the
	// heap property.  This isn't true of all priority queues but 
	// for this project, we will do this.
	// min and extractMin should throw PriorityQueueEmptyException if the queue is empty.
	const Object & min() const; 

	void extractMin(); 

};



template<typename Object>
MyPriorityQueue<Object>::MyPriorityQueue(){
    minHeap.push_back(Object());
}



template<typename Object>
MyPriorityQueue<Object>::~MyPriorityQueue(){
    minHeap.clear();
}



template<typename Object>
size_t MyPriorityQueue<Object>::size() const noexcept
{
    return minHeap.size() - 1;
}



template<typename Object>
bool MyPriorityQueue<Object>::isEmpty() const noexcept
{
    return minHeap.size() == 1;
}



template<typename Object>
void MyPriorityQueue<Object>::insert(const Object & elem)
{
    minHeap.push_back(elem);
    floating(size());
}



template<typename Object>
const Object & MyPriorityQueue<Object>::min() const
{
    if (isEmpty())
        throw PriorityQueueEmptyException("Priority Queue is empty!");
    
    return minHeap[1];
}



template<typename Object>
void MyPriorityQueue<Object>::extractMin()
{
    if (isEmpty())
        throw PriorityQueueEmptyException("Priority Queue is empty!");
    
    minHeap[1] = minHeap[size()];
    minHeap.pop_back();
    sink(1);
}



template<typename Object>
void MyPriorityQueue<Object>::swap(size_t i, size_t j)
{
    Object temp = minHeap[i];
    minHeap[i] = minHeap[j];
    minHeap[j] = temp;
    return;
    
}


//sink the element minHeap[index]
template<typename Object>
void MyPriorityQueue<Object>::sink(size_t index){
    if (index * 2 > size())
        return;
    
    size_t smaller = index * 2;
    
    if (index * 2 + 1 <= size() )
        smaller = minHeap[index * 2] < minHeap[index * 2 + 1] ? index * 2 : index * 2 + 1;
    
    
    if (minHeap[index] > minHeap[smaller]) {
        swap(index, smaller);
        return sink(smaller);
    }
    
}



template<typename Object>
void MyPriorityQueue<Object>::floating(size_t index)
{
    if (size() == 1)
        return;
    
    for (size_t i = index; i > 1; i /= 2)
    {
        if (minHeap[i] < minHeap[i/2])
            swap(i, i/2);
        else
            break;
    }
    
}



#endif

