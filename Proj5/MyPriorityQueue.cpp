//
//  MyPriorityQueue.cpp
//  Proj5
//
//  Created by Ricardo on 3/9/20.
//  Copyright © 2020 Ricardo. All rights reserved.
//

#include "MyPriorityQueue.hpp"

template<typename Object>
MyPriorityQueue<Object>::MyPriorityQueue(){
    minHeap.push_back(new Object);
}


template<typename Object>
MyPriorityQueue<Object>::~MyPriorityQueue(){
    minHeap.clear();
}


template<typename Object>
size_t MyPriorityQueue<Object>::size() const noexcept
{
    return minHeap.size() - 1; // stub
}



template<typename Object>
bool MyPriorityQueue<Object>::isEmpty() const noexcept
{
    return minHeap.size() == 1; // stub
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
    if (isEmpty()){
        throw PriorityQueueEmptyException("Priority Queue is empty!");
        return NULL;
    }
    
    return minHeap[1];
}



template<typename Object>
void MyPriorityQueue<Object>::extractMin()
{
    if (isEmpty()){
           throw PriorityQueueEmptyException("Priority Queue is empty!");
           return;
    }
    minHeap[1] = minHeap[size()];
    minHeap.pop_back();
    sink(1);
}


template<typename Object>
void MyPriorityQueue<Object>::sink(int index){
    if (index * 2 > size())
        return;
    
    int smaller = minHeap[index * 2];
    
    if (index * 2 + 1 <= size() )
        smaller = minHeap[index * 2] < minHeap[index * 2 + 1] ? index * 2 : index * 2 + 1;
    
    
    if (minHeap[index] > minHeap[smaller]) {
        swap(index, smaller);
        return sink(smaller);
    }
}
