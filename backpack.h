#ifndef BACKPACK_H
#define BACKPACK_H
#include<vector>
#include<string>

class Backpack
{
    std::vector<std::string> items;
public:
    Backpack() = default;
    std::vector<std::string>& getItems()
    {
        return this->items;
    }
    bool isFull()
    {
        return this->items.size() > 2;
    }
};
#endif // BACKPACK_H
