/* CSCI 41 - WORK DONE BY: JOSE CORTES*/
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using chrono::high_resolution_clock;
using chrono::duration_cast;
using chrono::duration;
using chrono::milliseconds;

vector <milliseconds> TimeCodes (1);
// All Functions are written in the class function MyArray, because it made it easier to call for functions and information within that class //
class MyArray{
    // Private so that they can only be accesed within these functions and class
    private:
    // Size of the original random array
    const int num = 10000;
    // Orginal random array
    int* initV;
    // A vector holding copies of the orignal array with reduced sizes
    vector <int*> OriCopyArray;
    // Vectors holding similar arrays to that of OriCopy but these are meant to be sorted by a specific algorithm
    vector <int*> SelectionSortArray;
    vector <int*> InsertionSortArray;
    vector <int*> BubbleSortArray;
    vector <int*> MergeSortArray;
    vector <int*> QuickSortArray;

    public:
    // Defualt Constructor - that makes out original array of 10,000 random integers //
    MyArray(){
        // This is activated when we create our object
        initV = new int [num];
        // Using the constant num of 10,000 the array is formed dynamically
        int i;
        // Assigns each element a random integer between 1-999
        for(i = 0; i < num; i++){
            initV[i] = rand() % 1000;
        }
        // Ensure it works
        cout << "Array initV created..." << endl;
    }
    // This fuction returns our original array so it can be printed in main //
    int* returnArray(){
        return initV;
    }

