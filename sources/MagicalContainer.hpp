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
        ~MagicalContainer() = default;

        void addElement(int element);
        size_t size();
        void removeElement(int element);
        std::vector<int>& getElements();
        void setElements(std::vector<int> &elements);

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
            AscendingIterator(MagicalContainer& cont);
            AscendingIterator(AscendingIterator& other) : container(other.container) , currentIndex(other.currentIndex){}
            ~AscendingIterator() = default;

            AscendingIterator begin();
            AscendingIterator end();

            AscendingIterator& operator=(const AscendingIterator& other);
            int operator*() const;
            AscendingIterator& operator++();
            MagicalContainer &getContainer();

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
            SideCrossIterator(MagicalContainer& cont);
            SideCrossIterator(SideCrossIterator& other) : container(other.container) , currentIndex(other.currentIndex){}
            ~SideCrossIterator() = default;

            SideCrossIterator begin();
            SideCrossIterator end();

            SideCrossIterator& operator=(const SideCrossIterator& other);
            int operator*() const;
            SideCrossIterator& operator++();
            MagicalContainer &getContainer() const;

            void turnToCrossOrder();
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
            PrimeIterator(MagicalContainer& cont);
            PrimeIterator(PrimeIterator& other) : container(other.container) , currentIndex(other.currentIndex){}
            ~PrimeIterator() = default;

            PrimeIterator begin();
            PrimeIterator end();

            PrimeIterator& operator=(const PrimeIterator& other);
            int operator*() const;
            PrimeIterator& operator++();
            static bool isPrime(int number);
            MagicalContainer &getContainer() const;

            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;

            //for tidy
            PrimeIterator(PrimeIterator&& other) = default;
            PrimeIterator& operator=(PrimeIterator&& other) = delete;

        };


        void addForSortedOrder(int element);

        void addToCrossOrder();

        bool isPrime(int element);

        void addToPrimeElements(int element);
    };

};








#endif //EX5_CPP_A_MAGICALCONTAINER_HPP
