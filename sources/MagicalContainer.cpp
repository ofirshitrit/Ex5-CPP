//
// Created by ofir on 5/28/23.
//

#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

void MagicalContainer::addElement(int element) {

    /**
     * 1. add in ascending order
     * 2. add to the cross order
     * 3. if the number is prime add to the primes
     */
     addForSortedOrder(element);

     addToCrossOrder();

     if (isPrime(element)){
         addToPrimeElements(element);
     }

}

size_t MagicalContainer::size() {
    return elements.size();
}

void MagicalContainer::removeElement(int element) {
    auto it = remove(elements.begin(), elements.end(), element);
    if (it == elements.end()) throw runtime_error("Cant remove a non-existing element");
    elements.erase(it, elements.end());
}

vector<int> &MagicalContainer::getElements(){
    return this->elements;
}

void MagicalContainer::setElements(vector<int> &elements) {
    this->elements = std::move(elements);
}

void MagicalContainer::addForSortedOrder(int element) {
    int rightPosition = 0;
    while (element > elements[rightPosition] && rightPosition < this->size()){
        rightPosition++;
    }
    elements.insert(elements.begin() + rightPosition, element);
}

void MagicalContainer::addToCrossOrder() {
    // clear the vector because every add to the container change the cross order.
    sideCrossElements.clear();
    // go over the container and take one from the start and one from the end.
    size_t start = 0 , end = this->size() - 1;
    for(size_t i = 0; i < sideCrossElements.size(); i+=2){
        sideCrossElements[i] = &(elements[start]);
        sideCrossElements[i+1] = &(elements[end]);
        start++;
        end--;
    }
}

bool MagicalContainer::isPrime(int element) {
    // 0 , 1  are not prime numbers
    if (element == 0 || element == 1 ) {
        return false;
    }

    for (int i = 2; i < element; ++i) {
        if (element % i == 0) {
            return false;
        }
    }

    return true;
}

void MagicalContainer::addToPrimeElements(int element) {
    // clear the vector because every add to the container change the cross order.
    primeElements.clear();
    // add the prime number to the right position
    size_t rightPosition = 0;
    while (element > *primeElements[rightPosition] && rightPosition < this->size()){
        rightPosition++;
    }
    primeElements.insert(primeElements.begin() + rightPosition, element);
}



