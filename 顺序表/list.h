#ifndef LIST_H
#define LIST_H

template<class elemType>
class List {
public:
    
    virtual ~List() {};

    virtual void clear() = 0;

    virtual int length() const = 0;

    virtual void insert(int i, const elemType& x) = 0;

    virtual void remove(int i) = 0;

    virtual int search(const elemType& x) const = 0;

    virtual elemType visit(int i) const = 0;

    virtual void traverse() const = 0;
};

#endif // LIST_H