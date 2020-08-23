#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <string>


class AbstractCreature
{
public:
    AbstractCreature(std::string name);


    virtual AbstractCreature clone();
    std::string name();
    char displayCharacter();


private:
    std::string _name;
    char _character;
};

#endif // ABSTRACTCREATURE_H
