//
// Created by ofr on 5/28/23.
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
    MagicalContainer::AscendingIterator itr(container);
    return itr;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    MagicalContainer::AscendingIterator itr(container, container.size());
    return itr;

}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &cont , int index) : container(cont) , currentIndex(index) {
    sort(cont.getElements().begin(),cont.getElements().end());
}

MagicalContainer &MagicalContainer::AscendingIterator::getContainer()  {
    return container;
}


MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &cont) : container(cont) , leftIndex(0), rightIndex(cont.size() - 1), isLeftTurn(true){

}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return SideCrossIterator(container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    SideCrossIterator iter(container);
    iter.leftIndex = container.size();
    iter.rightIndex = -1;
    iter.isLeftTurn = true;
    return iter;
}

MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other) { //todo
    if (this != &other){
        leftIndex = other.leftIndex;
        rightIndex = other.rightIndex;
        isLeftTurn = other.isLeftTurn;
    }
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    if (isLeftTurn)
        return container.elements[leftIndex];
    else
        return container.elements[rightIndex];
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    if (isLeftTurn) {
        ++leftIndex;
        isLeftTurn = false;
    }
    else {
        --rightIndex;
        isLeftTurn = true;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator &other) const {
    return leftIndex == other.leftIndex && rightIndex == other.rightIndex && isLeftTurn == other.isLeftTurn;
}
bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const {
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator &other) const {
    if (isLeftTurn && !other.isLeftTurn)
        return false;
    else if (!isLeftTurn && other.isLeftTurn)
        return true;
    else if (isLeftTurn && other.isLeftTurn)
        return leftIndex < other.leftIndex;
    else
        return rightIndex > other.rightIndex;
}

bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator &other) const {
    if (isLeftTurn && !other.isLeftTurn)
        return true;
    else if (!isLeftTurn && other.isLeftTurn)
        return false;
    else if (isLeftTurn && other.isLeftTurn)
        return leftIndex > other.leftIndex;
    else
        return rightIndex < other.rightIndex;
}

MagicalContainer &MagicalContainer::SideCrossIterator::getContainer() const {
    return container;
}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &cont , int index ) : container(cont), currentIndex(index){

}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return false;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return false;
}


MagicalContainer::PrimeIterator &
MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &other) {

    return *this;
}

bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator &other) const {
    return false;
}

bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator &other) const {

    return false;
}

int MagicalContainer::PrimeIterator::operator*() const {
    return 0;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {

    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator it(container);
    return *this;
}

MagicalContainer &MagicalContainer::PrimeIterator::getContainer() const {
    return container;
}

bool MagicalContainer::PrimeIterator::isPrime(int number)
{
    bool is_prime = true;
    // 0 and 1 are not prime numbers
    if (number == 0) {
        is_prime = false;
    }

    for (int i = 3; i <= number / 2; ++i) {
        if (number % i == 0) {
            is_prime = false;
            break;
        }
    }

    return is_prime;
}