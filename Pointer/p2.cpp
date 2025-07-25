#include <iostream> // For input/output operations (like std::cout)

// Function to swap the values of two integers using pointers
// Parameters:
//   ptrA: A pointer to the first integer
//   ptrB: A pointer to the second integer
void swapIntegers(int *ptrA, int *ptrB) {
    // Check if the pointers are not null to avoid dereferencing a null pointer,
    // which would cause a runtime error.
    if (ptrA == nullptr || ptrB == nullptr) {
        std::cerr << "Error: Null pointer passed to swapIntegers." << std::endl;
        return;
    }

    int temp; // Temporary variable to hold one of the values during the swap

    // 1. Store the value pointed to by ptrA in temp
    //    '*ptrA' dereferences the pointer, giving the value stored at that address
    temp = *ptrA;

    // 2. Store the value pointed to by ptrB into the memory location pointed to by ptrA
    *ptrA = *ptrB;

    // 3. Store the original value of ptrA (which is in temp) into the memory location pointed to by ptrB
    *ptrB = temp;

    // After these steps, the values at the memory locations pointed to by ptrA and ptrB are swapped.
}

int main() {
    // Declare and initialize two integer variables
    int num1 = 10;
    int num2 = 20;

    std::cout << "--- Before Swap ---" << std::endl;
    std::cout << "Value of num1: " << num1 << std::endl; // Output: 10
    std::cout << "Memory address of num1: " << &num1 << std::endl;
    std::cout << "Value of num2: " << num2 << std::endl; // Output: 20
    std::cout << "Memory address of num2: " << &num2 << std::endl;

    // Call the swapIntegers function
    // We pass the memory addresses of num1 and num2 using the '&' (address-of) operator.
    // So, ptrA in swapIntegers will hold the address of num1,
    // and ptrB will hold the address of num2.
    swapIntegers(&num1, &num2);

    std::cout << "\n--- After Swap ---" << std::endl;
    std::cout << "Value of num1: " << num1 << std::endl; // Output: 20
    std::cout << "Value of num2: " << num2 << std::endl; // Output: 10

    // --- Example with a pointer to an array element ---
    std::cout << "\n--- Pointer to an Array Element ---" << std::endl;
    int myArray[3] = {100, 200, 300};
    int *ptrToArrayElement = &myArray[1]; // Pointer to the second element (200)

    std::cout << "Original value at myArray[1] (via pointer): " << *ptrToArrayElement << std::endl; // Output: 200

    // Modify the array element using the pointer
    *ptrToArrayElement = 250;
    std::cout << "Modified value at myArray[1] (direct access): " << myArray[1] << std::endl; // Output: 250
    std::cout << "Modified value at myArray[1] (via pointer): " << *ptrToArrayElement << std::endl; // Output: 250

    // It's good practice to set pointers to nullptr if they are no longer pointing to valid memory
    // or if their purpose is fulfilled, especially for more complex scenarios.
    // For this simple example, it's less critical as they go out of scope soon.
    // ptrToArrayElement = nullptr;

    return 0; // Indicate successful program termination
}