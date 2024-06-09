#ifndef UTILITY_H
#define UTILITY_H

namespace Utility
{
    const int ConsoleYMin = 2;

    int Clamp(int value, int min, int max);
}

template <typename T, typename U>
class Pair {
public:
    T first;
    U second;

    Pair(T first, U second);
};

template <typename T, typename U>
Pair<T, U>::Pair(T first, U second) : first(first), second(second) {}

#endif