#ifndef NODES
#define NODES 1

#include <initializer_list>
#include <vector>
#include "print.hpp"

namespace lib
{
template <typename T>
class node
{
public:
    T element;
    node *next;
    node(T elem_val, node *nextval = nullptr) : element(elem_val), next(nextval) {}

    T &operator()()
    {
        return element;
    }
};

template <typename T>
class GraphNode
{
public:
    T val;
    int color,distance;
    GraphNode<T>* prev;
    std::vector<T> list;
    GraphNode(T value,std::vector<T> l)
    {
        list = l;
        val=value;
    }
    GraphNode(std::initializer_list<T> l)
    {
        list = std::vector<T>(l);
    }

    friend std::ostream &operator<<(std::ostream &out, const GraphNode g)
    {
        out << g.list;
        return out;
    }
};
} // namespace lib

#endif // NODES
