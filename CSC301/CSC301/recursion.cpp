#include <iostream>
#include <vector>
#include <string>
using namespace std;


// ---------------------------------------------------------
// 1. FACTORIAL USING RECURSION
// ---------------------------------------------------------

long long factorial(int n)
{
    // Base case
    if (n == 0 || n == 1)
    {
        return 1;
    }

    // Recursive case
    return n * factorial(n - 1);
}


// ---------------------------------------------------------
// 2. FIBONACCI USING RECURSION
// ---------------------------------------------------------

long long fibonacci(int n)
{
    // Base cases
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}


// Display the first n Fibonacci numbers
void displayFibonacci(int n)
{
    if (n <= 0)
    {
        cout << "No Fibonacci numbers to display." << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i);

        if (i < n - 1)
        {
            cout << ", ";
        }
    }

    cout << endl;
}


// ---------------------------------------------------------
// 3. STRING REVERSAL USING RECURSION
// ---------------------------------------------------------

string reverseString(string text)
{
    // Base case
    if (text.length() <= 1)
    {
        return text;
    }

    // Recursive case
    return reverseString(text.substr(1)) + text[0];
}


// ---------------------------------------------------------
// 4. RECURSIVE BINARY SEARCH
// ---------------------------------------------------------

int binarySearch(const vector<int>& arr, int left, int right, int target)
{
    // Base case
    if (left > right)
    {
        return -1;
    }

    int middle = left + (right - left) / 2;

    // Target found
    if (arr[middle] == target)
    {
        return middle;
    }

    // Search the left half
    if (target < arr[middle])
    {
        return binarySearch(arr, left, middle - 1, target);
    }

    // Search the right half
    return binarySearch(arr, middle + 1, right, target);
}


// Test binary search
void testBinarySearch(const vector<int>& arr, int target)
{
    int result = binarySearch(arr, 0, arr.size() - 1, target);

    if (result == -1)
    {
        cout << target << " was not found." << endl;
    }
    else
    {
        cout << target << " was found at index "
             << result << "." << endl;
    }
}


// ---------------------------------------------------------
// MAIN PROGRAM
// ---------------------------------------------------------

int main()
{
    cout << " RECURSION PROGRAM " << endl;


    // -----------------------------------------------------
    // FACTORIAL TESTS
    // -----------------------------------------------------

    cout << "\n Factorial Tests " << endl;

    cout << "Factorial of 0 = "
         << factorial(0) << endl;

    cout << "Factorial of 5 = "
         << factorial(5) << endl;

    cout << "Factorial of 7 = "
         << factorial(7) << endl;


    // -----------------------------------------------------
    // FIBONACCI TESTS
    // -----------------------------------------------------

    cout << "\n Fibonacci Tests " << endl;

    cout << "First 1 Fibonacci number: ";
    displayFibonacci(1);

    cout << "First 7 Fibonacci numbers: ";
    displayFibonacci(7);

    cout << "First 10 Fibonacci numbers: ";
    displayFibonacci(10);


    // -----------------------------------------------------
    // STRING REVERSAL TESTS
    // -----------------------------------------------------

    cout << "\n String Reversal Tests " << endl;

    string word1 = "cat";
    string word2 = "computer";
    string word3 = "";

    cout << "Original: " << word1 << endl;
    cout << "Reversed: " << reverseString(word1) << endl;

    cout << "\nOriginal: " << word2 << endl;
    cout << "Reversed: " << reverseString(word2) << endl;

    cout << "\nOriginal: [empty string]" << endl;
    cout << "Reversed: ["
         << reverseString(word3)
         << "]" << endl;


    // -----------------------------------------------------
    // BINARY SEARCH TESTS
    // -----------------------------------------------------

    cout << "\n Binary Search Tests " << endl;

    vector<int> numbers = {
        2, 5, 8, 12, 16, 21, 27, 31, 40
    };

    cout << "Array: ";

    for (int number : numbers)
    {
        cout << number << " ";
    }

    cout << endl;

    testBinarySearch(numbers, 16);
    testBinarySearch(numbers, 40);
    testBinarySearch(numbers, 10);


    // Empty array edge case
    vector<int> emptyArray;

    cout << "\nSearching an empty array:" << endl;

    testBinarySearch(emptyArray, 5);


    return 0;
}

