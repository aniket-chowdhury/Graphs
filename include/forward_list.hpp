#ifndef FORWARD_LIST
#define FORWARD_LIST 1

#include "nodes.hpp"

namespace lib
{
template <typename T>
class list
{
private:
    node<T> *head;
    node<T> *tail;

    void init() { head = tail = fence = new node<T> nullptr; }

public:
    node<T> *getHead() { return head; }
    node<T> *getTail() { return tail; }
    void setHead(node<T> *h) { head = h; }
    void setTail(node<T> *t) { tail = t; }
    node<T> *fence;
    list(){init()};
    int flag = 1;

    bool append(T it)
    {
        tail->next = new node<T>(it, nullptr);
        if (flag == 1)
        {
            head = tail->next;
            flag++;
            fence = head;
        }
        tail = tail->next;
        return true;
    }
};

} // namespace lib
#endif // FORWARD_LIST
