//
// Created by ofir on 6/4/23.
//
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;


MagicalContainer::PrimeIterator &
MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &other) {
    if (&container != &other.container) throw runtime_error("The iterators are points at different containers");
    currentIndex = other.currentIndex;
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return currentIndex == other.currentIndex;
}


bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator &other) const {
    return currentIndex < other.currentIndex;
}

bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator &other) const {
    return currentIndex > other.currentIndex;
}

int MagicalContainer::PrimeIterator::operator*() const {
    return *container.primeElements[static_cast<vector<int>::size_type>(currentIndex)];
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    if (currentIndex >= container.size()) throw runtime_error("Iterator is in the end.");
    ++currentIndex;
    return *this;
}


MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return PrimeIterator(container);
}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator iter(container);
    iter.currentIndex = container.primeElements.size();
    return iter;
}

MagicalContainer &MagicalContainer::PrimeIterator::getContainer() const {
    return container;
}

