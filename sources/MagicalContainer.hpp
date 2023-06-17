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
        class Iterator {
        private:
            MagicalContainer& container;
            int currentIndex;
        public:
            Iterator(MagicalContainer& cont) : container(cont), currentIndex(0) {}
            Iterator(Iterator& other) : container(other.container) , currentIndex(other.currentIndex){}
            ~Iterator() = default;

            Iterator begin();
            virtual Iterator end();

            bool operator==(const Iterator& other) const;
            bool operator!=(const Iterator& other) const;
            bool operator<(const Iterator& other) const;
            bool operator>(const Iterator& other) const;

            Iterator& operator=(const Iterator& other);
            virtual Iterator& operator++();
            virtual int operator*() const;

            MagicalContainer &getContainer() const;
            int getCurrentIndex() const;
            void setCurrentIndex(int currentIndex);

            // for tidy:
            Iterator(Iterator&& other) = default;
            Iterator& operator=(Iterator&& other) = delete;


        };
        class AscendingIterator : Iterator {

        public:
            AscendingIterator(MagicalContainer& magicalContainer) : Iterator(magicalContainer) {}
            AscendingIterator(AscendingIterator& other) : Iterator(other) {}
        };

        class SideCrossIterator : Iterator{

        public:
            SideCrossIterator(MagicalContainer& magicalContainer) : Iterator(magicalContainer) {}
            SideCrossIterator(SideCrossIterator& other) : Iterator(other){}
            int operator*() const override;

        };

        class PrimeIterator : Iterator{

        public:
            PrimeIterator(MagicalContainer& magicalContainer) : Iterator(magicalContainer) {}
            PrimeIterator(PrimeIterator& other) : Iterator(other){}
            int operator*() const override;
            PrimeIterator& operator++() override;
            PrimeIterator end();

        };



    };

};








#endif //EX5_CPP_A_MAGICALCONTAINER_HPP
