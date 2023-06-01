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
    return container.getElements()[currentIndex];
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    ++currentIndex;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
   //todo
   MagicalContainer::AscendingIterator itr(container);
    return itr;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    //todo
    MagicalContainer::AscendingIterator itr(container, container.size());
    return itr;

}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &cont , int index) : container(cont) , currentIndex(index) {
    sort(cont.getElements().begin(),cont.getElements().end());
}

 MagicalContainer &MagicalContainer::AscendingIterator::getContainer()  {
    return container;
}


MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &cont) : container(cont){

}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    return *this;
}

MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other) {
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    return 0;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator &other) const {
    return false;
}
bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator &other) const {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator &other) const {
    return false;
}

MagicalContainer &MagicalContainer::SideCrossIterator::getContainer() const {
    return container;
}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &cont) : container(cont){

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
