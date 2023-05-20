#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T> class queue
{
private:
    T* conatiner;
    T* _front;
    T* _back;
    int back_index;
    int _size;
    void extend_memmory(int step_extend = 10) {
        _size += step_extend;
        T* temp = new T[_size];
        for (int i = 0; i < back_index; i++) {
            temp[i] = conatiner[i];
        }
        delete[] conatiner;
        conatiner = temp;
    }

public:
    queue() {
        back_index = -1;
        _size = 10;
        this->conatiner = new T[_size];
    }
    queue(int size) : conatiner() {
        this->_size = size;
        this->conatiner = new T[size];
    }
    ~queue() = default;
    void push(T elem) {
        if (isFull()) {
            extend_memmory();
        }
        back_index++;
        conatiner[back_index] = elem;
        _back = &conatiner[back_index];
        if (back_index == 0) {
            _front = &conatiner[back_index];
        }
    }
    bool pop() {
        if (isEmpty()) {
            return false;
        }
        else {
            // delete _front;
            back_index--;
            T* temp = new T[_size];
            for (size_t i = 0; i <= back_index; i++) {
                temp[i] = conatiner[i + 1];
            }
            conatiner = temp;
            _front = &conatiner[0];
            return true;
        }
    }
    T* front() { return _front; }
    T* back() { return _back; }
    void output() {
        for (size_t i = 0; i <= back_index; i++) {
            if (conatiner[i] == conatiner[0]) {
                cout << "item[" << i << "] = " << conatiner[i] << " <-[front]" << endl;
            }
            else if (conatiner[i] == conatiner[back_index]) {
                cout << "item[" << i << "] = " << conatiner[i] << " <-[back]" << endl;
            }
            else {
                cout << "item[" << i << "] = " << conatiner[i] << endl;
            }
        }
    }
    int count() { return back_index + 1; }
    int memmory() { return _size; }
    bool isEmpty() { return (back_index <= 0) ? true : false; }
    bool isFull() { return (back_index == _size) ? true : false; }
};

class Busstop
{
private:
    int interval;
    int number_of_seats;   //ì³ñöÿ â àâòîáóñ³
    bool is_final;         //òèï çóïèíêè
    int passenger_count;   //ê³ëüê³ñòü ïàñàæèð³â
    int waiting_time;      //÷àñ î÷³êóâàííÿ
public:
    Busstop(int interval, int number_of_seats, bool is_final)
    {
        this->interval = interval;
        this->number_of_seats = number_of_seats;
        this->is_final = is_final;
        this->passenger_count = 0;
        this->waiting_time = 0;
    }

    void imitation(int simulation_time, int passenger_interval, int bus_interval, int max_passengers)
    {
        queue<int> passengers;
        srand(time(nullptr));

        for (int i = 0; i < simulation_time; i++) {
            //Ãåíåðàö³ÿ ïàñàæèð³â
            if (i % passenger_interval == 0)
            {
                int new_passengers = rand() % max_passengers + 1;
                for (int j = 0; j < new_passengers; j++)
                {
                    passengers.push(i);
                    passenger_count++;
                }
                cout << "Passengers arrived at time " << i << ". All passengers: " << passenger_count << endl;
            }
            //ïðèáóòòÿ àâòîáóñà
            if (i % bus_interval == 0)
            {
                int free_seats = rand() % number_of_seats + 1;
                int passengers_out = min(free_seats, passenger_count);
                for (int j = 0; j < passengers_out; j++)
                {
                    int wait_time = i - (*passengers.front());
                    waiting_time += wait_time;
                    passengers.pop();
                    passenger_count--;
                }
                cout << "Bus arrived at time " << i << ". Passengers who got off at the stop: " << passengers_out << ". All passengers: " << passenger_count << endl;
            }
        }
    }

    double get_average_waiting_time()
    {
        if (passenger_count == 0) {
            return 0;
        }
        return (double)waiting_time / passenger_count;
    }
};

