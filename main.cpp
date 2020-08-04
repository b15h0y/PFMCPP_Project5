/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */







#define DEFAULT_WINDOW_NAME "Untitled"
#define  D_HEIGHT 200
#define  D_WIDTH 200

#include <iostream>
#include <utility>
#include <vector>
#include <array>
#include "LeakedObjectDetector.h"

/** 
** NOTE: I DID NOT WRITE "USING NAMESPACE ... " CAUSE IT'S NOT A GOOD HABIT GENERALLY.
** HOWEVER IT WILL MAKE THE CODER A BIT EASIER TO READ
**/

/*
 UDT 1:
 */
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

/*
 UDT 2:
 */
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

/*
 UDT 3:
 */
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


ParentComponent::ParentComponent() :
name("Untitled-DEFAULT"),
numOfChildrens(0)
{

}

ParentComponent::~ParentComponent()
{
    std::cout << "a Parent will be destoyed!" << std::endl;
}

std::string ParentComponent::addChildren(Component& C)
{
    this->childrens.push_back(C);
    this->numOfChildrens++;
    return C.name;
}

std::string ParentComponent::getParentName() const
{
    return this->name;
}

bool ParentComponent::isParentVisible() const
{
    return this->isVisible;
}

bool ParentComponent::gotChildren() const
{
    return this->hasChildren;
}

bool ParentComponent::isEmpty(std::string)
{
    return this->childrens.size() == 0 ?  true : false;
}

std::vector<std::string> ParentComponent::getChildrenNames() const 
{
    std::vector<std::string> list;
    for(auto i : childrens)
    {
        list.push_back(i.name);
    }
    return list;
}

/*
 new UDT 4:
 */
struct DefaultGuiApp
{   
    GuiApplication myApp;
    Component button;

    DefaultGuiApp();
    ~DefaultGuiApp();
    JUCE_LEAK_DETECTOR(DefaultGuiApp)
};

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

/*
 new UDT 5:
 */

struct Plugin
{
    Component fader;
    Component label;
    Component slider;

    Plugin();
    ~Plugin();
    JUCE_LEAK_DETECTOR(Plugin)
};

Plugin::Plugin()
{
    std::cout << "Plugin is being initalized!" << std::endl;
}

Plugin::~Plugin()
{
    std::cout << "Plugin is being Terminated!" << std::endl;
}

struct ComponentWrapper
{
    Component* comp = nullptr;

    ComponentWrapper(Component*);
    ~ComponentWrapper();
};

ComponentWrapper::ComponentWrapper(Component* ptr) : comp(ptr)
{

}

ComponentWrapper::~ComponentWrapper()
{
    delete this->comp;
}

struct ParentComponentWrapper
{
    ParentComponent* pcomp = nullptr;

    ParentComponentWrapper(ParentComponent*);
    ~ParentComponentWrapper();
};

ParentComponentWrapper::ParentComponentWrapper(ParentComponent* ptr) : pcomp(ptr)
{

}

ParentComponentWrapper::~ParentComponentWrapper()
{
    delete this->pcomp;
}

struct GuiApplicationWrapper
{
    GuiApplication* guiapp = nullptr;

    GuiApplicationWrapper(GuiApplication*);
    ~GuiApplicationWrapper();
};

GuiApplicationWrapper::GuiApplicationWrapper(GuiApplication* ptr) : guiapp(ptr)
{

}

GuiApplicationWrapper::~GuiApplicationWrapper()
{
    delete this->guiapp;
}
// ===================================================================
struct DefaultGuiAppWrapper
{
    DefaultGuiApp* dguiapp = nullptr;

    DefaultGuiAppWrapper(DefaultGuiApp*);
    ~DefaultGuiAppWrapper();
};

DefaultGuiAppWrapper::DefaultGuiAppWrapper(DefaultGuiApp* ptr) : dguiapp(ptr)
{

}

DefaultGuiAppWrapper::~DefaultGuiAppWrapper()
{
    delete this->dguiapp;
}

struct PluginWrapper
{
    Plugin* plugin = nullptr;

    PluginWrapper(Plugin*);
    ~PluginWrapper();
};

PluginWrapper::PluginWrapper(Plugin* ptr) : plugin(ptr)
{
    
}

PluginWrapper::~PluginWrapper()
{
    delete this->plugin;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

int main()
{

    std::cout << "=============== Creating a New GUI App ==============" << std::endl;
    DefaultGuiAppWrapper app(new DefaultGuiApp); 
    app.dguiapp->button.setVisibility(false);
    std::cout << "=============== Creating a New Plugin App ===========" << std::endl;
    PluginWrapper plug(new Plugin); 
    plug.plugin->fader.setPosition(200,200);
    plug.plugin->slider.setComponentName("VerticalSlider");
    plug.plugin->label.setComponentName("Label1");
    std::cout << "================= Part 2 | this keyword =================" << std::endl;
    std::cout << plug.plugin->label.name << std::endl;
    plug.plugin->label.getComponentName();
    std::cout << plug.plugin->slider.name << std::endl;
    plug.plugin->slider.getComponentName();
    std::cout << app.dguiapp->myApp.getWindowTitle() << std::endl;
    std::cout << app.dguiapp->myApp.windowTitle << std::endl;

    
    std::cout << "good to go!" << std::endl;
}
