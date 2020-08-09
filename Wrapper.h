#pragma once

// #include "Component.h"
#include "ParentComponent.h"
#include "DefaultGuiApp.h"
#include "Plugin.h"
#include "GuiApplication.h"

FIXME: Forward declare stuff that you don't use in the file.

struct Component;

struct ComponentWrapper
{
    Component* comp = nullptr;

    ComponentWrapper(Component*);
    ~ComponentWrapper();
};


struct ParentComponentWrapper
{
    ParentComponent* pcomp = nullptr;

    ParentComponentWrapper(ParentComponent*);
    ~ParentComponentWrapper();
};


struct GuiApplicationWrapper
{
    GuiApplication* guiapp = nullptr;

    GuiApplicationWrapper(GuiApplication*);
    ~GuiApplicationWrapper();
};

struct DefaultGuiAppWrapper
{
    DefaultGuiApp* dguiapp = nullptr;

    DefaultGuiAppWrapper(DefaultGuiApp*);
    ~DefaultGuiAppWrapper();
};

struct PluginWrapper
{
    Plugin* plugin = nullptr;

    PluginWrapper(Plugin*);
    ~PluginWrapper();
};
