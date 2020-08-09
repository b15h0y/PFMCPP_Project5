#include "DefaultGuiApp.h"

#include <iostream>

DefaultGuiApp::DefaultGuiApp()
{
    std::cout << "Initializing a New Default GUI!" << std::endl;
    this->myApp.setResizable(true);
    this->myApp.addComponent(button);
    this->myApp.setWindowTitle("My PFM Deafult GUI Title!");
}

DefaultGuiApp::~DefaultGuiApp()
{
    std::cout << "Default GUI is being terminated!" << std::endl;
    button.destroyComponent();
}
