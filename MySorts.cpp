#include "MySorts.h"

size_t rint::countComp = 0;

bool operator> (const rint &lhs, const rint &rhs) {
    lhs.countComp++;
    return lhs.val > rhs.val;
}

rint rint::operator= (int &rhs) {
    return rint (rhs);
}

rint::rint (int val) :
    val (val)
{}

void rint::ResetCounters () {
    countComp = 0;
}

bool operator< (const rint &lhs, const rint &rhs) {
    lhs.countComp++;
    return lhs.val < rhs.val;
}

rint::operator int () {
    return val;
}