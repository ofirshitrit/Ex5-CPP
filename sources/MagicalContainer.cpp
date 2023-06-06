//
// Created by ofir on 5/28/23.
//

#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

void MagicalContainer::addElement(int element) {
     //Add the element such that it would be in ascending order
     addForSortedOrder(element);
    //Add pointers to the elements in the crossElements vector
     addToCrossOrder();
    //If the number is prime add the pointer to the element to the primeElements
     if (isPrime(element)){
         addToPrimeElements(element);
     }

}

size_t MagicalContainer::size() {
    return elements.size();
}

void MagicalContainer::removeElement(int element) {
    //Remove the element from the container
    auto it = remove(elements.begin(), elements.end(), element);
    if (it == elements.end()) throw runtime_error("Cant remove a non-existing element");
    elements.erase(it, elements.end());
    //This function clean the crossElements vector and then create a new side-cross order
    addToCrossOrder();
    //If the element is prime remove his pointer from the primesElements
    if (isPrime(element)){
        eraseFromPrimeElements(element);
    }
}

vector<int> &MagicalContainer::getElements(){
    return this->elements;
}

void MagicalContainer::setElements(vector<int> &elements) {
    this->elements = std::move(elements);
}

void MagicalContainer::addForSortedOrder(int element) {
    size_t rightPosition = 0;
    while (rightPosition < static_cast<std::vector<int>::size_type>(this->size()) && element > elements[rightPosition]){
        rightPosition++;
    }
    elements.insert(elements.begin() + static_cast<std::vector<int*>::difference_type>(rightPosition), element);
}

void MagicalContainer::addToCrossOrder() {
    // clear the vector because every add to the container change the cross order.
    sideCrossElements.clear();
    // go over the container and take one from the start and one from the end.
    size_t start = 0 , end = this->size() - 1;
    for(size_t i = 0; i < elements.size(); i+=2){
        sideCrossElements.push_back(&(elements[start]));
        sideCrossElements.push_back(&(elements[end]));
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
    // add the prime number to the right position
    size_t rightPosition = 0;
    while (rightPosition < primeElements.size() && element > *primeElements[rightPosition] ){
        rightPosition++;
    }
    primeElements.insert(primeElements.begin() + static_cast<std::vector<int*>::difference_type>(rightPosition), new int(element));
}

void MagicalContainer::eraseFromPrimeElements(int element) {
    auto it = remove(primeElements.begin(), primeElements.end(), new int(element));
    if (it == primeElements.end()) throw runtime_error("Cant remove a non-existing element");
    primeElements.erase(it, primeElements.end());
}



