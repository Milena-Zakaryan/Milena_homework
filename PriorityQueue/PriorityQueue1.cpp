#include <iostream>
#include <vector>
#include <cmath>

template<typename T>
class PriorityQueue
{
private:
    std::vector<T> heap;
    void heapifyUp(size_t index) 
    {
        while (index > 0) 
        {
            size_t parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) 
            {
                std::swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }
    void heapifyDown(size_t index)
    {
        size_t heapSize = heap.size();

        while (index < heapSize) 
        {
            size_t leftChild = 2 * index + 1;
            size_t rightChild = 2 * index + 2;
            size_t largest = index;

            if (leftChild < heapSize && heap[leftChild] > heap[largest])
                largest = leftChild;
            if (rightChild < heapSize && heap[rightChild] > heap[largest])
                largest = rightChild;
            if (largest != index)
            {
                std::swap(heap[index], heap[largest]);
                index = largest;
            }
            else {
                break;
            }
        }
    }
public:
    template<typename InputIt>
    PriorityQueue(InputIt first, InputIt last) :heap(first, last) 
    {
        for (int i = heap.size() / 2 - 1; i >= 0; --i) 
        {
            heapifyDown(i);
        }
    }
    bool empty() const 
    {
        return heap.empty();
    }
    size_t size() const 
    {
        return heap.size();
    }
    void push(const T& value) 
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    typename std::vector<T>::const_iterator begin() const 
    {
        return heap.begin();
    }
    typename std::vector<T>::const_iterator end() const
    {
        return heap.end();
    }
    void pop() 
    {
        if (heap.empty())
        {
            std::cout << "Heap is empty!" << std::endl;
            return;
        }
        std::swap(heap[0], heap.back());
        heap.pop_back();
        heapifyDown(0);
    }
    const T& top() const 
    {
        if (heap.empty()) 
        {
            std::cout << "Heap is empty" << std::endl;
            return 0;
        }
        return heap[0];
    }
};

struct Point 
{
    int x{};
    int y{};

    double dist() const
    {
        return std::sqrt(x * x + y * y);
    }
    friend bool operator<(const Point& lhs, const Point& rhs) 
    {
        return lhs.dist() < rhs.dist();
    }
    friend bool operator>(const Point& lhs, const Point& rhs)
    {
        return lhs.dist() > rhs.dist();
    }
};
int main() 
{
     int n;
     std::cin >> n;
     std::vector<int> v(n);
     for(int &x:v) 
     {
        std::cin >> x;
     }
     int k;
     std::cin >> k;
     PriorityQueue<int> piles(v.begin(),v.end());
     while(k>0)
     {
         double top = piles.top();
         piles.pop();
         piles.push(std::ceil(top/2));
         --k;
     }
     int sum = 0;
     while(!piles.empty())
     {
         sum+=piles.top();
         piles.pop();
     }
     std::cout << sum;
     
     return 0;
}

