/* Ordered Set Implemented in an Unrolled (Doubly)-Linked List */
// File: OSULL.h

#include <iostream>
#include <cstring>
using namespace std;


template <typename T, int initNodeCapacity = 10 > 
class OSULL
{
public:
    OSULL()
    {
        // set the node capacity  
        nodeCapacity = initNodeCapacity;

        // make the front and back dummy nodes 
        front = new Node(nullptr, nullptr, nodeCapacity);
        back = new Node(front, nullptr, nodeCapacity);
        front->next = back;

        size = 0;
        nodeCount = 0;
    }
    ~OSULL()
    {
        Node *cursor = front;
        while (cursor != nullptr)
        {
            Node *current = cursor;
            cursor = cursor->next;
            delete current;
        }
    }
    bool isEmpty() { return size == 0; }
    int get_size() { return size; }

    bool insert(T item)
    {
        // inserts item into the list, if it is not there already
        // returns true if inserted; false if it was already there
        Node *cursor = front->next;
        while (cursor != back && cursor->getMax() < item)
        {
            cursor = cursor->next;
        }
        if (cursor != back && cursor->find(item))
        {
            return false; // return false if the item was already there
        }
        if (cursor == back || cursor->getSize() == cursor->getCapacity())
        {
            // if the cursor is the back node or it is full, 
            // then insert a new node before it 
            Node *newNode = new Node(cursor->prev, cursor, nodeCapacity);
            cursor->prev->next = newNode;
            cursor->prev = newNode;
            cursor = newNode;
            nodeCount++;
        }
        cursor->insert(item);
        size++;
        return true;
    }

    bool find(T item)
    {
        // searches for item in the list
        // returns true if found; false otherwise 
        Node *cursor = front->next;
        while (cursor != back && cursor->getMax() < item)
        {
            cursor = cursor->next;
        }
        return (cursor != back && cursor->find(item));
    }

    bool remove(T item)
    {
        // removes item from the list 
        // returns false if the item was not there; true if it was
        Node *cursor = front->next;
        while (cursor != back && cursor->getMax() < item)
        {
            cursor = cursor->next;
        }
        if (cursor != back && cursor->remove(item))
        {
            size--;
            if (cursor->getSize() < nodeCapacity / 2 && nodeCount > 1)
            {
                // Merge nodes if current node is less than half full
                Node *prevNode = cursor->prev;
                Node *nextNode = cursor->next;
                if (prevNode != front && prevNode->getSize() + cursor->getSize() <= prevNode->getCapacity())
                {
                    prevNode->merge(cursor);
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    delete cursor;
                    nodeCount--;
                }
                else if (nextNode != back && cursor->getSize() + nextNode->getSize() <= nextNode->getCapacity())
                {
                    cursor->merge(nextNode);
                    cursor->next = nextNode->next;
                    nextNode->next->prev = cursor;
                    delete nextNode;
                    nodeCount--;
                }
            }
            return true;
        }
        return false;
    }

    T getMin()
    {
        // returns the minimum item in the list
        // requires: size not 0 
        return front->next->getMin();
    }

    T getMax()
    {
        // returns the maximum item in the list
        // requires: size not 0 
        return back->prev->getMax();
    }

    void display()
    {
        // prints out the list contents 
        Node *cursor = front->next;
        cout << "<";
        while (cursor != back)
        {
            cursor->display();
            cursor = cursor->next;
        }
        cout << " >";
    }

private:
    class Node
    {
    public:
        Node(Node *prev, Node *next, int capacity)
        {
            // notice that we can use the constructor arguments to 
            // do most o the work of inserting a new node into the list 
            this->prev = prev;
            this->next = next;
            this->capacity = capacity;
            data = new T[capacity];
            size = 0;
        }
        Node *prev; // pointer to the next node 
        Node *next; // pointer to the previous nodes 
        int capacity; // capacity of this node 
        T *data; // array of data items in this node 
        int size; // current number of items in this node 
        int getCapacity()
        {
            // return the capacity of this node 
            return capacity;
        }
        int getSize()
        {
            // return the number of items in this node
            return size;
        }
        T getMin()
        {
            // return the smallest item in this node
            // requires: this->size not 0 
            return data[0];
        }
        T getMax()
        {
            // return the largest item in this node 
            // requires: this->size not 0 
            return data[size - 1];
        }
        bool insert(T item)
        {
            // checks if the item is in this node         
            if (find(item))
            {
                return true;
            }
            // check if the node is full
            if (size == capacity)
            {
                return false;
            }
            // find the position to insert the new item
            int i = 0;
            while (i < size && data[i] < item)
            {
                i++;
            }
            // insert the new item at the correct position
            data[i] = item;
            size++;
            return true;
        }
        bool find(T item)
        {
            // Linear search for the item in the node
            for (int i = 0; i < size; i++)
            {
                if (data[i] == item)
                {
                    return true;
                }
            }
            return false;
        }
        bool remove(T item)
        {
            // remove item from this node
            // returns true if the item was removed, false otherwise
            int i = 0;
            while (i < size && data[i] < item)
            {
                i++;
            }
            if (i == size)
            {
                return false; // Item not found
            }
            // Shift the items to the left to fill the gap
            for (int j = i; j < size - 1; j++)
            {
                data[j] = data[j + 1];
            }
            size--;
            return true;
        }

        void display()
        {
            // print the contents of this list 
            cout << "<";
            for (int i = 0; i < size; i++)
            {
                cout << " " << data[i];
            }
            cout << " >";
        }
    };

    int size; // current number of items 
    int nodeCount; // current number of nodes 
    int nodeCapacity; // capacity to assign to new nodes 
    Node *front; // pointer to front dummy node 
    Node *back;  // pointer to back dummy node 
};