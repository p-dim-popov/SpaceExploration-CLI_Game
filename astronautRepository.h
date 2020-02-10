#ifndef ASTRONAUTREPOSITORY_H
#define ASTRONAUTREPOSITORY_H
#include"iRepository.h"
#include"astronaut.h"
#include<algorithm>
#include<numeric>
class AstronautRepository : public IRepository<Astronaut>
{
    const Astronaut nullAstronaut;
    std::vector<Astronaut> astronauts;
public:
    AstronautRepository() {}
    virtual std::vector<Astronaut>& getModels() override
    {
        return this->astronauts;
    }
    virtual void add(const Astronaut & astr) override
    {
        this->astronauts.push_back(astr);
    }
//    const Astronaut& findByName(const std::string& name) override
//    {
//        for(auto &astr : this->astronauts)
//        {
//            if(astr.getName() == name)
//            {
//                return astr;
//            }
//        }
//        auto astrP = std::find_if(this->astronauts.begin(), this->astronauts.end(),
//                [&name](const Astronaut& a){ return name == a.getName();});
//        if (astrP == this->astronauts.end())
//            return nullAstronaut;
//        return (*astrP);
//    }
    virtual bool remove(const Astronaut & astr) override
    {
        auto countBefore = this->astronauts.size();
        astronauts.erase(std::remove(astronauts.begin(), astronauts.end(), astr), astronauts.end());
        return this->astronauts.size() < countBefore;
    }
};
#endif // ASTRONAUTREPOSITORY_H
