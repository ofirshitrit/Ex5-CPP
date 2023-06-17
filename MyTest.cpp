//
// Created by ofr on 5/30/23.
//
#include "doctest.h"
#include <stdexcept>
#include "sources/MagicalContainer.hpp"

using namespace std;
using namespace ariel;


TEST_SUITE("MagicalContainer checks") {
    MagicalContainer container;
    TEST_CASE("Add element") {
        CHECK((container.size() == 0)); // at the beginning the container should be empty
        container.addElement(1);
        CHECK((container.size() == 1));

        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        CHECK((container.size() == 4));
    }
    TEST_CASE("Remove element") {
        container.removeElement(1);
        CHECK((container.size() == 3));
        container.removeElement(2);
        container.removeElement(3);
        container.removeElement(4);
        CHECK((container.size() == 0)); // remove all elements
        CHECK_THROWS((container.removeElement(1)));

    }
}

TEST_SUITE("AscendingIterator checks") {

    TEST_CASE("Add element") { // Check if the elements in the ascIter container are sorted
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(4);
        MagicalContainer::AscendingIterator ascIter(container);
        auto ascIterBegin = ascIter.getContainer().getElements().begin();
        auto ascIterEnd = ascIter.getContainer().getElements().end();
        vector<int> sortedElements(ascIterBegin,ascIterEnd);
        CHECK((sortedElements == vector<int>({2,4,5})));
        CHECK_FALSE((sortedElements == vector<int>({5,2,4})));
    }

    TEST_CASE("Check operators") {
        MagicalContainer container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);

        MagicalContainer::AscendingIterator ascIter(container);
        MagicalContainer::AscendingIterator ascIter2(container);

        auto ascIterBegin = ascIter.getContainer().getElements().begin();
        auto ascIterEnd = ascIter.getContainer().getElements().end();

        CHECK((ascIter == ascIter2));
        CHECK_FALSE((ascIter != ascIter2));
        CHECK((ascIterBegin < ascIterEnd));
        CHECK_FALSE((ascIterBegin > ascIterEnd));

        CHECK((*ascIter == 1));
        ++ascIter;
        CHECK((*ascIter == 2));
    }
}

TEST_SUITE("SideCrossIterator  checks") {
    TEST_CASE("Add element") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(4);
        container.addElement(6);
        MagicalContainer::SideCrossIterator crossIter(container);
        auto crossIterBegin = crossIter.getContainer().getElements().begin();
        auto crossIterEnd = crossIter.getContainer().getElements().end();
        vector<int> crossElements(crossIterBegin,crossIterEnd);
        CHECK((crossElements == vector<int>({2,6,4,5})));
        CHECK_FALSE((crossElements == vector<int>({5,2,4,6})));
    }

    TEST_CASE("Check operators") {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(1);
        container.addElement(3);
        // the container should look like that: 1,3,2
        MagicalContainer::SideCrossIterator crossIter(container);
        MagicalContainer::SideCrossIterator crossIter2(container);
        auto crossIterBegin = crossIter.getContainer().getElements().begin(); // should be 2
        auto crossIterEnd = crossIter.getContainer().getElements().end(); // should be 1

        CHECK((crossIter == crossIter2));
        CHECK_FALSE((crossIter != crossIter2));
        CHECK((crossIterBegin < crossIterEnd));
        CHECK_FALSE((crossIterBegin > crossIterEnd));

        CHECK((*crossIter == 1));
        ++crossIter;
        CHECK((*crossIter == 3));
    }
}

TEST_SUITE("PrimeIterator checks") {

    TEST_CASE("Add element") {
        // Check if the elements in the primeIter container are prime only
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(4);
        container.addElement(6);
        MagicalContainer::PrimeIterator primeIter(container);
        auto primeIterBegin = primeIter.getContainer().getElements().begin();
        auto primeIterEnd = primeIter.getContainer().getElements().end();
        vector<int> primeElements(primeIterBegin,primeIterEnd);
        CHECK((primeElements == vector<int>({2,5})));
        CHECK_FALSE((primeElements == vector<int>({5,2,4,6})));
    }

    TEST_CASE("Check operators") {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(1);
        container.addElement(3);
        container.addElement(5);
        // the container should look like that: 2,3,5
        MagicalContainer::PrimeIterator primeIter(container);
        MagicalContainer::PrimeIterator primeIter2(container);
        auto primeIterBegin = primeIter.getContainer().getElements().begin(); // should be 2
        auto primeIterEnd = primeIter.getContainer().getElements().end(); // should be 5

        CHECK((primeIter == primeIter2));
        CHECK_FALSE((primeIter != primeIter2));
        CHECK((primeIterBegin < primeIterEnd));
        CHECK_FALSE((primeIterBegin > primeIterEnd));

        CHECK((*primeIter == 2));
        ++primeIter;
        CHECK((*primeIter == 3));
    }
}

