#include <algorithm>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

template <typename T> class Element 
{
public:
    T value;
    Element* next;
    Element* prev;
    Element() : value(), next(nullptr), prev(nullptr) {}
    Element(T value) : value(value), next(nullptr), prev(nullptr) {}
    ~Element() = default;
};

template <typename T> class doubly_linked_list 
{
private:
    Element<T>* _head;
    Element<T>* _tail;
    int _size;

public:
    doubly_linked_list() : _head(nullptr), _tail(nullptr), _size(0) {}
    ~doubly_linked_list() {
        Element<T>* temp = _head;
        while (temp != nullptr) {
            temp = temp->next;
            delete _head;
            _head = temp;
        }
        _tail = nullptr;
    }

    void push_back(T value) 
    {   
        try {
        Element<T>* temp = new Element<T>(value);
        if (_head == nullptr) {
            _head = temp;
            _tail = temp;
        }
        else {
            _tail->next = temp;
            temp->prev = _tail;
            _tail = temp;
        }
        _size++;
        }
        catch (exception ex) {
			cout << "Error: memory allocation error" << ex.what() << endl;
        }
    }
    void push_front(T value) 
    {   
        try {
            Element<T>* temp = new Element<T>(value);
            if (_head == nullptr) {
                _head = temp;
                _tail = temp;
            }
            else {
                temp->prev = nullptr;
                temp->next = _head;
                _head->prev = temp;
                _head = temp;
            }
            _size++;
        }
        catch (exception ex) {
            cout << "Error: memory allocation error" << ex.what() << endl;
        }

        
    }
    void pop_back() 
    {
        try {
            if (_head == nullptr) {
                return;
            }
            else if (_head == _tail) {
                delete _head;
                _head = nullptr;
                _tail = nullptr;
            }
            else {
                Element<T>* temp = _head;
                while (temp->next != _tail) {
                    temp = temp->next;
                }
                delete _tail;
                _tail = temp;
                _tail->next = nullptr;
            }
            _size--;
        }
        catch (exception ex) {
            cout << "Error : removing the element " << ex.what() << endl;
        }
    }
    void pop_front() 
    {
        try {
            if (_head == nullptr) {
                return;
            }
            else if (_head == _tail) {
                delete _head;
                _head = nullptr;
                _tail = nullptr;
            }
            else {
                Element<T>* temp = _head;
                _head = _head->next;
                _head->prev = nullptr;
                delete temp;
            }
            _size--;
        }
        catch (exception ex) {
            cout << "Error : removing the element " << ex.what() << endl;
        }
    }
    void insert(int index, T value) 
    {
        try {
            if (index < 0 || index > _size) {
                return;
            }
            else if (index == 0) {
                push_front(value);
            }
            else if (index == _size) {
                push_back(value);
            }
            else {
                Element<T>* temp = _head;
                for (int i = 0; i < index - 1; i++) {
                    temp = temp->next;
                }
                Element<T>* new_elem = new Element<T>(value);
                new_elem->next = temp->next;
                temp->next->prev = new_elem;
                new_elem->prev = temp;
                temp->next = new_elem;
                _size++;
            }
        }
        catch (exception ex) {
            cout << "Error : memory allocation failed " << ex.what() << endl;
        }     
    }
    void remove(int index) 
    {
        try {
            if (index < 0 || index >= _size) {
                return;
            }
            else if (index == 0) {
                pop_front();
            }
            else if (index == _size - 1) {
                pop_back();
            }
            else {
                Element<T>* temp = _head;
                for (int i = 0; i < index - 1; i++) {
                    temp = temp->next;
                }
                Element<T>* to_delete = temp->next;
                temp->next = temp->next->next;
                temp->next->prev = temp;
                delete to_delete;
                _size--;
            }
        }
        catch (exception ex) {
            cout << "Error : removing the element by index" << ex.what() << endl;
        }
    }
    void remove(T value) 
    {
        try {
            Element<T>* temp = _head;
            int index = 0;
            while (temp != nullptr) {
                if (temp->value == value) {
                    remove(index);
                    return;
                }
                temp = temp->next;
                index++;
            }
        }
        catch (exception ex) {
            cout << "Error : removing the element " << ex.what() << endl;
        }
    }
    void print() {
        Element<T>* temp = _head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void print_rev() {
        Element<T>* temp = _tail;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    void dev_print() {
        int index = 0;
        Element<T>* temp = _head;
        while (temp != nullptr) {
            cout << "Element[" << index << "]: " << (long long)temp << endl;
            cout << "Value: " << temp->value << endl;
            cout << "Next element: " << (long long)temp->next << endl << endl;
            temp = temp->next;
            index++;
        }
        cout << endl;
    }
    int size() { return _size; }
};
