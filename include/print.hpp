#ifndef PRINT
#define PRINT 1
#include <iostream>
#include <vector>
#include <utility>

template <typename First, typename Second>
std::ostream &operator<<(std::ostream &out, const std::pair<First, Second> &p);
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> vec);

template <typename First, typename Second>
std::ostream &operator<<(std::ostream &out, const std::pair<First, Second> &p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> vec)
{
    out << "[";
    auto it = vec.begin();
    for (it; it < vec.end() - 1; it++)
    {
        out << *it << ", ";
    }
    out << *it << "]";
    return out;
}

#endif // DEBUG
