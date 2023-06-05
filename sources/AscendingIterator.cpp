//
// Created by ofir on 6/4/23.
//
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;



bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    return &container == &(other.container) && currentIndex == other.currentIndex;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(*this == other);
}


MagicalContainer::AscendingIterator &
MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other) {
    if (&container != &other.container) throw runtime_error("The iterators are points at different containers");
    currentIndex = other.currentIndex;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator &other) const {
    return currentIndex < other.currentIndex;
}

bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator &other) const {

    return currentIndex > other.currentIndex;
}

int MagicalContainer::AscendingIterator::operator*() const {
    return container.getElements()[static_cast<vector<int>::size_type>(currentIndex)];
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    if (currentIndex >= container.size()) throw runtime_error("Iterator is in the end.");
    ++currentIndex;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    return AscendingIterator(container);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    AscendingIterator iter(container);
    iter.currentIndex = container.size();
    return iter;
}
