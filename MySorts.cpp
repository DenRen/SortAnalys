#include <values.h>
#include <stdexcept>
#include "MySorts.h"

size_t rint::countComp = 0;
size_t rint::countSwap = 0;

bool operator> (const struct rint &lhs, const struct rint &rhs) {
    lhs.countComp++;
    return lhs.val > rhs.val;
}

struct rint rint::operator= (int &rhs) {
    return rint (rhs);
}

rint::rint (int val) :
    val (val)
{}

void rint::ResetCounters () {
    countComp = 0;
    countSwap = 0;
}

bool operator< (const struct rint &lhs, const struct rint &rhs) {
    lhs.countComp++;
    return lhs.val < rhs.val;
}

rint::operator int () {
    return val;
}

void swap (struct rint &lhs, struct rint &rhs) {
    lhs.countSwap++;

    struct rint temp = lhs;
    lhs = rhs;
    rhs = temp;
}

float MaxSecond (std::vector <std::pair <float, float>> &data) {
    int size = data.size ();
    float max = MINFLOAT;
    while (--size >= 0)
        if (data[size].second > max)
            max = data[size].second;

    return max;
}

std::pair <arr_type, arr_type> GetSwapComp (int size_arr, int quan_point, void (*sortFunc) (struct rint[], int)) {
    if (quan_point <= 0)
        throw std::runtime_error ("quan_point <= 0");

    std::vector <std::pair <float, float> > swaps (size_arr), comps (size_arr);

    res_type *buf = (res_type *) calloc (size_arr, sizeof (res_type));
    std::random_device rd;
    std::mt19937 mersenne (rd ());

    const int step = (size_arr - 2) / quan_point;

    for (int size = 2, i = 0; size <= size_arr; size += step, i++) {
        FillRandVal32 (buf, size, &mersenne);

        rint::ResetCounters ();
        sortFunc (buf, size);

        if (CheckSortArray (buf, size) == false)
            throw std::runtime_error ("Failed sort array");

        swaps[i] = std::make_pair (size, rint::countSwap);
        comps[i] = std::make_pair (size, rint::countComp);
    }

    free (buf);
    return std::pair <arr_type, arr_type> (swaps, comps);
}