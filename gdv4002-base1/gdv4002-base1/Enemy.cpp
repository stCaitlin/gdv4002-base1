#include "Enemy.h"

Enemy::Enemy(
	glm::vec2 initPosition,
	float initOrientation,
	glm::vec2 initSize,
	GLuint initTextureID,
	float initialPhase,
	float initialPhaseVelocity)
	: GameObject2D(initPosition, initOrientation, initSize, initTextureID) {
	phaseAngle = initialPhase;
	phaseVelocity = initialPhaseVelocity;
}

void Enemy::update(double tDelta) {

	// set position based on phase angle
	position.y = sin(phaseAngle);

	// update phase angle based on phase velocity * time elapsed
	phaseAngle += phaseVelocity * tDelta;
}