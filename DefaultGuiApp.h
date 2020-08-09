
#pragma once

#include "LeakedObjectDetector.h"
#include "GuiApplication.h"
#include "Component.h"

struct DefaultGuiApp
{   
    GuiApplication myApp;
    Component button;

    DefaultGuiApp();
    ~DefaultGuiApp();
    JUCE_LEAK_DETECTOR(DefaultGuiApp)
};
