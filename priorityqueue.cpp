#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Item {
public:
    T data;
    int priority;

    // Constructor to initialize an item
    Item(T data, int priority) : data(data), priority(priority) {}

    // Overloading the <= operator to compare priorities
    bool operator<=(const Item<T>& other) const {
        return this->priority <= other.priority;
    }
};

template <typename T>
class PriorityQueue {
private:
    vector<Item<T>> items; // Vector to hold the priority queue items

public:
    // Function to insert an item into the priority queue
    void enqueue(T data, int priority) {
        Item<T> newItem(data, priority);
        items.push_back(newItem);

        // Sort the items based on priority in descending order
        sort(items.begin(), items.end(), [](const Item<T>& a, const Item<T>& b) {
            return b <= a; // Higher priority comes first
        });
    }

    // Function to remove and return the highest priority item
    T dequeue() {
        if (items.empty()) {
            throw runtime_error("Priority queue is empty");
        }
        T highestPriorityItem = items.front().data;
        items.erase(items.begin()); // Remove the item with the highest priority
        return highestPriorityItem;
    }

    // Function to check if the priority queue is empty
    bool isEmpty() const {
        return items.empty();
    }

    // Function to get the highest priority item without removing it
    T peek() const {
        if (items.empty()) {
            throw runtime_error("Priority queue is empty");
        }
        return items.front().data;
    }

    // Function to display the items in the priority queue
    void display() const {
        cout << "Priority Queue:\n";
        for (const auto& item : items) {
            cout << "Data: " << item.data << ", Priority: " << item.priority << "\n";
        }
    }
};

int main() {
    PriorityQueue<string> pq;

    // Adding items to the priority queue
    pq.enqueue("Task 1", 2);
    pq.enqueue("Task 2", 5);
    pq.enqueue("Task 3", 1);
    pq.enqueue("Task 4", 3);

    // Display the priority queue
    pq.display();

    // Dequeue the highest priority item
    cout << "\nDequeueing highest priority item: " << pq.dequeue() << "\n";
    pq.display();

    // Peek at the highest priority item
    cout << "\nPeek at highest priority item: " << pq.peek() << "\n";

    return 0;
}
