#pragma once
#include <vector>

namespace ds {
namespace heap {

class Heap
{
public:
    Heap();
    Heap(const std::vector<int>& iValues);
    Heap(const Heap& iOther);

    Heap& operator=(const Heap& iOther);

    int peek();
    void push(int iValue);
    int pop();

    int size();
    bool empty();

private:
    int positionOfGreaterChild(int iParentPos);

    std::vector<int> elements;    
};

} // namespace heap
} // namespace ds
