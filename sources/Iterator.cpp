//
// Created by ofr on 5/28/23.
//
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

bool MagicalContainer::Iterator::operator<(const MagicalContainer::Iterator &other) const {
    return currentIndex < other.currentIndex;
}

bool MagicalContainer::Iterator::operator>(const MagicalContainer::Iterator &other) const {

    return currentIndex > other.currentIndex;
}

bool MagicalContainer::Iterator::operator==(const Iterator& other) const {
    return &container == &(other.container) && currentIndex == other.currentIndex;
}

bool MagicalContainer::Iterator::operator!=(const Iterator& other) const {
    return !(*this == other);
}



MagicalContainer::Iterator MagicalContainer::Iterator::begin() {
    Iterator iter(container);
    return iter;
}

MagicalContainer::Iterator MagicalContainer::Iterator::end() {
    Iterator iter(container);
    iter.currentIndex = container.size();
    return iter;
}

MagicalContainer::Iterator &MagicalContainer::Iterator::operator=(const MagicalContainer::Iterator &other) {
    if (&container != &other.container) throw runtime_error("The iterators are points at different containers");
    currentIndex = other.currentIndex;
    return *this;
}

int MagicalContainer::Iterator::operator*() const {
    return container.getElements()[static_cast<vector<int>::size_type>(currentIndex)];
}

MagicalContainer::Iterator &MagicalContainer::Iterator::operator++() {
    if (currentIndex >= container.size()) throw runtime_error("Iterator is in the end.");
    ++currentIndex;
    return *this;
}

MagicalContainer &MagicalContainer::Iterator::getContainer() const {
    return container;
}

int MagicalContainer::Iterator::getCurrentIndex() const {
    return currentIndex;
}

void MagicalContainer::Iterator::setCurrentIndex(int currentIndex) {
    Iterator::currentIndex = currentIndex;
}


