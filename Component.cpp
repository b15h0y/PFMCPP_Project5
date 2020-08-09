#include "Component.h"

Component::Component(): pos{0,0}, rotationAngle(0.0), name("ComponentName")
{
    std::cout << "a Component has been initialized!" << std::endl;
}

Component::Component(const Component& A)
{ //Copy Constructor
    this->rotationAngle = A.rotationAngle;
    for(auto i : pos)
    {
        pos[i] = A.pos[i];
    }
    this->isVisible = A.isVisible;
    this->name = A.name; 
}

Component::~Component()
{
    std::cout << "a Component will be destoyed!" << std::endl;
    this->destroyComponent();
}

void Component::setComponentName(std::string n)
{
    this->name = n;
}

void Component::getComponentName() const
{
    std::cout << this->name << std::endl;
}


void Component::setVisibility(bool n)
{
    this->isVisible = n;
}

void Component::setRotation(float n)
{
    this->rotationAngle = n;
}

void Component::setPosition(std::uint32_t _X, std::uint32_t _Y)
{
    // Just for the sake of the assignment requirments..
    for(auto i : pos)
    {
        i == 0 ? this->pos[i] = _X : i == 1 ? this->pos[i] = _Y : throw std::runtime_error("Unexpected Error Occured!");
    }
}

void Component::destroyComponent()
{
    this->memoryAddress = 0x0;
}
