//
//  MyPriorityQueue.cpp
//  Proj5
//
//  Created by Ricardo on 3/9/20.
//  Copyright © 2020 Ricardo. All rights reserved.
//

#include "MyPriorityQueue.hpp"

template<typename Object>
void MyPriorityQueue<Object>::swap(int i, int j)
{
    Object temp = minHeap[i];
        minHeap[i] = minHeap[j];
        minHeap[j] = temp;
        return;
    
}

template<typename Object>
void MyPriorityQueue<Object>::sink(int index)

{
    int i = index;
    while (i*2 < size()) {
        if ((minHeap[i] < minHeap[i*2]) and (minHeap[i] < minHeap[i*2+1]))
            //current node smaller than both right and left
        {
            break;
        }
        else if ((minHeap[i] < minHeap[i*2]) and (minHeap[i] > minHeap[i*2+1]))
            //current node smaller than left but larger than right
        {
            swap(i, i*2);
            i = i*2;
        }
        else if ((minHeap[i] > minHeap[i*2]) and (minHeap[i] < minHeap[i*2+1]))
            //current node smaller than right but larger than left
        {
            swap(i, i*2+1);
            i = i*2+1;
        }
        else
        {
            if (<#condition#>) {
                <#statements#>
            }
        }
    }


}

template<typename Object>
void MyPriorityQueue<Object>::floating(int index)
{
    if (size() == 1) {
        return;
    }
    for (int i = index; i > 0; i /= 2)
        {
            if (minHeap[i] < minHeap[i/2])
                swap(i, i/2);
            else
                break;
        }

}

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

