/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}



#define DEFAULT_WINDOW_NAME  "Untitled"
#define  D_HEIGHT 200
#define  D_WIDTH 200

#include <iostream>
#include <utility>
#include <vector>
#include <array>

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
    void setVisibility(bool);
    void setRotation(float);
    void setPosition(std::uint32_t,std::uint32_t);
    void destroyComponent(); 
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
private:
    GuiApplication myApp;
public:
    Component button;

    DefaultGuiApp();
    ~DefaultGuiApp();
};

DefaultGuiApp::DefaultGuiApp()
{
    std::cout << "Initializing a New Default GUI!" << std::endl;
    this->myApp.setResizable(true);
    this->myApp.addComponent(button);
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
};

Plugin::Plugin()
{
    std::cout << "Plugin is being initalized!" << std::endl;
}

Plugin::~Plugin()
{
    std::cout << "Plugin is being Terminated!" << std::endl;
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
    DefaultGuiApp App;
    App.button.setVisibility(false);
    std::cout << "=============== Creating a New Plugin App ===========" << std::endl;
    Plugin Plug;
    Plug.fader.setPosition(200,200);
    Plug.slider.setComponentName("VerticalSlider");
    Plug.label.setComponentName("Label1");

    
    std::cout << "good to go!" << std::endl;
}
