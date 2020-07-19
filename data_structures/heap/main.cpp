#include <iostream>
#include <set>
#include "Heap.hpp"

void test();

int main()
{
    std::cout << "Hello" << std::endl;  
    test();
    return 0;
}

void printVector(const std::vector<int>& iVec)
{
    std::cout << "[ ";
    for (int aNum : iVec)
        std::cout << aNum << " ";
    std::cout << "] ";
}

void test()
{
    ds::heap::Heap aHeap;

    std::vector<int> aToInsert { 50, 29, 19, 1, 0, 101, 593, 29, 10, 2300, 
                                 10, -1, 33, 30, 709, 111, 11, 11, 11, 0, 90 };
    std::vector<int> aInserted;
    std::set<int> aExpected;
    for (int aPos = 0; aPos < aToInsert.size(); ++aPos)
    {
        const int aNumber = aToInsert[aPos];
        aHeap.push(aNumber);
        aExpected.insert(aNumber);
        if (aHeap.peek() != *aExpected.rbegin())
        {
            std::cout << "******************** [FAIL] ********************" << std::endl;
            std::cout << "Insertion of '" << aNumber << "'";
            std::cout << " to a heap containing numbers: ";
            printVector(aInserted);
            std::cout << std::endl;
            std::cout << "Expected max: " << *aExpected.rbegin() << "  ";
            std::cout << "Heap.peek(): " << aHeap.peek() << std::endl;
            std::cout << "************************************************" << std::endl;
            return;
        }
        aInserted.push_back(aNumber);
    }

    std::cout << "heap.size(): ";
    if (aHeap.size() != aToInsert.size())
    {
        std::cout << "KO" << std::endl;
        return;
    }
    std::cout << "OK" << std::endl;

    std::sort(aInserted.begin(), aInserted.end(), std::greater<int>());
    for (int aNumber : aInserted)
    {
        int aVal = aHeap.pop();
        if (aVal != aNumber)
        {
            std::cout << "Expected value: " << aNumber << " Received value: " << aVal << std::endl;
            return;
        }
    }

    if (!aHeap.empty())
    {
        std::cout << "[KO] Heap not empty after popping all values." << std::endl;
        return;
    }
    std::cout << "[OK]" << std::endl;
}

