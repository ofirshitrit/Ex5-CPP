//
// Created by ofir on 6/4/23.
//

#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;




MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    SideCrossIterator beginIter(container);
    return beginIter;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    SideCrossIterator endIter(container);
    endIter.currentIndex = container.size();
    return endIter;
}

MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other) {
    if (&container != &other.container) throw runtime_error("The iterators are points at different containers");
    currentIndex = other.currentIndex;
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    return *container.sideCrossElements[static_cast<vector<int>::size_type>(currentIndex)];
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
    return currentIndex > other.currentIndex;
}

MagicalContainer &MagicalContainer::SideCrossIterator::getContainer() const {
    return container;
}
