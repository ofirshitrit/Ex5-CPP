//
// Created by ofir on 5/28/23.
//

#ifndef EX5_CPP_A_MAGICALCONTAINER_HPP
#define EX5_CPP_A_MAGICALCONTAINER_HPP
#include <iostream>
#include <vector>
#include <algorithm>
namespace ariel {
    class MagicalContainer {
    private:
        std::vector<int> elements;
        std::vector<int*> primeElements;
        std::vector<int*> sideCrossElements;
    public:
        MagicalContainer() = default;
        ~MagicalContainer();

        void addElement(int element);
        size_t size();
        void removeElement(int element);
        std::vector<int>& getElements();
        void setElements(std::vector<int> &elements);
        bool isPrime(int element);

        // This function add the element such that the elements will be in ascending order
        void addForSortedOrder(int element);
        // This function add the element such that the elements will be in side-cross order
        void addToCrossOrder();
        // This function add the prime number to the right position in the primes vector
        void addToPrimeElements(int element);
        // This function remove the prime number from the right position in the primes vector
        void eraseFromPrimeElements(int element);

        //for tidy
        MagicalContainer(const MagicalContainer& other) = delete;
        MagicalContainer& operator=(const MagicalContainer& other) = delete;
        MagicalContainer(MagicalContainer&& other) = delete;
        MagicalContainer& operator=(MagicalContainer&& other) = delete;

        // Iterators
        class AscendingIterator {
        private:
            MagicalContainer& container;
            int currentIndex;

        public:
            AscendingIterator(MagicalContainer& cont)  : container(cont) , currentIndex(0) {}
            AscendingIterator(AscendingIterator& other) : container(other.container) , currentIndex(other.currentIndex){}
            ~AscendingIterator() = default;

            AscendingIterator begin();
            AscendingIterator end();

            AscendingIterator& operator=(const AscendingIterator& other);
            int operator*() const;
            AscendingIterator& operator++();

            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;

            //for tidy
            AscendingIterator(AscendingIterator&& other) = default;
            AscendingIterator& operator=(AscendingIterator&& other) = delete;

        };

        class SideCrossIterator {
        private:
            MagicalContainer& container;
            int currentIndex;

        public:
            SideCrossIterator(MagicalContainer& cont) : container(cont) , currentIndex(0) {}
            SideCrossIterator(SideCrossIterator& other) : container(other.container) , currentIndex(other.currentIndex){}
            ~SideCrossIterator() = default;

            SideCrossIterator begin();
            SideCrossIterator end();

            SideCrossIterator& operator=(const SideCrossIterator& other);
            int operator*() const;
            SideCrossIterator& operator++();
            MagicalContainer &getContainer() const;

            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;

            //for tidy
            SideCrossIterator(SideCrossIterator&& other) = default;
            SideCrossIterator& operator=(SideCrossIterator&& other) = delete;

        };

        class PrimeIterator {
        private:
            MagicalContainer& container;
            int currentIndex;

        public:
            PrimeIterator(MagicalContainer& cont) : container(cont), currentIndex(0) {}
            PrimeIterator(PrimeIterator& other) : container(other.container) , currentIndex(other.currentIndex){}
            ~PrimeIterator() = default;

            PrimeIterator begin();
            PrimeIterator end();

            PrimeIterator& operator=(const PrimeIterator& other);
            int operator*() const;
            PrimeIterator& operator++();
            MagicalContainer &getContainer() const;

            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;

            //for tidy
            PrimeIterator(PrimeIterator&& other) = default;
            PrimeIterator& operator=(PrimeIterator&& other) = delete;

        };



    };

};








#endif //EX5_CPP_A_MAGICALCONTAINER_HPP
