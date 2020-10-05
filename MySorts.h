#ifndef SORTANALYS_MYSORTS_H
#define SORTANALYS_MYSORTS_H

#include <cstdint>
#include <cstdlib>
#include <algorithm>
#include <random>

enum SORTS {
    SELECT,
    BUBBLE,
    INSERT,
    QUICK,
    size
};

typedef struct rint res_type;

struct rint {                   // Research int
    static size_t countComp;
    static size_t countSwap;

    int val;

    rint (int val);

    static void ResetCounters ();

    rint operator= (int &rhs);
    friend bool operator> (const rint &lhs, const rint &rhs);
    friend bool operator< (const rint &lhs, const rint &rhs);

    operator int ();
};

template <typename T>
void SelectSort (T data[], int size) {
    int max = INT32_MIN, iter_max = 0;
    while (size > 1) {
        max = INT32_MIN;
        for (int i = 0; i < size; i++)
            if (data[i] >= max) {
                max = data[i];
                iter_max = i;
            }

        swap (data[iter_max], data[--size]);
    }
}

template <typename T>
void BubbleSort (T data[], int size) {
    for (int j = 0; j < size; j++)
        for (int i = size - 1; i > j; i--)
            if (data[i] < data[i - 1])
                swap (data[i], data[i - 1]);
}

template <typename T>
void InsertSort (T data[], int size) {
    for (int i = 1; i < size; i++)
        for (int j = i; j > 0 && data[j - 1] > data[j]; j--)
            swap (data[j - 1], data[j]);
}

template <typename T>
void QSort (T data[], int size) {
    int left = 0, right = size - 1;
    T supp = data[right / 2];

    while (left <= right) {
        while (data[left]  < supp) left++;
        while (data[right] > supp) right--;
        if (left <= right)
            swap (data[left++], data[right--]);
    }

    if (right > 0)
        QSort (data, right + 1);

    if (left < size - 1)
        QSort (data + left, size - left);
}

void swap (struct rint &lhs, struct rint &rhs);

template <typename T>
void FillRandVal32 (T data[], int size, std::mt19937 *mt) {
    while (--size >= 0)
        data[size] = (*mt) ();
}

template <typename T>
bool CheckSortArray (T data[], int size) {
    if (size <= 1)
        return true;

    while (--size >= 1)
        if (data[size] < data[size - 1])
            return false;

    return true;
}

float MaxSecond (std::vector <std::pair <float, float>> &data);

typedef std::vector <std::pair <float, float>> arr_type;

std::pair <arr_type, arr_type> GetSwapComp (int size_arr, int quan_point, void (*sortFunc) (struct rint[], int));

#endif //SORTANALYS_MYSORTS_H
