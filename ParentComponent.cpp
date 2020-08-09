
#include "ParentComponent.h"
#include <iostream>
#include <vector>

ParentComponent::ParentComponent() :
name("Untitled-DEFAULT"),
numOfChildrens(0)
{

}

ParentComponent::~ParentComponent()
{
    std::cout << "a Parent will be destoyed!" << std::endl;
}

std::string ParentComponent::addChildren(Component& C)
{
    this->childrens.push_back(C);
    this->numOfChildrens++;
    return C.name;
}

std::string ParentComponent::getParentName() const
{
    return this->name;
}

bool ParentComponent::isParentVisible() const
{
    return this->isVisible;
}

bool ParentComponent::gotChildren() const
{
    return this->hasChildren;
}

bool ParentComponent::isEmpty(std::string)
{
    return this->childrens.size() == 0 ?  true : false;
}

std::vector<std::string> ParentComponent::getChildrenNames() const 
{
    std::vector<std::string> list;
    for(auto i : childrens)
    {
        list.push_back(i.name);
    }
    return list;
}
