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
    if (this != &other){
        currentIndex = other.currentIndex;
    }
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

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &cont) : container(cont) , currentIndex(0) {
    // change the container such that the elements will be in sort order
    sort(cont.getElements().begin(),cont.getElements().end());
}

MagicalContainer &MagicalContainer::AscendingIterator::getContainer()  {
    return container;
}