#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H


#include <string>


namespace core::creatures {


class AbstractCreature
{
public:
    AbstractCreature();
    AbstractCreature(std::string name);


    virtual AbstractCreature& clone() const = 0;
    std::string name();
    char displayCharacter();


private:
    std::string _name;
};
}
#endif // ABSTRACTCREATURE_H
