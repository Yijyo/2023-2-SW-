namespace Utility 
{
    const int ConsoleYMin = 2;

    int Clamp(int value, int min, int max) 
    {
        if (value <= min)
            return min;

        if (value >= max)
            return max;

        return value;
    }
}

template <typename T, typename U>
class Pair 
{
public:
    T first;
    U second;

    Pair(T first, U second) : first(first), second(second) {}
};