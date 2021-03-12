#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include <vector>

using std::vector;
// [1, 3, 5, 7, 10]
// [1, 3, 5] [7, 10]
// [1, 3] [5] | [7] 10]
// [1] [3] | [5] || [7] 10]
// [1, 3] [5] | [7, 10]
// [1, 3, 5] [7, 10]
// [1, 3, 5, 7, 10]

template <typename T>
vector<T> merge(const vector<T>& lower, const vector<T>& upper);

template <typename T>
void merge_sort(vector<T>& v) {
    if(v.empty() or v.size() == 1) {
        return;
    }
    vector<T> v_lower;
    vector<T> v_upper;
    for(size_t i = 0; i < v.size(); ++i) {
        if(i < v.size() / 2) {
            v_lower.push_back(v.at(i));
        } else {
            v_upper.push_back(v.at(i));
        }
    }
    merge_sort(v_lower);
    merge_sort(v_upper);
    v = merge(v_lower, v_upper);
}

template <typename T>
vector<T> merge(const vector<T>& lower, const vector<T>& upper) {
    vector<T> merged;
    size_t i = 0, j = 0;
    while(i < lower.size() and j < upper.size()) {
        if(lower.at(i) <= upper.at(j)) {
            merged.push_back(lower.at(i));
            ++i;
        } else {
            merged.push_back(upper.at(j));
            ++j;
        }
    }

    while(i < lower.size()) {
        merged.push_back(lower.at(i));
        ++i;
    }

    while(j < upper.size()) {
        merged.push_back(upper.at(j));
        ++j;
    }

    return merged;
}

#endif