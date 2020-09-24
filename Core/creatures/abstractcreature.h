#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <string>
#include <memory>

namespace core::creatures {


class AbstractCreature
{
public:
    AbstractCreature(std::string name);
    virtual ~AbstractCreature();


    virtual std::shared_ptr<AbstractCreature> clone() const = 0;
    virtual std::string name() const;
    virtual char displayCharacter() const;

    virtual void setBoss(bool boss);
    virtual bool isBoss();

    std::ostream& operator <<(std::ostream &display);

private:
    std::string _name;
    char _displayCharacter;
    bool _boss;
};
}
#endif // ABSTRACTCREATURE_H
