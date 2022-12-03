#include <iostream>
#include <cstdlib> // for srand()

// Manipulation de nombres

// sum of two intergers 
int Sum(int a, int b) {
    return a + b;
}

// reverse a to b and b to a with a reference (like a pointer) to avoid returning values
void Reverse(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Sum two integers with a pointer
void Sum_Pointer(int a, int b, int *c) {
    *c = a+b;
}

// Sum two integers with a reference only with "&"
void Sum_Reference(int a, int b, int &c) {
    c = a+b;
}

// Random value initizalized for each value in a tab
void Random_Array_Value(int array[], int size) {
    srand((unsigned) time(0));
    for (int i = 0; i < size; i++) {
        array[i] = (rand() % 50) + 1; // random value between 50 and 1
    }
}

void Print_Array(int array[], int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << " " << array[i] << " ";
    }
    std::cout << " ]" << std::endl;
}

void Sort_Array(int array[], int size, int isCroissant) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size - i - 1; j++)
            if ((array[j] > array[j + 1] && isCroissant == 1) // if we want to sort croissant and actual value is greater than value+1 -> we swap values
                || (array[j] < array[j + 1] && isCroissant == 0)) // if we want to sort decroissant and actual value is less than value+1 -> we swap values
                    Reverse(array[j], array[j+1]); // we swap the two values
    }
    
}

int main() {
    std::cout << "Hello World!" << std::endl;

    // I.1.1
    std::cout << "I.1.1" << std::endl;
    int sum = Sum(2,2);
    std::cout << "Sum of two integers : " << sum << std::endl;

    // I.1.2
    std::cout << "I.1.2" << std::endl;
    int value1 = 5;
    int value2 = 10;
    std::cout << "Before : Value1 = " << value1 << " and Value2 = " << value2 << std::endl;
    Reverse(value1, value2);
    std::cout << "After : Value1 = " << value1 << " and Value2 = " << value2 << std::endl;

    // I.1.3
    std::cout << "I.1.3" << std::endl;
    int value_pointer = 0;
    Sum_Pointer(2,2,&value_pointer);
    std::cout << "value_pointer with a pointer = " << value_pointer << std::endl;
    
    value_pointer = 0;
    Sum_Reference(6,6,value_pointer);
    std::cout << "value_pointer with a reference = " << value_pointer << std::endl;

    // I.1.4
    std::cout << "I.1.4" << std::endl;
    int size;
    int isCroissant;
    std::cout << "Enter the size of the array : ";
    std::cin >> size;

     if(std::cin.fail() || size <= 0) { // if not valid value
        std::cout << "Error. Enter value for the size array (value greater than 0)" << std::endl; 
        std::cin.clear();
        std::cin.ignore(); // we clear and ignore the failure to restart the loop
        return EXIT_FAILURE;
    }

    std::cout << "Sorting croissant (enter : 1) or decroissant (enter : 0) ";
    std::cin >> isCroissant;

    if(std::cin.fail() || isCroissant != 0 && isCroissant != 1) { // if not valid value
        std::cout << "Error. Enter value between 0 and 1" << std::endl; 
        std::cin.clear();
        std::cin.ignore(); // we clear and ignore the failure to restart the loop
        return EXIT_FAILURE;
    } else {
        if(isCroissant == 1) {
            std::cout << "You choose a croissant sorting :" << std::endl; 
        } else {
            std::cout << "You choose a decroissant sorting :" << std::endl;
        }
    }

    int tab [size];
    Random_Array_Value(tab, size);
    std::cout << " -> Non sorted array :" << std::endl;
    Print_Array(tab, size);
    std::cout << " -> Sorted array :" << std::endl;
    Sort_Array(tab, size, isCroissant);
    Print_Array(tab, size);

    return 0;
}
