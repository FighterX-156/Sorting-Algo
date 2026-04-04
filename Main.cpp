#include <bits/stdc++.h>
using namespace std;

vector<int> generate(int size, int min_val = 0, int max_val = 100000)
{
    vector<int> dataset;
    dataset.reserve(size);
    for (int i = 0; i < size; ++i)
    {
        int range = max_val - min_val + 1;    // 100000 -0+1
        int num = min_val + (rand() % range); 
        dataset.push_back(num);
    }
    return dataset;
}

void print(const vector<int> &data)
{
    cout << "Generated " << data.size() << " numbers:\n";
    for (size_t i = 0; i < data.size(); ++i)
    {
        cout << data[i];
        if (i != data.size() - 1)
            cout << " "; // space between numbers
    }
    cout << "\n";
    cout << "Student ID: C243014 \n"
         << "Student Name: Nafizur Rahman Seam\n";
}

// Quick Sort
int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}

void quicksort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quicksort(arr, start, p - 1);
        quicksort(arr, p + 1, end);
    }
}

// Insertion Sort
void insertionsort(vector<int> &arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx + start] = temp[idx];
    }
}

void mergesort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

void sortselection(vector<int> &data, int size)
{
    cout << "Choose an option:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Merge Sort\n";
    cout << "3. Quick Sort\n";
    cout << "Enter your choice (1-3): ";
    int Sort;
    cin >> Sort;

    // 1. Start the timer
    auto start_time = chrono::high_resolution_clock::now();

    switch (Sort)
    {
    case 1:
        insertionsort(data, size);
        break;
    case 2:
        mergesort(data, 0, size - 1);
        break;
    case 3:
        quicksort(data, 0, size - 1);
        break;
    default:
        cout << "Invalid choice.\n";
        return;
    }

    // end the timer
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> execution_time = end_time - start_time;
    print(data);
    cout << "Execution Time: " << execution_time.count() << " ms\n";
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    cout << "Choose an option:\n";
    cout << "1. Size -> 10^1\n";
    cout << "2. Size -> 10^2\n";
    cout << "3. Size -> 10^3\n";
    cout << "4. Size -> 10^4\n";
    cout << "5. Size -> 10^5\n";
    cout << "Enter your choice random dataset size (1-5): ";
    int option;
    cin >> option;

    int size;
    vector<int> data;

    switch (option)
    {
    case 1:
        size = 10;
        data = generate(size);
        break;
    case 2:
        size = 100;
        data = generate(size);
        break;
    case 3:
        size = 1000;
        data = generate(size);
        break;
    case 4:
        size = 10000;
        data = generate(size);
        break;
    case 5:
        size = 100000;
        data = generate(size);
        break;
    default:
        cout << "Error 404\n";
        return 1;
    }

    sortselection(data, size);

    return 0;
}