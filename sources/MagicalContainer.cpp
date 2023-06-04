//
// Created by ofir on 5/28/23.
//

#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

void MagicalContainer::addElement(int element) {
    elements.push_back(element);
}

size_t MagicalContainer::size() {
    return elements.size();
}

void MagicalContainer::removeElement(int element) {
    auto it = remove(elements.begin(), elements.end(), element);
    if (it == elements.end()) throw runtime_error("Cant remove a non-existing element");
    elements.erase(it, elements.end());
}

std::vector<int> &MagicalContainer::getElements(){
    return this->elements;
}

void MagicalContainer::setElements(vector<int> &elements) {
    this->elements = move(elements);
}

