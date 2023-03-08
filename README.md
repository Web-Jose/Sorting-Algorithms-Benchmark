# Sorting Algorithms Benchmark
This is a C++ program that implements different sorting algorithms and benchmarks their performance. The program generates an array of 10,000 integers with random values between 0 and 999, and uses it to test the following sorting algorithms:

- Selection sort
- Insertion sort
- Bubble sort
- Merge sort
- Quick sort

The program also measures the time it takes for each algorithm to sort the array and prints out the sorted array.

## Requirements
The following requirements are necessary to run this program:

- C++11 compiler or newer

## How to run the program
To run the program, compile the code using a C++ compiler and run the resulting executable file. The program will automatically create an array of 10,000 random integers and sort it using each of the algorithms mentioned above.

## Usage
To run this program, compile the '**main.cpp**' file and run the executable. The output will display the unsorted array, followed by the sorted array for each of the three sorting algorithms. For each sorting algorithm, the execution time in milliseconds will be displayed.

## Dependencies
This program uses the following C++ standard libraries:

- iostream
- vector
- chrono

## Implementation
The '**MyArray**' class is defined with private member variables that store the initial array of integers, as well as vectors to store the sorted arrays for each sorting algorithm. The class also has member functions to perform each of the three sorting algorithms and to display the execution times for each algorithm.

The '**main**' function creates an instance of the '**MyArray**' class and calls the member functions to perform each sorting algorithm. It also stores the execution times for each sorting algorithm in a '**vector of milliseconds**'.

## Credits
This program was written by Jose Cortes as an assignment for the CSCI 41 course at California State University of Fresno

## License
This code is licensed under the MIT License. See the LICENSE file for more information.
