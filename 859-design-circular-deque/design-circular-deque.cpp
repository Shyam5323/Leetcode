class MyCircularDeque {
    struct Node {
        int val;
        Node* next = nullptr;
        Node* prev = nullptr;  
        Node(int value) : val(value) {}
    };

    Node* head;  
    Node* tail;  
    int k;      
    int count;   

public:
    MyCircularDeque(int k) {
        head = nullptr;
        tail = nullptr;
        this->k = k;
        this->count = 0;
    }
    
    bool insertFront(int value) {
        if (count == k) {
            return false; 
        }

        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;  
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (count == k) {
            return false; 
        }

        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;  
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;  
        }

        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;  
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;  
        }

        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr; 
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        count--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;  
        }
        return head->val;
    }

    int getRear() {
        if (isEmpty()) {
            return -1;  
        }
        return tail->val;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == k;
    }
};
