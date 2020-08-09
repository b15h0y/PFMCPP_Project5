
#pragma once

#include <array>
#include "LeakedObjectDetector.h"

struct Component 
{
private:
    std::uint32_t memoryAddress;
public:    
    std::array<std::uint32_t, 2> pos;
    float rotationAngle;
    bool isVisible = true;
    std::string name;
    
    Component();
    Component(const Component& A);
    ~Component();
    void setComponentName(std::string);
    void getComponentName() const;
    void setVisibility(bool);
    void setRotation(float);
    void setPosition(std::uint32_t,std::uint32_t);
    void destroyComponent(); 
    JUCE_LEAK_DETECTOR(Component)
};
