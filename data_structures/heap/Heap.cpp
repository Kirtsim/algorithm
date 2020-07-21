#include "Heap.hpp"

#include <algorithm>

namespace ds {
namespace heap {

Heap::Heap() = default;

Heap::Heap(const std::vector<int>& iValues) :
    values_(iValues)
{
    int rootPos = values_.size() / 2;
    while (rootPos > -1)
        heapify(rootPos--);
}

Heap::Heap(const Heap& iOther) :
    values_(iOther.values_)
{}

Heap& Heap::operator=(const Heap& iOther)
{
    if (this != &iOther)
        values_ = iOther.values_;
    return *this;
}

int Heap::peek()
{
    if (!values_.empty())
        return values_.front();
    throw std::runtime_error("Invoked peek() on empty Heap.");
}

void Heap::push(int iValue)
{
    values_.push_back(iValue);
    int aPos = values_.size() - 1;
    int aParentPos = positionOfParent(aPos);

    while (aParentPos > -1 && values_[aPos] > values_[aParentPos])
    {
        std::swap(values_[aPos], values_[aParentPos]);
        aPos = aParentPos;
        aParentPos = positionOfParent(aPos);
    }
}

int Heap::pop()
{
    if (values_.empty())
        throw std::runtime_error("Invoked pop() on emtpy Heap.");
    int aValue = values_.front();

    std::swap(values_.front(), values_.back());
    values_.pop_back();
    heapify(0);

    return aValue;
}

void Heap::heapify(int iPos)
{
    if (iPos >= values_.size())
        return;
    int parentPos = iPos;
    int childPos  = positionOfGreaterChild(parentPos);
    while (childPos != -1 && values_[parentPos] < values_[childPos])
    {
        std::swap(values_[parentPos], values_[childPos]);
        parentPos = childPos;
        childPos  = positionOfGreaterChild(parentPos);
    }
}

int Heap::positionOfParent(const int iChildPos)
{
    if (iChildPos % 2 == 0)
        return iChildPos / 2 - 1;
    return iChildPos / 2;
}

int Heap::positionOfGreaterChild(const int iParentPos)
{
    const int aChildPosL = iParentPos * 2 + 1;
    const int aChildPosR = aChildPosL + 1;

    if (aChildPosL >= values_.size())
        return -1;
    if (aChildPosR >= values_.size())
        return aChildPosL;
    if (values_[aChildPosL] < values_[aChildPosR])
        return aChildPosR;
    return aChildPosL;
}

int Heap::size()
{
    return values_.size();
}

bool Heap::empty()
{
    return values_.empty();
}

} // namespace heap
} // namespace ds
