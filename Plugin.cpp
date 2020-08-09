#include "Plugin.h"
#include <iostream>

Plugin::Plugin()
{
    std::cout << "Plugin is being initalized!" << std::endl;
}

Plugin::~Plugin()
{
    std::cout << "Plugin is being Terminated!" << std::endl;
}
