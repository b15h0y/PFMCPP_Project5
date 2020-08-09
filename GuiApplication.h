#pragma once

#define DEFAULT_WINDOW_NAME "Untitled"
#define  D_HEIGHT 200
#define  D_WIDTH 200

#include <iostream>
#include <vector>
#include <array>

#include "LeakedObjectDetector.h"
#include "Component.h"

struct GuiApplication 
{
    std::string windowTitle;
    std::pair <size_t, size_t> windowSize;
    bool isResizable;
    bool isVisible = true;
    std::array<bool,3> showButtons = {true, true, true};
    std::vector<Component> componentsList; //NESTED

    GuiApplication();
    ~GuiApplication();
    void setWindowTitle(std::string S = DEFAULT_WINDOW_NAME);
    void setWindowSize(size_t W = D_WIDTH , size_t H = D_HEIGHT);
    void setResizable(bool);
    void setVisibile(bool);
    void addComponent(Component&);
    std::string getWindowTitle() const;
    std::vector <std::string> getComponentsListNames() const;
    std::pair <size_t, size_t> getWindowSize() const;
    JUCE_LEAK_DETECTOR(GuiApplication)

};
