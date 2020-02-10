#ifndef IREPOSITORY_H
#define IREPOSITORY_H

template <typename T>
class IRepository
{
public:
    virtual std::vector<T>& getModels() = 0;
    virtual void add(const T&) = 0;
    virtual bool remove(const T&) = 0;
};
#endif // IREPOSITORY_H
