#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <typename T>
class DoublyLinkedList
{
   private:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;

        Node(T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size_;

   public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size_(0) {}

    ~DoublyLinkedList() { clear(); }

    DoublyLinkedList(DoublyLinkedList& other) : head(nullptr), tail(nullptr), size_(0)
    {
        Node* current = other.head;
        while (current)
        {
            push_back(current->data);
            current = current->next;
        }
    }

    DoublyLinkedList& operator=(DoublyLinkedList& other)
    {
        if (this != &other)
        {
            clear();
            Node* current = other.head;
            while (current)
            {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void push_back(T& value)
    {
        Node* newNode = new Node(value);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size_++;
    }

    void push_front(T& value)
    {
        Node* newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size_++;
    }

    void pop_back()
    {
        Node* temp = tail;
        tail = tail->prev;
        if (tail)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
        size_--;
    }

    void pop_front()
    {
        Node* temp = head;
        head = head->next;
        if (head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
        size_--;
    }

    T& front()
    {
        return head->data;
    }

    T& back()
    {
        return tail->data;
    }

    bool empty() { return size_ == 0; }

    size_t size() { return size_; }

    void clear()
    {
        while (head)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size_ = 0;
    }
};

#endif
