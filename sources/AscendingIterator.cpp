//
// Created by ofir on 5/28/23..
//
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::begin() {
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::end() {
    setCurrentIndex(getContainer().size());
    return *this;
}



