#include "backpack.hpp"

std::vector<std::string> &Backpack::getItems() {
    return this->items;
}

bool Backpack::isFull() {
    return this->items.size() > 2;
}

Backpack::~Backpack() {

}
