#include "PriorityQueue.h"
#include <iostream>

int main() {
    PriorityQueue<int> priorityQueue;

    priorityQueue.InsertWithPriority(3, 1);
    priorityQueue.InsertWithPriority(7, 3);
    priorityQueue.InsertWithPriority(5, 2);

    priorityQueue.Show();

    std::cout << "Peek: " << priorityQueue.Peek() << std::endl;

    std::cout << "Pulled: " << priorityQueue.PullHighestPriorityElement() << std::endl;

    priorityQueue.Show();

    return 0;
}
