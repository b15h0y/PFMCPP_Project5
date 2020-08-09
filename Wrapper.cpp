#include "Wrapper.h"

ComponentWrapper::ComponentWrapper(Component* ptr) : comp(ptr)
{

}

ComponentWrapper::~ComponentWrapper()
{
    delete this->comp;
}


ParentComponentWrapper::ParentComponentWrapper(ParentComponent* ptr) : pcomp(ptr)
{

}

ParentComponentWrapper::~ParentComponentWrapper()
{
    delete this->pcomp;
}


GuiApplicationWrapper::GuiApplicationWrapper(GuiApplication* ptr) : guiapp(ptr)
{

}

GuiApplicationWrapper::~GuiApplicationWrapper()
{
    delete this->guiapp;
}
// ===================================================================

DefaultGuiAppWrapper::DefaultGuiAppWrapper(DefaultGuiApp* ptr) : dguiapp(ptr)
{

}

DefaultGuiAppWrapper::~DefaultGuiAppWrapper()
{
    delete this->dguiapp;
}


PluginWrapper::PluginWrapper(Plugin* ptr) : plugin(ptr)
{
    
}

PluginWrapper::~PluginWrapper()
{
    delete this->plugin;
}
