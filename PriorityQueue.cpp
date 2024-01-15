#include "PriorityQueue.h"

template <typename T>
PriorityQueue<T>::PriorityQueue() : size(0) {
}

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