    // Fuction to print an array's first 100 elements //
    void PrintArray(int* a) {
        int i;
        // loop to print those 100 elements
        for(i = 0; i < 100; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    // Creates a differently sized array with the same integers as the original up to that point declared by the size //
    void NewArrayCopy (int m){
        // Start time
        auto start = high_resolution_clock::now();
        // creates that new array dynamically while placing it in a vector to hold it
        int* copier = new int [m];
        int i;
        for(i = 0; i < m; i++){
            copier[i] = initV[i];
        }
        // Adds it to the vector - Since this doesn't use users input the order shouldn't change
        OriCopyArray.push_back(copier);
        // End time
        auto end = high_resolution_clock::now();
        // convert to integer
        TimeCodes.push_back(duration_cast<milliseconds>(end - start));
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // This starts the selection sort process by creating a copy of the array and then sorting that array using a recursive fuction //
    void BeginSS(int arraynum, int m){
        int* copier = new int [m];
        int i;
        for(i = 0; i < m; i++){
            copier[i] = initV[i];
        }
        // Adds it to the vector - Since this doesn't use users input the order shouldn't change
        SelectionSortArray.push_back(copier);
        // Print unsorted array
        cout << "Unsorted array of " << m << " elements" << endl;
        PrintArray(OriCopyArray.at(arraynum));
        cout << "Selection sort of " << m << " elements:" << endl;
        // Start time
        auto start = high_resolution_clock::now();
        // Recursive selection sort
        SelectionSort(arraynum, m, 0);
        // End time
        auto end = high_resolution_clock::now();
        // convert to integer
        TimeCodes.push_back(duration_cast<milliseconds>(end - start));
        // Prints that sorted array after
        PrintArray(SelectionSortArray.at(arraynum));
        cout << endl;
    }
    // Returns the index of the smallest number in the unsorted array //
    int MinLocationSS (int arraynum, int m, int index){
        int i;
        int minlocation = index;
        // loop to find the index of the smallest number or number equal to that of the current smallest number
        for(i = index; i < m; i++){
            if (SelectionSortArray.at(arraynum)[i] <= SelectionSortArray.at(arraynum)[minlocation]){
                minlocation = i;
            }
        }
        return minlocation;
    }
    // Recursive fuction using the index number of the array in the vector, the size, and the current position it's looking to swap //
    void SelectionSort (int arraynum, int m, int index){
        // When current index is equal to the size of the array it returns to end the function
        if (index == m){
            return;
        }
        // Swap the current index and the index of the current minimum integer
        swap(SelectionSortArray.at(arraynum)[index],SelectionSortArray.at(arraynum)[MinLocationSS(arraynum,m,index)]);
        // Recursive calling - repeating the same information except the index is one higher to move it along
        SelectionSort(arraynum, m, (index + 1));
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // This starts the insertion sort process by creating a copy of the array and then sorting that array using a sorting fuction //
    void BeginIS(int arraynum, int m){
        int* copier = new int [m];
        int i;
        for(i = 0; i < m; i++){
            copier[i] = initV[i];
        }
        // Adds it to the vector - Since this doesn't use users input the order shouldn't change
        InsertionSortArray.push_back(copier);
        // Print unsorted array
        cout << "Unsorted array of " << m << " elements" << endl;
        PrintArray(OriCopyArray.at(arraynum));
        cout << "Insertion sort of " << m << " elements:" << endl;
        // Start time
        auto start = high_resolution_clock::now();
        // Insertion sort algorithm
        InsertionSort(arraynum, m);
        // End time
        auto end = high_resolution_clock::now();
        // convert to integer
        TimeCodes.push_back(duration_cast<milliseconds>(end - start));
        // Prints that sorted array after
        PrintArray(InsertionSortArray.at(arraynum));
        cout << endl;
    }
    // Insertion sort algorithm using the postion of the array in the vector and it's size //
    void InsertionSort (int arraynum, int m){
        int i, j, index;
        // Using the previously declared variables we run 2 loops to sort one element at a time
        for (i = 1; i < m; i++){
            index = InsertionSortArray.at(arraynum)[i];
            j = i - 1;
            while (j >= 0 && InsertionSortArray.at(arraynum)[j] > index){
                InsertionSortArray.at(arraynum)[j + 1] = InsertionSortArray.at(arraynum)[j];
                j = j - 1;
            }
            InsertionSortArray.at(arraynum)[j+1] = index;
        }
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // This is the start of the bubble sort algorithm //
    void BeginBS(int arraynum, int m){
        int* copier = new int [m];
        int i;
        for(i = 0; i < m; i++){
            copier[i] = initV[i];
        }
        // Adds it to the vector - Since this doesn't use users input the order shouldn't change
        BubbleSortArray.push_back(copier);
        // Print unsorted array
        cout << "Unsorted array of " << m << " elements" << endl;
        PrintArray(OriCopyArray.at(arraynum));
        cout << "Bubble sort of " << m << " elements:" << endl;
        // Start time
        auto start = high_resolution_clock::now();
        // Bubble sort
        BubbleSort(arraynum, m);
        // End time
        auto end = high_resolution_clock::now();
        // convert to integer
        TimeCodes.push_back(duration_cast<milliseconds>(end - start));
        // Prints that sorted array after
        PrintArray(BubbleSortArray.at(arraynum));
        cout << endl;
    }
    // Bubble sort algorithm using the index of the array from the vector and the size //
    void BubbleSort ( int arraynum, int m){
        int i, j;
        // 2 loops seeing if one number is bigger than it's neighbor and then run through the array again repeating the process
        for (i = 1; i < m; i++){
            for (j = 0; j < m - 1; j++){
                if (BubbleSortArray.at(arraynum)[j] > BubbleSortArray.at(arraynum)[j + 1]){
                    swap (BubbleSortArray.at(arraynum)[j], BubbleSortArray.at(arraynum)[j + 1]);
                }
            }
        }
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // This is the start of the merge sort algorithm //
    void BeginMS(int arraynum, int m){
        int* copier = new int [m];
        int i;
        for(i = 0; i < m; i++){
            copier[i] = initV[i];
        }
        // Adds it to the vector - Since this doesn't use users input the order shouldn't change
        MergeSortArray.push_back(copier);
        // Print unsorted array
        cout << "Unsorted array of " << m << " elements" << endl;
        PrintArray(OriCopyArray.at(arraynum));
        cout << "Merge sort of " << m << " elements:" << endl;
        // Start time
        auto start = high_resolution_clock::now();
        // Merge sort
        MergeSort(arraynum, 0, m - 1);
        // End time
        auto end = high_resolution_clock::now();
        // convert to integer
        TimeCodes.push_back(duration_cast<milliseconds>(end - start));
        //Prints sorted array after
        PrintArray(MergeSortArray.at(arraynum));
        cout << endl;
    }
    // This merge function merges two arrays together from the sub arrays created from the mergesort function //
    void Merge (int arraynum, int left, int middle, int right) {
        // These two establish a1 and a2 which are the sizes of the left and right arrays
        int a1 = middle - left + 1;
        int a2 = right - middle;
        // Dynamically creates integer pointers using the previous integer values to house the split array
        int* LeftArray = new  int [a1];
        int* RightArray = new int [a2];
        // Two loops to input their values
        int i, j;
        for (i = 0; i < a1; i++){
            LeftArray[i] = MergeSortArray.at(arraynum)[left + i];
        }
        for (j = 0; j < a2; j++){
            RightArray[j] = MergeSortArray.at(arraynum)[middle + 1 + j];
        }
        // These index values are so we can move through both arrays without exceeding their size and to build the sorted array
        int IndexA1 = 0;
        int IndexA2 = 0;
        int IndexMS = left;
        // Compares the two arrays at an index to determine which has the lower value to input into the main array until one of the arrays reachs its size
        while (IndexA1 < a1 && IndexA2 < a2){
            // Left value is lower
            if (LeftArray[IndexA1] <= RightArray[IndexA2]){
                MergeSortArray.at(arraynum)[IndexMS] = LeftArray[IndexA1];
                IndexA1++;
            }
            // Right value is lower
            else {
                MergeSortArray.at(arraynum)[IndexMS] = RightArray[IndexA2];
                IndexA2++;
            }
            // Moves along the merge sort array
            IndexMS++;
        }
        // Inserts the rest of the values into the array from the left array
        while (IndexA1 < a1){
            MergeSortArray.at(arraynum)[IndexMS] = LeftArray[IndexA1];
            IndexA1++;
            IndexMS++;
        }
        // Inserts the rest of the values into the array from the right array
        while (IndexA2 < a2){
            MergeSortArray.at(arraynum)[IndexMS] = RightArray[IndexA2];
            IndexA2++;
            IndexMS++;
        }
    }
    // This function creates decreasing array sizes until the begin variable is greater than or equal to the end variable
    void MergeSort (int arraynum, int begin, int end){
        // Checks for that
        if (begin >= end) {
            return;
        }
        // Finds the middle
        int middle = begin + (end - begin) / 2;
        // Creates ranges for smaller arrays
        MergeSort(arraynum, begin, middle);
        MergeSort (arraynum, middle + 1, end);
        // Merges those arrays
        Merge (arraynum, begin, middle, end);
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // This is the start of the quick sort algorithm //
    void BeginQS(int arraynum, int m){
        int* copier = new int [m];
        int i;
        for(i = 0; i < m; i++){
            copier[i] = initV[i];
        }
        // Adds it to the vector - Since this doesn't use users input the order shouldn't change
        QuickSortArray.push_back(copier);
        // Print unsorted array
        cout << "Unsorted array of " << m << " elements" << endl;
        PrintArray(OriCopyArray.at(arraynum));
        cout << "Quick sort of " << m << " elements:" << endl;
        // Start time
        auto start = high_resolution_clock::now();
        // Quick sort
        QuickSort(arraynum, 0, (m - 1));
        // End time
        auto end = high_resolution_clock::now();
        // convert to integer
        TimeCodes.push_back(duration_cast<milliseconds>(end - start));
        //Prints sorted array after
        PrintArray(QuickSortArray.at(arraynum));
        cout << endl;
    }
    // Using the last element it puts all values lower than it to the left and all values higher to the right //
    int partition (int arraynum, int low, int high){
        // Gets last element value
        int pivot = QuickSortArray.at(arraynum)[high];
        // Is one lower than the minimum because of the pivot
        int i = (low - 1);
        // if lower value than the last element it swaps
        for (int j = low; j <= high - 1; j++){
            if (QuickSortArray.at(arraynum)[j] < pivot){
                i++;
                swap(QuickSortArray.at(arraynum)[i], QuickSortArray.at(arraynum)[j]);
            }
        }
        // Changes the last element
        swap(QuickSortArray.at(arraynum)[i + 1], QuickSortArray.at(arraynum)[high]);
        // Returns the index of that where 'i' left off
        return (i + 1);
    }
    // Using the value from the partition function to split the arrays by low and high values till it's sorted and low is equal to the high //
    void QuickSort (int arraynum, int low, int high){
        if (low < high){
            // Value from partition
            int pi = partition(arraynum, low, high);
            // Spliting functions
            QuickSort(arraynum, low, (pi - 1));
            QuickSort(arraynum, (pi + 1), high);
        }
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // This function gets the time in milliseconds from the vector and outputs it in this table //
    void TableCreation (){
        cout << "+---------------+------+----------------+----------------+-------------+------------+------------+" << endl;
        cout << "| # of elements | Copy | Selection sort | Insertion sort | Bubble sort | Merge sort | Quick sort |" << endl;
        cout << "+---------------+------+----------------+----------------+-------------+------------+------------+" << endl;
        cout << "|          2000 |   " << TimeCodes.at(1).count() << "  |       " << TimeCodes.at(6).count() << "       |       " << TimeCodes.at(11).count() << "       |     " << TimeCodes.at(16).count() << "      |     " << TimeCodes.at(21).count() << "      |     " << TimeCodes.at(26).count() << "      |" << endl;
        cout << "|          4000 |   " << TimeCodes.at(2).count() << "  |       " << TimeCodes.at(7).count() << "      |       " << TimeCodes.at(12).count() << "       |     " << TimeCodes.at(17).count() << "     |     " << TimeCodes.at(22).count() << "      |     " << TimeCodes.at(27).count() << "      |" << endl;
        cout << "|          6000 |   " << TimeCodes.at(3).count() << "  |       " << TimeCodes.at(8).count() << "      |       " << TimeCodes.at(13).count() << "      |     " << TimeCodes.at(18).count() << "     |     " << TimeCodes.at(23).count() << "      |     " << TimeCodes.at(28).count() << "      |" << endl;
        cout << "|          8000 |   " << TimeCodes.at(4).count() << "  |       " << TimeCodes.at(9).count() << "      |       " << TimeCodes.at(14).count() << "      |     " << TimeCodes.at(19).count() << "    |     " << TimeCodes.at(24).count() << "      |     " << TimeCodes.at(29).count() << "      |" << endl;
        cout << "|         10000 |   " << TimeCodes.at(5).count() << "  |       " << TimeCodes.at(10).count() << "      |       " << TimeCodes.at(15).count() << "      |     " << TimeCodes.at(20).count() << "    |     " << TimeCodes.at(25).count() << "      |     " << TimeCodes.at(30).count() << "      |" << endl;
        cout << "+---------------+------+----------------+----------------+-------------+------------+------------+" << endl;
    }
};

int main () {
    MyArray task1;
    cout << "First 100 unsorted elements of orignal array housing 10,000 integers..." << endl;
    task1.PrintArray(task1.returnArray());
    cout << endl;
    task1.NewArrayCopy(2000);
    task1.NewArrayCopy(4000);
    task1.NewArrayCopy(6000);
    task1.NewArrayCopy(8000);
    task1.NewArrayCopy(10000);
    cout << "---------------------------------------------------------------------------" << endl;
    // Selection sort of 2,000 elements
    task1.BeginSS(0,2000);
    // Selection sort of 4,000 elements
    task1.BeginSS(1,4000);
    // Selection sort of 6,000 elements
    task1.BeginSS(2,6000);
    // Selection sort of 8,000 elements
    task1.BeginSS(3,8000);
    // Selection sort of 10,000 elements
    task1.BeginSS(4,10000);
    cout << "---------------------------------------------------------------------------" << endl;
    // Insertion sort of 2,000 elements
    task1.BeginIS(0,2000);
    // Insertion sort of 4,000 elements
    task1.BeginIS(1,4000);
    // Insertion sort of 6,000 elements
    task1.BeginIS(2,6000);
    // Insertion sort of 8,000 elements
    task1.BeginIS(3,8000);
    // Insertion sort of 10,000 elements
    task1.BeginIS(4,10000);
    cout << "---------------------------------------------------------------------------" << endl;
    // Bubble sort of 2,000 elements
    task1.BeginBS(0,2000);
    // Bubble sort of 4,000 elements
    task1.BeginBS(1,4000);
    // Bubble sort of 6,000 elements
    task1.BeginBS(2,6000);
    // Bubble sort of 8,000 elements
    task1.BeginBS(3,8000);
    // Bubble sort of 10,000 elements
    task1.BeginBS(4,10000);
    cout << "---------------------------------------------------------------------------" << endl;
    // Merge sort of 2,000 elements
    task1.BeginMS(0, 2000);
    // Merge sort of 4,000 elements
    task1.BeginMS(1,4000);
    // Merge sort of 6,000 elements
    task1.BeginMS(2,6000);
    // Merge sort of 8,000 elements
    task1.BeginMS(3,8000);
    // Merge sort of 10,000 elements
    task1.BeginMS(4,10000);
    cout << "---------------------------------------------------------------------------" << endl;
    // Quick sort of 2,000 elements
    task1.BeginQS(0, 2000);
    // Quick sort of 4,000 elements
    task1.BeginQS(1,4000);
    // Quick sort of 6,000 elements
    task1.BeginQS(2,6000);
    // Quick sort of 8,000 elements
    task1.BeginQS(3,8000);
    // Quick sort of 10,000 elements
    task1.BeginQS(4,10000);
    task1.TableCreation();

    char exitstatus = 'a';
    while (exitstatus != 'q'){
        cout << "Type 'q' to exit" << endl;
        cin >> exitstatus;
    }
    cout << "Exited successfully!" << endl;

    return 0;
}