//
// Created by Justin on 2023/3/17.
//
#include <utility>
#include <vector>

using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
  public:
    vector<int> heap;

    MinHeap(vector<int> vector)
    {
        heap = buildHeap(vector);
    }

    vector<int> buildHeap(vector<int>& vector)
    {
        // Write your code here.
        for (auto i : vector) {
            insert(i);
        }
        return heap;
    }

    void siftDown(int currentIdx, int endIdx, vector<int>& heap)
    {
        // Write your code here.
        if (currentIdx != endIdx) {
            int left  = (currentIdx + 1) * 2 - 1;
            int right = (currentIdx + 1) * 2;
            if (right <= endIdx) {
                int minIdx = heap[left] < heap[right] ? left : right;
                if (heap[minIdx] < heap[currentIdx]) {
                    std::swap(heap[currentIdx], heap[minIdx]);
                    siftDown(minIdx, heap.size() - 1, heap);
                }
            }
            else if (left <= endIdx) {
                if (heap[left] < heap[currentIdx]) {
                    std::swap(heap[currentIdx], heap[left]);
                }
            }
        }
    }

    void siftUp(int currentIdx, vector<int>& heap)
    {
        // Write your code here.
        if (currentIdx != 0) {
            int parent = (currentIdx - 1) / 2;
            if (heap[currentIdx] < heap[parent]) {
                std::swap(heap[currentIdx], heap[parent]);
                siftUp(parent, heap);
            }
        }
    }

    int peek()
    {
        // Write your code here.
        if (!heap.empty()) {
            return heap[0];
        }
        return -1;
    }

    int remove()
    {
        // Write your code here.
        if (!heap.empty()) {
            int min = heap[0];
            std::swap(heap[0], heap[heap.size() - 1]);
            heap.pop_back();
            siftDown(0, heap.size() - 1, heap);
            return min;
        }
        return -1;
    }

    void insert(int value)
    {
        // Write your code here.
        heap.push_back(value);
        siftUp(heap.size() - 1, heap);
    }
};