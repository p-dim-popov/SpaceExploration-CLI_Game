#ifndef PLANET_H
#define PLANET_H

#include<string>
#include<vector>
#include<stdexcept>

class Planet {
    std::string name;
    std::vector<std::string> items;

    void setName(const std::string &value);
public:
    explicit Planet(const std::string &name);
    const std::string &getName() const;
    std::vector<std::string> &getItems();
    bool operator==(const Planet &planet);

    virtual ~Planet();
};

#endif // PLANET_H
