#include <iostream>

// addition function
int summation(int *arrayValues, int arrayCapacity)
{
    int total = 0;
    for (int k = 0; k < arrayCapacity; k++)
    {
        total += arrayValues[k];
    }
    return total;
}
// max function

int maximum(int *arrayValues, int arrayCapacity)
{
    int maximumValue = arrayValues[0];
    for (int p = 0; p < arrayCapacity; p++)
    {
        if (arrayValues[p] > maximumValue) // compares the 2 values
        {
            maximumValue = arrayValues[p];
        }
    }
    return maximumValue;
}
int main()
{
    int arrayCapacity;
    std::cout << "How many elements do you need in the array" << '\n';
    std::cin >> arrayCapacity;

    if (arrayCapacity <= 0) // declines if the user chooses value <0;
    {
        std::cout << "Please, enter a valid number next time!" << '\n';
        return 1;
    }

    int *arrayValues = new int[arrayCapacity]; // memory allocation

    for (int i = 0; i < arrayCapacity; i++)
    {
        std::cout << "Enter the elements: " << '\n';
        std::cin >> arrayValues[i];
    }
    for (int i = 0; i < arrayCapacity; i++)
    {
        std::cout << arrayValues[i] << '\n';
    }
    std::cout << "Sum: " << summation(arrayValues, arrayCapacity) << '\n';        // function call
    std::cout << "Max. Element: " << maximum(arrayValues, arrayCapacity) << '\n'; // function call

    delete[] arrayValues;  // clear up memory
    arrayValues = nullptr; // pointer nullifier

    return 0;
}
