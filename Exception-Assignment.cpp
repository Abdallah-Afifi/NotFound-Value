#include <iostream>
#include <exception>

class NotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Value not found in the array.";
    }
};

int search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    throw NotFoundException();
}

int main() {
    int N;
    std::cout << "Enter the size of the array: ";
    std::cin >> N;
    int* arr = new int[N];
    std::cout << "Enter " << N << " integers for the array: ";
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    int target;
    std::cout << "Enter the target value to search for: ";
    std::cin >> target;
    try {
        int index = search(arr, N, target);
        std::cout << "Value found at index " << index << std::endl;
    }
    catch (const NotFoundException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        delete[] arr;
        return 1;
    }
    delete[] arr;
    std::cout << "Success!" << std::endl;
    return 0;
}
