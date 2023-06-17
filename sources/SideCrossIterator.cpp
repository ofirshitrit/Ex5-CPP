//
// Created by ofir on 5/28/23.
//

#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;


int MagicalContainer::SideCrossIterator::operator*() const {
    return *getContainer().sideCrossElements[static_cast<vector<int>::size_type>(getCurrentIndex())];
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::begin() {
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::end() {
    setCurrentIndex(getContainer().size());
    return *this;
}



