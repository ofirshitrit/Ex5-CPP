//
// Created by ofir on 6/4/23.
//

#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;


int MagicalContainer::SideCrossIterator::operator*() const {
    return *getContainer().sideCrossElements[static_cast<vector<int>::size_type>(getCurrentIndex())];
}


