#include "Engine.h"
#include "Keys.h"
#include "Player.h"
#include "Enemy.h"
//#include "glPrint.h"

#include <bitset>

// Function prototypes
//void myRender(GLFWwindow*window);
void myKeyboardHandler(GLFWwindow*window, int key, int scancode, int action, int mods);

// Global Variables
std::bitset<5> keys{ 0x0 }; // Bit flags to track which keys are currently pressed 
glm::vec2 gravity = glm::vec2(0.0f,-1.0f);


int main(void) {
//main function body

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}
	/*GLuint myFontNormal = 0;
	GLuint myFontUnderline = 0;

	myFontNormal = glBuildFont(L"Consolas",24);
	myFontUnderline = glBuildFont(L"Aptos",24, GLFONT_STYLE::BOLD | 
	GLFONT_STYLE::UNDERLINE);*/

	//
	//setup rendering properties (enable blending)
	//
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_ALWAYS);


	//0.Load player texture and create player object
	GLuint playerTexture = loadTexture("Resources\\Textures\\player1_ship.png");
	Player*mainPlayer = new Player(glm::vec2(-1.5f,0.0f),0.0f,glm::vec2(0.5f,0.5f),playerTexture,1.0f);
	addObject("player",mainPlayer);

	
	//1.Load enemy texture 
	GLuint enemyTexture = loadTexture("Resources\\Textures\\Alien02.png");

	//2.Create enemy objects 
	Enemy*enemy1 = new Enemy(glm::vec2(0.0f,0.0f),0.0f,glm::vec2(0.5f,0.5f), enemyTexture, 0.0f,glm::radians(45.0f));

	Enemy* enemy2 = new Enemy(glm::vec2(1.0f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), enemyTexture, 0.0f, glm::radians(90.0f));

	Enemy* enemy3 = new Enemy(glm::vec2(2.0f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), enemyTexture, 0.0f, glm::radians(60.0f));

	//add enemy objects to the engine 
	addObject("enemy1",enemy1);
	addObject("enemy2", enemy2);
	addObject("enemy3", enemy3);

	//
	// Set callback functions
	//
	setKeyboardHandler(myKeyboardHandler);
	//setRenderFunction(myRender);

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}


//void myRender(GLFWwindow* window) {
////render code here...
//
//glSetCurrentFont(GL_FONT_UNDERLINE_THICKNESS_BIT_NV);
//glColor3f(1.0f, 1.0f, 1.0f);
//glRasterPos2f(0.0f, 0.0f);
//glPrint("Hello,World");
//
//}


void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods) {
	// check if the key was just pressed 
	if (action == GLFW_PRESS) {
		 
		 //now check which key was pressed 
		switch (key)
		{
			case GLFW_KEY_ESCAPE:
				//If esacpe is pressed tell GLFW we want to close the window (and quit)
				glfwSetWindowShouldClose(window,true);
				break;


			case GLFW_KEY_W:
				keys[key::W] = true;
				break;

			case GLFW_KEY_S:
				keys[key::S] = true;
				break;

			case GLFW_KEY_D:
				keys[key::D] = true;
				break;

			case GLFW_KEY_A:
				keys[key::A] = true;
				break;

			case GLFW_KEY_SPACE:
				keys[key::SPACE] = true;
				break;
			}
		
		}
		// if not pressed, check the key has just been released 
		else if (action == GLFW_RELEASE) {

			//handle key release events 
		switch (key)
		{
			case GLFW_KEY_W:
			keys[key::W] = false;
			break;

			case GLFW_KEY_S:
				keys[key::S] = false;
				break;

			case GLFW_KEY_D:
				keys[key::D] = false;
				break;

			case GLFW_KEY_A:
				keys[key::A] = false;
				break;

			case GLFW_KEY_SPACE:
				keys[key::SPACE] = false;
				break;
			}
		 }
	}



