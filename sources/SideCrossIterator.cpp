//
// Created by ofir on 6/4/23.
//

#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;



MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &cont) : container(cont) , currentIndex(0){
    // change the container such that the elements will be in cross order
    createCrossOrder();
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return SideCrossIterator(container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    SideCrossIterator iter(container);
    iter.currentIndex = container.size();
    return iter;
}

MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other) {
    if (this != &other){
        currentIndex = other.currentIndex;
    }
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    return container.getElements()[static_cast<vector<int>::size_type>(currentIndex)];
}


MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    if (currentIndex >= container.size()) throw runtime_error("Iterator is in the end.");
    ++currentIndex;
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator &other) const {
    return currentIndex == other.currentIndex;
}
bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const {
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator &other) const {
    return currentIndex < other.currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator &other) const {
    return currentIndex < other.currentIndex;
}

MagicalContainer &MagicalContainer::SideCrossIterator::getContainer() const {
    return container;
}

void MagicalContainer::SideCrossIterator::createCrossOrder() {
    vector<int> sortedElements = container.getElements();
    sort(sortedElements.begin(),sortedElements.end());

    vector<int> crossElements(sortedElements.size());
    int start = 0 , end = sortedElements.size() - 1;
    for(int i =0; i < crossElements.size(); i+=2){
        crossElements[i] = sortedElements[start];
        crossElements[i+1] = sortedElements[end];
        start++;
        end--;
    }
    container.setElements(crossElements);
}
