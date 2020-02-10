#ifndef IREPOSITORY_H
#define IREPOSITORY_H
#include<vector>
#include<string>
template <typename T>
class IRepository
{
public:
    virtual std::vector<T>& getModels() = 0;
    virtual void add(const T&) = 0;
    virtual bool remove(const T&) = 0;
//    virtual const T& findByName(const std::string&);
};
#endif // IREPOSITORY_H
