#include "header.h"

//creating list
Node* createList() {
    Node* first = new Node;
    Node* current = first;
    Node* previous = current;
    bool firstValueException = true;
    cout << "Creating list.\nEnter numbers or STOP:\n";
    while (true) {
        string value;
        cin >> value;
        if (firstValueException && value == "STOP") {
            return nullptr;
        } else {
            firstValueException = false;
        }
        if (value == "STOP"){
            previous -> pointerToNextElem = nullptr;
            delete current;
            break;
        }
        current -> value = stoi(value); //stoi() == string to int function
        current -> pointerToNextElem = new Node;
        previous = current;
        current = current -> pointerToNextElem;
    }
    return first;
}

//copying list
Node* copyList(Node* first) {
    if (first == nullptr) return nullptr;
    Node* current = first;

    Node* copy = new Node;
    copy -> value = current -> value;
    copy -> pointerToNextElem = nullptr;
    Node* copyCurrent = copy;

    current = current -> pointerToNextElem;
    while (current) {
        copyCurrent -> pointerToNextElem = new Node;
        copyCurrent = copyCurrent -> pointerToNextElem;

        copyCurrent -> value = current -> value;
        copyCurrent -> pointerToNextElem = nullptr;

        current = current -> pointerToNextElem;
    }
    return copy;
}

//getting length of the list
int listLength(Node* first) {
    if (first == nullptr) return 0;
    int length = 1;
    Node* current = first;
    while(current -> pointerToNextElem != nullptr) {
        length++;
        current = current -> pointerToNextElem;
    }
    return length;
}

//deleting list
void deleteList(Node* first){
    if (first == nullptr) return; //empty list can not be cleared
    Node* current = first;
    while (current)
    {
        first = first -> pointerToNextElem;
        delete current;
        current = first;
    }
}

//delete node on position of index
void deleteElem(Node* &first, int index) {
    int length = listLength(first);
    if (index < 0 || index > length - 1 ) {
        cout << "Error: bad index" << endl;
        return;
    }
    if (index == 0) {
        Node* temp = first -> pointerToNextElem;
        delete first;
        first = temp;
        return;
    } else {
        Node* current = first;
        for (int counter = 0; counter < index - 1; counter++) {
            current = current -> pointerToNextElem;
        }
        Node* previous = current;
        current = current -> pointerToNextElem;
        previous -> pointerToNextElem = current -> pointerToNextElem;
        delete current;
        return;
    }
}

//insert element on position of index
void insertElem(Node* &first, int index, int value) {
    int length = listLength(first);
    if (index < 0 || index > length ) {
        cout << "Error: bad index" << endl;
        return;
    }
    Node* newElem = new Node;
    newElem -> value = value;
    if (index == 0) {
        newElem -> pointerToNextElem = first;
        first = newElem;
        return;
    } else if (index == length) {
        Node* current = first;
        while (current -> pointerToNextElem) {
            current = current -> pointerToNextElem;
        }
        current -> pointerToNextElem = newElem;
        newElem -> pointerToNextElem = nullptr;
        return;
    } else {
        Node* current = first;
        for (int counter = 0; counter < index; counter++) {
            current = current -> pointerToNextElem;
        }
        newElem -> pointerToNextElem = current -> pointerToNextElem;
        current -> pointerToNextElem = newElem;
        return;
    }
}

//print list
void printList(Node* first) {
    if (first == nullptr) return;
    Node* current = first;
    while (current) {
        cout << current -> value << endl;
        current = current -> pointerToNextElem;
    }
}

//print list starting with index startIndex and ending with index endIndex
void printList(Node* first, int startIndex, int endIndex) {
    if (first == nullptr) return;
    Node* current = first;
    int counter = 0;
    while (current) {
        if (counter >= startIndex && counter < endIndex) cout << current -> value << endl;
        current = current -> pointerToNextElem;
        counter++;
    }
}

//push element into back of the list
void pushBack(Node* &first, int value) {
    Node* current = first;
    Node* previous = current;
    int length = 0; //for 0st index
    while (current) {
        previous = current;
        current = current->pointerToNextElem;
        length++;
    }
    current = new Node;
    current -> value = value;
    current -> pointerToNextElem = nullptr;
    if (length != 0) {
        previous -> pointerToNextElem = current;
    } else {
        first = current;
    }
}

//delete last element of the list
void popBack(Node* &first) {
    if (first == nullptr) return;
    Node* current = first;
    Node* previous = current;
    int length = 0; //for 0st index
    while (current -> pointerToNextElem) {
        previous = current;
        current = current->pointerToNextElem;
        length++;
    }
    if (length > 1) {
        delete current;
        previous -> pointerToNextElem = nullptr;
    } else {
        first = nullptr;
    }
}

//bubble-sorting list
void sortList (Node* first) {
    Node* previous = first;
    Node* current = previous -> pointerToNextElem;
    bool sorted = false;
    int temp;
    while (!sorted) {
        previous = first;
        current = previous -> pointerToNextElem;
        sorted = true;
        while (current) {
            if (previous -> value > current -> value) {
                temp = current -> value;
                current -> value = previous -> value;
                previous -> value = temp;
                sorted = false;
            }
            previous = previous -> pointerToNextElem;
            current = current -> pointerToNextElem;
        }
    }
}