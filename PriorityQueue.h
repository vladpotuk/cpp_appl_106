#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>

template <typename T>
class PriorityQueue {
private:
    static const int MAX_SIZE = 100;

    struct Element {
        T value;
        int priority;

        Element() : value(T()), priority(0) {}

        Element(T val, int pri) : value(val), priority(pri) {}
    };

    Element elements[MAX_SIZE];
    int size;

public:
    PriorityQueue() : size(0) {}
    bool IsEmpty() const;
    bool IsFull() const;
    void InsertWithPriority(T value, int priority);
    T PullHighestPriorityElement();
    T Peek() const;
    void Show() const;
};

template <typename T>
bool PriorityQueue<T>::IsEmpty() const {
    return size == 0;
}

template <typename T>
bool PriorityQueue<T>::IsFull() const {
    return size == MAX_SIZE;
}

template <typename T>
void PriorityQueue<T>::InsertWithPriority(T value, int priority) {
    if (!IsFull()) {
        Element newElement(value, priority);

        int i = size - 1;
        while (i >= 0 && elements[i].priority > newElement.priority) {
            elements[i + 1] = elements[i];
            i--;
        }

        elements[i + 1] = newElement;
        size++;
    }
}

template <typename T>
T PriorityQueue<T>::PullHighestPriorityElement() {
    if (!IsEmpty()) {
        T value = elements[0].value;

        for (int i = 1; i < size; i++) {
            elements[i - 1] = elements[i];
        }

        size--;
        return value;
    }
    return T();
}

template <typename T>
T PriorityQueue<T>::Peek() const {
    if (!IsEmpty()) {
        return elements[0].value;
    }
    return T();
}

template <typename T>
void PriorityQueue<T>::Show() const {
    for (int i = 0; i < size; i++) {
        std::cout << "Value: " << elements[i].value << ", Priority: " << elements[i].priority << std::endl;
    }
}

#endif
