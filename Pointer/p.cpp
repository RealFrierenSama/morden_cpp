#include <iostream> // For input/output operations
#include <string>   // If string pointers were needed, but this example mainly uses basic types

// Function declaration: Demonstrates modifying a variable outside the function via a pointer
void changeValueViaPointer(int* ptrToValue);

// Function declaration: Demonstrates traversing an array using a pointer
void printArrayWithPointer(int* arrPtr, int size);

int main() {
    // --- 1. What is a pointer? Declaring Pointers and nullptr ---
    std::cout << "--- 1. What is a pointer? Declaring Pointers and nullptr ---" << std::endl;
    int myVariable = 10;
    int* pointerToInt; // Declare a pointer to an integer, * indicates it's a pointer type

    // Good practice: Initialize pointer to nullptr, indicating it doesn't point to any valid memory address currently
    pointerToInt = nullptr;

    if (pointerToInt == nullptr) {
        std::cout << "pointerToInt is initialized to nullptr." << std::endl;
    }
    std::cout << std::endl;

    // --- 2. Address-of Operator (&) and Dereference Operator (*) ---
    std::cout << "--- 2. Address-of Operator (&) and Dereference Operator (*) ---" << std::endl;
    int score = 95;
    int* scorePtr;      // Declare a pointer to an integer

    // Use the address-of operator (&) to get the memory address of variable score, and assign it to pointer scorePtr
    scorePtr = &score;

    std::cout << "Value of variable score: " << score << std::endl;
    std::cout << "Memory address of variable score: " << &score << std::endl;
    std::cout << "Address stored in pointer scorePtr: " << scorePtr << std::endl;
    std::cout << "Value obtained by dereferencing (*) pointer scorePtr: " << *scorePtr << std::endl;

    // Modifying the variable's value through the pointer
    *scorePtr = 100; // Dereference scorePtr and assign a new value, this will change score's value
    std::cout << "After modification via pointer, value of variable score: " << score << std::endl;
    std::cout << std::endl;

    // --- 3. Pointers and Arrays ---
    std::cout << "--- 3. Pointers and Arrays ---" << std::endl;
    int numbers[] = {10, 20, 30, 40, 50};
    int* numbersPtr;

    // The array name itself can often be treated as a pointer to the first element of the array
    numbersPtr = numbers; // numbersPtr now points to numbers[0]
    // Equivalent to: numbersPtr = &numbers[0];

    std::cout << "Value of the first array element (via pointer): " << *numbersPtr << std::endl;
    std::cout << "Address of the first array element: " << numbersPtr << std::endl;

    // Pointer arithmetic: move pointer to the next element
    numbersPtr++; // Pointer moves forward by the size of one integer type (usually 4 bytes)
    std::cout << "Value of the second array element (after pointer moves): " << *numbersPtr << std::endl;
    std::cout << "Address of the second array element: " << numbersPtr << std::endl;

    // Reset pointer to the beginning of the array
    numbersPtr = numbers;
    std::cout << "Traversing the array using a loop and pointer:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Element " << i << ": Value = " << *(numbersPtr + i)
                  << ", Address = " << (numbersPtr + i) << std::endl;
        // Note: (numbersPtr + i) is the address, *(numbersPtr + i) is the value at that address
    }
    std::cout << std::endl;

    // --- 4. Pointers and Functions ---
    std::cout << "--- 4. Pointers and Functions ---" << std::endl;
    int valueToChange = 25;
    std::cout << "Before calling function, value of valueToChange: " << valueToChange << std::endl;

    // Pass the address of valueToChange to the function
    changeValueViaPointer(&valueToChange);

    std::cout << "After calling function, value of valueToChange: " << valueToChange << std::endl;

    // Using a function to print an array via pointer
    int anotherArray[] = {1, 2, 3};
    std::cout << "Printing array via function:" << std::endl;
    printArrayWithPointer(anotherArray, 3); // Array name passed as a pointer
    std::cout << std::endl;


    // --- 5. Dynamic Memory Allocation (new and delete) ---
    std::cout << "--- 5. Dynamic Memory Allocation (new and delete) ---" << std::endl;
    int* dynamicIntPtr = nullptr;

    // Use 'new' to allocate memory for an integer on the heap
    dynamicIntPtr = new int;

    if (dynamicIntPtr != nullptr) {
        *dynamicIntPtr = 77; // Assign a value to the dynamically allocated memory
        std::cout << "Value of dynamically allocated integer: " << *dynamicIntPtr << std::endl;
        std::cout << "Address of dynamically allocated integer: " << dynamicIntPtr << std::endl;

        // Use 'delete' to free the memory previously allocated with 'new', to prevent memory leaks
        delete dynamicIntPtr;
        std::cout << "Dynamically allocated memory has been freed." << std::endl;

        // Good practice: Set pointer to nullptr after freeing to avoid dangling pointers
        dynamicIntPtr = nullptr;
    } else {
        std::cout << "Memory allocation failed!" << std::endl;
    }

    // Dynamically allocating an array
    int size = 5;
    int* dynamicArrayPtr = nullptr;
    dynamicArrayPtr = new int[size]; // Allocate an array of 5 integers

    if (dynamicArrayPtr != nullptr) {
        std::cout << "Address of dynamically allocated array: " << dynamicArrayPtr << std::endl;
        for (int i = 0; i < size; ++i) {
            dynamicArrayPtr[i] = i * 100; // Use it like a normal array
            std::cout << "dynamicArrayPtr[" << i << "] = " << dynamicArrayPtr[i] << std::endl;
        }

        // Use 'delete[]' to free array memory allocated with 'new[]'
        delete[] dynamicArrayPtr;
        std::cout << "Dynamically allocated array memory has been freed." << std::endl;
        dynamicArrayPtr = nullptr;
    } else {
        std::cout << "Array memory allocation failed!" << std::endl;
    }
    std::cout << std::endl;


    // --- 6. Pointer Caveats and Dangers ---
    std::cout << "--- 6. Pointer Caveats and Dangers ---" << std::endl;
    // (a) Uninitialized pointer:
    // int* uninitializedPtr;
    // *uninitializedPtr = 5; // Dangerous! uninitializedPtr points to an unknown memory location, writing to it can cause a crash or undefined behavior.

    // (b) Dereferencing a null pointer:
    // int* nullPtrExample = nullptr;
    // *nullPtrExample = 10; // Dangerous! Attempting to write to address 0 or a null address, usually causes a crash.

    // (c) Dangling Pointer:
    // When a pointer points to a memory block that has already been freed, it becomes a dangling pointer.
    // If dynamicIntPtr was not set to nullptr after delete, it would be a dangling pointer.
    // If you accidentally dereference it again, the behavior is undefined.
    // if (dynamicIntPtr != nullptr) { // dynamicIntPtr has been set to nullptr, so this is safe
    //     std::cout << "Accessing freed memory (if pointer wasn't set to nullptr) causes problems." << std::endl;
    // }

    // (d) Memory Leak:
    // If memory is allocated with 'new' but forgotten to be freed with 'delete' (or 'delete[]'),
    // this memory remains occupied during program execution and cannot be reused, i.e., a memory leak.
    // Repeated memory leaks can lead to the program running out of available memory and crashing.

    std::cout << "Be careful when learning pointers! Ensure you understand how they work and their potential risks." << std::endl;

    std::cout << "\nPointer tutorial program finished." << std::endl;
    return 0;
}

// Function definition: Modifies the value of the passed variable via a pointer
void changeValueViaPointer(int* ptrToValue) {
    if (ptrToValue != nullptr) { // Always check if the pointer is nullptr before dereferencing
        std::cout << "  (Inside function) Address pointed to by ptrToValue: " << ptrToValue << std::endl;
        std::cout << "  (Inside function) Value pointed to by ptrToValue (before modification): " << *ptrToValue << std::endl;
        *ptrToValue = 500; // Modify the value at the address the pointer points to
        std::cout << "  (Inside function) Value pointed to by ptrToValue (after modification): " << *ptrToValue << std::endl;
    } else {
        std::cout << "  (Inside function) Received a null pointer!" << std::endl;
    }
}

// Function definition: Traverses and prints array elements using a pointer
void printArrayWithPointer(int* arrPtr, int size) {
    std::cout << "  (Inside function) Array address: " << arrPtr << std::endl;
    for (int i = 0; i < size; ++i) {
        // Both of the following methods can access array elements
        // std::cout << "  Element " << i << ": " << arrPtr[i] << std::endl; // Array subscript method
        std::cout << "  Element " << i << ": " << *(arrPtr + i) << std::endl; // Pointer arithmetic and dereferencing method
    }
}