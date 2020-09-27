#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <string>
#include <memory>

namespace core::creatures {

/**
 * @brief The AbstractCreature class
 * The abstract prototype class used for creating and cloning concrete creatures.
 */
class AbstractCreature
{
public:
    AbstractCreature(std::string name);
    virtual ~AbstractCreature();


    virtual std::shared_ptr<AbstractCreature> clone() const = 0;
    virtual std::string name() const;
    virtual char displayCharacter() const;

    /**
     * @brief setBoss
     * @param boss. If set to true,
     * the creature is going to be a Boss type.
     */
    virtual void setBoss(bool boss);

    /**
     * @brief isBoss
     * @return true if creature is a Boss type.
     */
    virtual bool isBoss();

    std::ostream& operator <<(std::ostream &display);

private:
    std::string _name;
    char _displayCharacter;
    bool _boss;
};
}
#endif // ABSTRACTCREATURE_H
