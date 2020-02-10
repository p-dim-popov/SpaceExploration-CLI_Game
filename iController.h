#ifndef ICONTROLLER_H
#define ICONTROLLER_H
#include<string>
#include<vector>
class IController
{
public:
    virtual std::string addAstronaut(const std::string& type,const std::string& astronautName) = 0;
    virtual std::string addPlanet(const std::string & planetName, std::vector<std::string>& items) = 0;
    virtual std::string retireAstronaut(const std::string &astronautName) = 0;
    virtual std::string explorePlanet(const std::string &planetName) = 0;
    virtual std::string report() = 0;
};
#endif // ICONTROLLER_H
