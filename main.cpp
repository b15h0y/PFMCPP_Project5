/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12
 Create a branch named Part1
Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 
Since you didn't do Project 3:
write 3 UDTs below (where it asks for Copied UDTs) that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
 
 4) add 2 new UDTs that use only the types you copied above as member variables.
 
 5) Add destructors to these 2 new types that do something.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) use at least 2 instances of each of your UDTs in main. 
        add some std::cout statements in main() that use your UDT's member variables.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
If you need inspiration for what to write, take a look at previously approved student projects in the Slack Workspace channel for this project part.
 */


#define DEFAULT_WINDOW_NAME  "Untitled"
#define  D_HEIGHT 200
#define  D_WIDTH 200

#include <iostream>
#include <utility>
#include <vector>

/** 
** NOTE: I DID NOT WRITE "USING NAMESPACE ... " CAUSE IT'S NOT A GOOD HABIT GENERALLY.
** HOWEVER IT WILL MAKE THE CODER A BIT EASIER TO READ
**/

typedef unsigned int posInt;

int len(posInt *a) 
{
  return (sizeof(a)/sizeof(a[0]));
}
/*
 UDT 1:
 */
struct Component 
{
  posInt pos[2];
  float rotationAngle;
  bool isVisible=true;
  std::string name;
  
  Component();
  Component(const Component&A);
  ~Component();
  void setComponentName(std::string);
  void setVisibility(bool);
  void setRotation(float);
  void setPosition(posInt,posInt);
  void destroyComponent(); 
  private:
    posInt memoryAddress;
};

Component::Component(): pos{0,0}, rotationAngle(0.0), name("ComponentName")
{
  std::cout << "a Component has been initialized!" << std::endl;
}
Component::Component(const Component&A)
{ //Copy Constructor
  this->rotationAngle = A.rotationAngle;
  for (int i =0; i < len(this->pos); ++i)
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
  this->name=n;
}
void Component::setVisibility(bool n)
{
  this->isVisible=n;
}
void Component::setRotation(float n)
{
  this->rotationAngle=n;
}
void Component::setPosition(posInt _X,posInt _Y)
{
  // Just for the sake of the assignment requirments..
  for (int i=0; i < len(this->pos); ++i)
  {
    i==0 ? this->pos[i] = _X : i==1 ? this->pos[i] = _Y : throw std::runtime_error("Unexpected Error Occured!");
  }
}
void Component::destroyComponent()
{
  this->memoryAddress=0x0;
}

/*
 UDT 2:
 */
struct guiApplication 
{
  std::string windowTitle;
  std::pair <size_t, size_t> windowSize;
  bool isResizable;
  bool isVisible = true;
  const bool showButtons[3] = {true,true,true};
  std::vector<Component> componentsList; //NESTED

  guiApplication();
  ~guiApplication();

  /****
  ***** Setter Methods
  ****/
  void setWindowTitle(std::string S = DEFAULT_WINDOW_NAME);
  void setWindowSize(size_t W=D_WIDTH , size_t H=D_HEIGHT);
  void setResizable(bool);
  void setVisibile(bool);
  void addComponent(Component&);
  
  /****
  ***** Getter Methods
  ****/
  std::string getWindowTitle() const;
  std::vector <std::string> getComponentsListNames() const;
  std::pair <size_t, size_t> getWindowSize() const;
};

guiApplication::guiApplication(): windowTitle(DEFAULT_WINDOW_NAME), isResizable(false) 
{
  this->windowSize.first = D_WIDTH;
  this->windowSize.second = D_HEIGHT;
}
guiApplication::~guiApplication()
{
  std::cout << "a GUI App will be destoyed!" << std::endl;
}
void guiApplication::setWindowTitle(std::string S)
{
  this->windowTitle = S;
}
void guiApplication::setWindowSize(size_t W, size_t H){
  this->windowSize.first=W;this->windowSize.second=H;
}
void guiApplication::setResizable(bool n)
{
  this->isResizable = n;
}
void guiApplication::setVisibile(bool n)
{
  this->isVisible = n;
}
std::string guiApplication::getWindowTitle() const 
{
  return this->windowTitle;
}
std::vector<std::string> guiApplication::getComponentsListNames() const 
{
  std::vector<std::string> list;
  for (size_t i = 0; i < this->componentsList.size(); ++i)
  {
    list.push_back(componentsList[i].name);
  }
  return list;
}
std::pair<size_t, size_t> guiApplication::getWindowSize() const {
  return this->windowSize;
}
void guiApplication::addComponent(Component& C)
{
  this->componentsList.push_back(C);
}

/*
 UDT 3:
 */
struct parentComponent
{
  std::vector<Component> childrens; //NESTED
  std::string name;
  bool hasChildren = false;
  bool isVisible = true;
  posInt numOfChildrens;

  /****
  ***** Constructor | Destructor
  ****/
  parentComponent();
  ~parentComponent();

  /****
  ***** Setter Methods
  ****/
  std::string addChildren(Component&);
  std::string setParentName(std::string);
  
  /****
  ***** Getter Methods
  ****/
  std::string getParentName() const;
  std::vector <std::string> getChildrenNames() const;
  bool isParentVisible() const;
  bool gotChildren() const;

  /****
  ***** Utils Methods
  ****/
  bool isEmpty(std::string);
};


parentComponent::parentComponent():name("Untitled-DEFAULT"),numOfChildrens(0)
{

}
parentComponent::~parentComponent()
{
  std::cout << "a Parent will be destoyed!" << std::endl;
}

std::string parentComponent::addChildren(Component& C)
{
  this->childrens.push_back(C);
  this->numOfChildrens++;
  return C.name;
}



std::string parentComponent::getParentName() const
{
  return this->name;
}
bool parentComponent::isParentVisible() const
{
  return this->isVisible;
}
bool parentComponent::gotChildren() const
{
  return this->hasChildren;
}
bool parentComponent::isEmpty(std::string)
{
  return this->childrens.size()==0 ?  true : false;
}

std::vector<std::string> parentComponent::getChildrenNames() const 
{
  std::vector<std::string> list;
  for (size_t i = 0; i < this->childrens.size(); ++i)
  {
    list.push_back(childrens[i].name);
  }
  return list;
}

/*
 new UDT 4:
 */
struct DefaultGuiApp
{
  Component button;
  DefaultGuiApp();
  ~DefaultGuiApp();
  private:
    guiApplication myApp;
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
