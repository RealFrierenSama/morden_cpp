#include <iostream> // For input/output operations

int main() {
    // 1. Declare an integer variable
    int var = 20;

    // 2. Declare a pointer to an integer
    int *ptr;

    // 3. Point the pointer to the address of variable var
    //    The '&' symbol is the address-of operator
    ptr = &var;

    // Output the value of variable var
    std::cout << "Value of var: " << var << std::endl; // Output: 20

    // Output the address stored in pointer ptr (i.e., the address of var)
    std::cout << "Address stored in ptr: " << ptr << std::endl;

    // 4. Dereference pointer ptr to get the value at the address it points to
    //    The '*' symbol here is the dereference operator
    std::cout << "Value pointed to by ptr (*ptr): " << *ptr << std::endl; // Output: 20

    // 5. Modify the value of the variable through the pointer
    *ptr = 30; // Change the value at the address pointed to by ptr (i.e., var's address) to 30
    std::cout << "Value of var after modification by pointer: " << var << std::endl; // Output: 30
    std::cout << "Value of *ptr after modification by pointer: " << *ptr << std::endl; // Output: 30

    // 6. Pointers and Arrays
    int arr[3] = {10, 20, 30};
    int *arrPtr;

    // The array name itself is a pointer to the first element of the array
    arrPtr = arr; // Equivalent to arrPtr = &arr[0];

    std::cout << "\n--- Pointers and Arrays ---" << std::endl;
    std::cout << "Value of the first array element (via arrPtr): " << *arrPtr << std::endl; // Output: 10

    // Move the pointer to the next element of the array
    arrPtr++; // Pointer arithmetic, moves to the next int position
    std::cout << "Value of the second array element (via arrPtr++): " << *arrPtr << std::endl; // Output: 20

    // Move the pointer again
    arrPtr++;
    std::cout << "Value of the third array element (via arrPtr++): " << *arrPtr << std::endl; // Output: 30

    // 7. Null Pointer
    //    It's good programming practice to initialize pointers; if unsure where it should point, initialize to nullptr
    int *nullPtr = nullptr;
    std::cout << "\n--- Null Pointer ---" << std::endl;
    std::cout << "Value of nullPtr: " << nullPtr << std::endl; // Usually outputs 0 or 0x0

    // Attempting to dereference a null pointer will cause a runtime error (uncomment the line below to observe, but be careful as the program might crash)
    // std::cout << "Attempting to dereference null pointer: " << *nullPtr << std::endl;

    return 0; // Program terminated successfully
}