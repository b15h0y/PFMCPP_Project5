#include "GuiApplication.h"
#include <vector>

#define DEFAULT_WINDOW_NAME "Untitled"
#define  D_HEIGHT 200
#define  D_WIDTH 200


GuiApplication::GuiApplication(): windowTitle(DEFAULT_WINDOW_NAME), isResizable(false) 
{
    this->windowSize.first = D_WIDTH;
    this->windowSize.second = D_HEIGHT;
}

GuiApplication::~GuiApplication()
{
    std::cout << "a GUI App will be destoyed!" << std::endl;
}

void GuiApplication::setWindowTitle(std::string S)
{
    this->windowTitle = S;
}

void GuiApplication::setWindowSize(size_t W, size_t H)
{
    this->windowSize.first = W; 
    this->windowSize.second = H;
}

void GuiApplication::setResizable(bool n)
{
     this->isResizable = n;
}

void GuiApplication::setVisibile(bool n)
{
    this->isVisible = n;
}

std::string GuiApplication::getWindowTitle() const 
{
    return this->windowTitle;
}

std::vector<std::string> GuiApplication::getComponentsListNames() const 
{
    std::vector<std::string> list;
    for(auto i : this->componentsList)
    {
        list.push_back(i.name);
    }
    return list;
}

std::pair<size_t, size_t> GuiApplication::getWindowSize() const 
{
    return this->windowSize;
}

void GuiApplication::addComponent(Component& C)
{
    this->componentsList.push_back(C);
}
