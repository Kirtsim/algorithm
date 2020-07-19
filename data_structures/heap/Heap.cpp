#include "Heap.hpp"

#include <algorithm>

namespace ds {
namespace heap {

Heap::Heap() = default;

Heap::Heap(const std::vector<int>& iValues) :
    elements(iValues)
{
    // I know this is not optimal
    std::sort(elements.begin(), elements.end(), std::greater<int>());
}

Heap::Heap(const Heap& iOther) :
    elements(iOther.elements)
{}

Heap& Heap::operator=(const Heap& iOther)
{
    if (this != &iOther)
        elements = iOther.elements; 
    return *this;
}

int Heap::peek()
{
    if (!elements.empty())
        return elements.front();
    throw std::runtime_error("Invoked peek() on empty Heap.");
}

void Heap::push(int iValue)
{
    elements.push_back(iValue);
    int aPos = elements.size() - 1; 
    int aParentPos = aPos/2 - (1 * aPos % 2);

    while (aParentPos > -1 && elements[aPos] > elements[aParentPos])
    {
        std::swap(elements[aPos], elements[aParentPos]);
        aPos = aParentPos;
        aParentPos = aPos/2;
        if (aPos % 2 == 0)
            aParentPos--;
    }
}

int Heap::pop()
{
    if (elements.empty())
        throw std::runtime_error("Invoked pop() on emtpy Heap.");
    int aValue = elements.front();
    std::swap(elements.front(), elements.back());
    elements.pop_back(); 

    const int aSize = elements.size();
    int aPos = 0;
    int aChildPos = positionOfGreaterChild(aPos);
    while (aChildPos != -1 && elements[aPos] < elements[aChildPos])
    {
        std::swap(elements[aPos], elements[aChildPos]); 
        aPos = aChildPos;
        aChildPos = positionOfGreaterChild(aPos);
    }
    return aValue;
}

int Heap::positionOfGreaterChild(const int iParentPos)
{
    const int aChildPosL = iParentPos * 2 + 1;
    const int aChildPosR = aChildPosL + 1;

    if (aChildPosL >= elements.size())
        return -1;
    if (aChildPosR >= elements.size())
        return aChildPosL;
    if (elements[aChildPosL] < elements[aChildPosR])
        return aChildPosR;
    return aChildPosL;
}

int Heap::size()
{
    return elements.size();
}

bool Heap::empty()
{
    return elements.empty();
}

} // namespace heap
} // namespace ds
