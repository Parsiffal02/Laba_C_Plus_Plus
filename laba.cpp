#include <iostream>
#include <vector>
#include <algorithm> // Для std::swap
#include <cstdlib> // Для std::rand() и std::srand()
#include <ctime> // Для std::time()

// Шаблонная функция для быстрой сортировки с рандомизированным pivot
template<typename T>
int partition(std::vector<T>& arr, int low, int high) {
    // Рандомизация pivot
    std::srand(std::time(nullptr));
    int random = low + std::rand() % (high - low);
    std::swap(arr[random], arr[high]); // Меняем местами выбранный и последний элемент

    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template<typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Шаблонная функция для сортировки пузырьком
template<typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++)     
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                std::swap(arr[j], arr[j+1]);
}

// Шаблонная функция для сортировки вставками
template<typename T>
void insertionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Функция для вывода массива
template<typename T>
void printArray(const std::vector<T>& arr) {
    for (const auto& item : arr)
        std::cout << item << " ";
    std::cout << "\n";
}

int main() {
    // Создаем вектор для демонстрации
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};

    // Демонстрация быстрой сортировки
    std::cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);
    std::cout << "QuickSort: ";
    printArray(arr);

    // Демонстрация сортировки пузырьком
    std::vector<int> arr2 = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr2);
    std::cout << "BubbleSort: ";
    printArray(arr2);

    // Демонстрация сортировки вставками
    std::vector<int> arr3 = {101, 33, 59, 27, 2, 41};
    insertionSort(arr3);
    std::cout << "InsertionSort: ";
    printArray(arr3);

    return 0;
}