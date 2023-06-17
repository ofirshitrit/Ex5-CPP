//
// Created by ofir on 6/4/23.
//
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;



int MagicalContainer::PrimeIterator::operator*() const {
    return *getContainer().primeElements[static_cast<vector<int>::size_type>(getCurrentIndex())];
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    if (getCurrentIndex() >= getContainer().primeElements.size()) throw runtime_error("Iterator is in the end.");
    setCurrentIndex(getCurrentIndex()+1);
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator iter(getContainer());
    iter.setCurrentIndex(getContainer().primeElements.size()) ;
    return iter;
}

