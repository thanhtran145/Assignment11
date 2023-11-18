#include "Heap.h"

//************************** Constructor **********************//
// Default constructor
template <class T>
Heap<T>::Heap() {
    heap.clear();
}

//************************** Public Functions **********************//

// Precondition: a positive size integer
// Postcondition: randomly create the array
template <class T>
void Heap<T>::createDynamicArray(int size) {
    heap.clear();

    for (int i = 0; i < size; i++) {
        T random = rand() % 100 + 1;
        heap.push_back(random);
    }
}


//Precondition: NA
//Postcondition: insert an element to the array
template <class T>
void Heap<T>::pushElement(T element) {
    heap.push_back(element);
}

// Precondition: an non-empty array
// Postcondition: create a heap base on the array
template <class T>
void Heap<T>::makeHeap() {
    if (heap.empty()) {
        cout << "\n\t\t\tThe array is empty. Please create the array.\n";
        return;
    }

    make_heap(heap.begin(), heap.end());
}

//Precondition: NA
//Postcondition: display the front element of the heap
template <class T>
void Heap<T>::displayMaxElement() {
    if (heap.empty()) {
        cout << "\n\t\t\tThe heap is empty. Please make_heap().\n";
        return;
    }

    cout << "\n\t\t\tThe maximum element of heap: " << heap.front() << "\n";
}

//Precondition: NA
//Postcondition: insert an element to the heap
template <class T>
void Heap<T>::pushHeap(T element) {
    heap.push_back(element);
    make_heap(heap.begin(), heap.end());
}

//Precondition: the heap has to be not empty
//Postcondition: pop the front element of the heap
template <class T>
void Heap<T>::popHeap() {
    if (heap.empty()) {
        cout << "\n\t\t\tThe heap is empty.\n";
        return;
    }

    pop_heap(heap.begin(), heap.end());
    heap.pop_back();
}

//Precondition: the heap has to be not empty
//Postcondition: sort the heap
template <class T>
void Heap<T>::sortHeap() {
    if (heap.empty()) {
        cout << "\n\t\t\tThe heap is empty.\n";
        return;
    }

    make_heap(heap.begin(), heap.end());
    sort_heap(heap.begin(), heap.end());
}

//Precondition: the heap has to be not empty
//Postcondition: return true if a vector is a heap, otherwise return false
template <class T>
bool Heap<T>::isHeap() {
    if (heap.empty()) {
        cout << "\n\t\t\tThe array is empty. Please create the array.\n";
        return false;
    }

    return is_heap(heap.begin(), heap.end());
}

//Precondition: the heap has to be not empty
//Postcondition: return the heap elements in the vector
template <class T>
void Heap<T>::isHeapUntil() {
    if (heap.empty()) {
        cout << "\n\t\t\tThe array is empty. Please create the array.\n";
        return;
    }

    auto first_not_heap = is_heap_until(heap.begin(), heap.end());

    cout << "\n\t\t\tThe heap elements in the container are: ";
    for (auto it = heap.begin(); it != first_not_heap; ++it) {
        cout << *it << " ";
    }

    cout << "\n";
}

//Precondition: the heap has to be not empty
//Postcondition: display the heap attributes
template <class T>
void Heap<T>::displayHeap() {
    if (heap.empty()) {
        cout << "\n\t\t\tThe heap is empty. Please make_heap().\n";
        return;
    }

    cout << "\n\t\t\tThe heap: ";
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << "\n";
}

//Precondition: NA
//Postcondition: display the menu
template <class T>
void Heap<T>::menu() {
    srand(time(0));

    do {
        system("cls");
        cout << "\n\t\t3> Heap in C++ STL";
        cout << "\n\t\t" + string(70, char(205));
        cout << "\n\t\t\tA> create a dynamic array";
        cout << "\n\t\t\tB> push_back() an element onto the array";
        cout << "\n\t\t\tC> make_heap()";
        cout << "\n\t\t\tD> front()";
        cout << "\n\t\t\tE> push_heap()";
        cout << "\n\t\t\tF> pop_heap()";
        cout << "\n\t\t\tG> sort_heap()";
        cout << "\n\t\t\tH> is_heap()";
        cout << "\n\t\t\tI> is_heap_until()";
        cout << "\n\t\t\tJ> display";

        cout << "\n\t\t" + string(70, char(196));
        cout << "\n\t\t\t0> return";
        cout << "\n\t\t" + string(70, char(205));

        switch (toupper(inputChar("\n\t\t\tOption: ", static_cast<string>("ABCDEFGHIJ0")))) {
        case '0': return; break;
        case 'A': 
        {
            int size = inputInteger("\n\t\t\tEnter the size of the dynamic array: ", true);
            createDynamicArray(size);
        } break;

        case 'B': {
            T element = inputInteger("\n\t\t\tEnter an element: ");
            pushElement(element);
        } break;

        case 'C':
            makeHeap();
            break;

        case 'D':
            displayMaxElement();
            break;

        case 'E': {
            T element = inputInteger("\n\t\t\tEnter an element: ");
            pushHeap(element);
        } break;

        case 'F':
            popHeap();
            break;

        case 'G':
            sortHeap();
            break;

        case 'H':
            if (isHeap()) {
                cout << "\n\t\t\tThe array is a heap.\n";
            }
            else {
                cout << "\n\t\t\tThe array is not a heap.\n";
            }
            break;

        case 'I':
            isHeapUntil();
            break;

        case 'J':
            displayHeap();
            break;

        default:
            cout << "\n\t\t\tERROR - Invalid option.\n";
            break;
        }

        cout << "\n";
        system("pause");

    } while (true);
}
