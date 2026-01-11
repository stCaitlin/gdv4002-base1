#include "Player.h"
#include "Keys.h"
#include <bitset>

extern std::bitset<5> keys;
extern glm::vec2 gravity;

Player::Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass) 
: GameObject2D(initPosition, initOrientation, initSize, initTextureID) {
	
	this->mass = mass;

	velocity = glm::vec2(0.0f,0.0f); //default to 0 velocity 

}

void Player::update(double tDelta) {
	
	glm::vec2 F = glm::vec2(0.0f,0.0f);

	const float thrust = 2.0f;

	//1.accumulate forces 
	if (keys.test(key::W) == true) {
		
		F += glm::vec2(0.0f,thrust);
	}
	if (keys.test(key::S) == true) {

		F += glm::vec2(0.0f, -thrust);
	}
	if (keys.test(key::A) == true) {

		F += glm::vec2(-thrust, 0.0f);
	}
	if (keys.test(key::D) == true) {

		F += glm::vec2(thrust, 0.0f);

		F += gravity;
	}


	//2.calculate acceleration. if f=ma, a = f/m
	glm::vec2 a = F*(1.0f/mass);


	//3.integrate to get new velocity
	velocity = velocity + (a*(float)tDelta);

	//4.integrate to get new position
	position = position + (velocity*(float)tDelta);
	}



