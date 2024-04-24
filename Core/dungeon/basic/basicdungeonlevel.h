#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H

#include "Core/dungeon/dungeonlevel.h"


namespace core::dungeon::basic {

    /**
     * @brief The BasicDungeonLevel class
     * The concrete Dungeon Level product, produced by the Builder, for basic dungeons.
     */
    class BasicDungeonLevel : public DungeonLevel
    {
        public:

            BasicDungeonLevel(std::string &name, int &width, int &height);

            /**
             * @brief description
             * @return the string description.
             * A brief desciption of the level, including name, size and type.
             */
            virtual std::string description() const override;


        private:
            std::string _type;

    };
}
#endif // BASICDUNGEONLEVEL_H
