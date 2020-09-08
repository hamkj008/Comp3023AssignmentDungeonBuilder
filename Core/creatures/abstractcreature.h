#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <string>


namespace core::creatures {


class AbstractCreature
{
public:
    AbstractCreature(std::string name);
    virtual ~AbstractCreature();


    virtual AbstractCreature* clone() const = 0;
    virtual std::string name() const;
    virtual char displayCharacter() const;

private:
    std::string _name;
    char _displayCharacter;
};
}
#endif // ABSTRACTCREATURE_H
