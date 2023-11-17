#include "Heap.h"

template <class T>
Heap<T>::Heap()
{
	heap.clear();
}

template <class T>
void Heap<T>::menu()
{
    srand(time(0));

    do
    {
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
        cout << "\n\t\t\tJ> display the heap";

        cout << "\n\t\t" + string(70, char(196));
        cout << "\n\t\t\t0> return";
        cout << "\n\t\t" + string(70, char(205));

        switch (toupper(inputChar("\n\t\t\tOption: ", static_cast<string>("ABCDEFGHIJ0"))))
        {
        case '0': return;
        case 'A':
        {
            heap.clear();

            int size = inputInteger("\n\t\t\tEnter the size of the dynamic array: ", true);

            for (int i = 0; i < size; i++)
            {
                int random = rand() % 100 + 1;
                heap.push_back(random);
            }
        }
        break;

        case 'B':
        {
            heap.push_back(inputInteger("\n\t\t\tEnter an element: "));
        }
        break;

        case 'C':
        {
            if (heap.empty())
            {
                cout << "\n\t\t\tThe array is empty. Please create the array.\n";
                break;
            }

            make_heap(heap.begin(), heap.end());

        }
        break;

        case 'D':
        {
            if (heap.empty())
            {
                cout << "\n\t\t\tThe heap is empty. Please make_heap().\n";
                break;
            }

            cout << "\n\t\t\tThe maximum element of heap: " << heap.front() << "\n";
        }
        break;

        case 'E':
        {
            heap.push_back(inputInteger("\n\t\t\tEnter an element: "));
            make_heap(heap.begin(), heap.end());
        }
        break;

        case 'F':
        {
            if (heap.empty())
            {
                cout << "\n\t\t\tThe heap is empty.\n";
                break;
            }

            pop_heap(heap.begin(), heap.end());
        }
        break;

        case 'G':
        {
            if (heap.empty())
            {
                cout << "\n\t\t\tThe heap is empty.\n";
                break;
            }

            make_heap(heap.begin(), heap.end());
            sort_heap(heap.begin(), heap.end());

        }
        break;

        case 'H':
        {
            if (heap.empty())
            {
                cout << "\n\t\t\tThe array is empty. Please create the array.\n";
                break;
            }

            if (is_heap(heap.begin(), heap.end()))
            {
                cout << "\n\t\t\tThe array is a heap.\n";
            }
            else
            {
                cout << "\n\t\t\tThe array is not a heap.\n";
            }
        }
        break;

        case 'I':
        {
            if (heap.empty())
            {
                cout << "\n\t\t\tThe array is empty. Please create the array.\n";
                break;
            }

            auto first_not_heap = is_heap_until(heap.begin(), heap.end());

            cout << "\n\t\t\tThe array is a heap until: " << *first_not_heap << "\n";

        }
        break;


        case 'J':
        {
            if (heap.empty())
            {
                cout << "\n\t\t\tThe heap is empty. Please make_heap().\n";
                break;
            }

            cout << "\n\t\t\tThe heap: ";
            for (int i = 0; i < heap.size(); i++)
            {
                cout << heap[i] << " ";
            }
            cout << "\n";
        }
        break;

        default: cout << "\n\t\t\tERROR - Invalid option.\n"; break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}

