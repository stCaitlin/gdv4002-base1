#include "Engine.h"


// Function prototypes

void myUpdate(GLFWwindow* window, double tDelta);

void myKeyboardHandler(GLFWwindow*window,int key, int scancode, int action, int mods);

// Global Variables


int main(void) {
//main function body

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}


	//
	// Setup game scene objects here
	
	//addObject("player1", glm::vec2(-1.5f, 1.0f), glm::radians(-30.0f), glm::vec2(1.0f, 1.0f), "Resources\\Textures\\bumblebee.png");
	//addObject("player2", glm::vec2(-1.5f, 1.0f), glm::radians(45.0f), glm::vec2(1.0f, 1.0f), "Resources\\Textures\\bumblebee.png");


	addObject("player", glm::vec2(-1.5f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), "Resources\\Textures\\player1_ship.png");

	addObject("enemy", glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(0.75f, 0.75f), "Resources\\Textures\\alien01.png");
	addObject("enemy", glm::vec2(1.0f, 0.0f), 0.0f, glm::vec2(0.75f, 0.75f), "Resources\\Textures\\alien01.png");
	addObject("enemy", glm::vec2(2.0f, 0.0f), 0.0f, glm::vec2(0.75f, 0.75f), "Resources\\Textures\\alien01.png");




	
	//
	// Set callback functions
	//

	setUpdateFunction(myUpdate);


	listGameObjectKeys();
	listObjectCounts();

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}

float enemyPhase[3] = { 0.0f, 0.0f, 0.0f }; 
float enemyPhaseVelocity[3] = { glm::radians(90.0f), glm::radians(90.0f), glm::radians(90.0f) };

void myUpdate(GLFWwindow* window, double tDelta) {

GameObjectCollection enemies = getObjectCollection("enemy");

//float player1RotationSpeed=glm::radians(90.0f);
//GameObject2D*player1=getObject("player1");
//player1->orientation = player1->orientation + glm::radians(90.0)*tDelta;
}








