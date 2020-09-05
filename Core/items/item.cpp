#include "item.h"

namespace core::items {


Item::Item(std::string &name)
    : _name{name}
{

}


std::string Item::name() const {
    return _name;
}


}
