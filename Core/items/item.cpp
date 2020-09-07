#include "item.h"
#include <iostream>

using namespace std;

namespace core::items {


Item::Item()
{

}
Item::~Item() {
    std::cout << "Item object deleted" << std::endl;
}

}
