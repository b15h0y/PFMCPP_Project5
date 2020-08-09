#pragma once

#include "Component.h"
#include "LeakedObjectDetector.h"

struct Plugin
{
    Component fader;
    Component label;
    Component slider;

    Plugin();
    ~Plugin();
    JUCE_LEAK_DETECTOR(Plugin)
};
