#pragma once

#include <vector>
#include "LeakedObjectDetector.h"
#include "Component.h"

struct ParentComponent
{
    std::vector<Component> childrens; //NESTED
    std::string name;
    bool hasChildren = false;
    bool isVisible = true;
    std::uint32_t numOfChildrens;

    ParentComponent();
    ~ParentComponent();
    std::string addChildren(Component&);
    std::string setParentName(std::string);
    std::string getParentName() const;
    std::vector <std::string> getChildrenNames() const;
    bool isParentVisible() const;
    bool gotChildren() const;
    bool isEmpty(std::string);
    JUCE_LEAK_DETECTOR(ParentComponent)
};
