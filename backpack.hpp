#ifndef BACKPACK_H
#define BACKPACK_H
#include<vector>
#include<string>

class Backpack
{
    std::vector<std::string> items;
public:
    Backpack() = default;
    std::vector<std::string>& getItems();
    bool isFull();

    virtual ~Backpack();
};
#endif // BACKPACK_H
