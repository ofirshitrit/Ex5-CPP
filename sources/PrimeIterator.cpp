//
// Created by ofir on 6/4/23.
//
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;


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