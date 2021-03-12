#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

template <typename T>
size_t partition(T arr[], size_t lower, size_t upper);

template <typename T>
void quicksort(T arr[], size_t lower, size_t upper) {
    if(lower < upper) {
        size_t pi = partition(arr, lower, upper);

        if(pi > 0) quicksort(arr, lower, pi);
        quicksort(arr, pi + 1, upper);
    }
}

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
size_t partition(T arr[], size_t lower, size_t upper) {
    auto pivot = arr[upper - 1];

    size_t index = lower - 1;

    for(size_t i = lower; i < upper; ++i) {
        if(arr[i] < pivot) {
            ++index;
            swap(arr[i], arr[index]);
        }
    }
    swap(arr[index + 1], arr[upper - 1]);
    return index + 1;
}

template <typename T>
void quicksort(T arr[], size_t n) {
    quicksort(arr, 0, n);
}

#endif