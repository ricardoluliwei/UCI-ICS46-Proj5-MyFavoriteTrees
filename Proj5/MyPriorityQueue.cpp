//
//  MyPriorityQueue.cpp
//  Proj5
//
//  Created by Ricardo on 3/9/20.
//  Copyright © 2020 Ricardo. All rights reserved.
//

#include "MyPriorityQueue.hpp"

template<typename Object>
size_t MyPriorityQueue<Object>::size() const noexcept
{
    return minHeap.size() - 1; // stub
}



template<typename Object>
bool MyPriorityQueue<Object>::isEmpty() const noexcept
{
    return minHeap.empty(); // stub
}

template<typename Object>
void MyPriorityQueue<Object>::insert(const Object & elem)
{
    
}




template<typename Object>
const Object & MyPriorityQueue<Object>::min() const
{
    return minHeap[1];
}



template<typename Object>
void MyPriorityQueue<Object>::extractMin()
{
    
}

