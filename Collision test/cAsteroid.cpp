/*
=================
cAsteroid.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cAsteroid.h"
//I have made a change
/*
=================================================================
Defualt Constructor
=================================================================
*/
cAsteroid::cAsteroid() : cSprite()
{
	this->asteroidVelocity = { 1, 1 };

}
/*
=================================================================
Update the sprite position
=================================================================
*/
	int xPos = 2;
	int negXPos = -2;
	int yPos = 3;
	int negYPos = -3;
	int X = xPos;
	int Y = yPos;
void cAsteroid::update(double deltaTime)
{

	this->setSpriteRotAngle(this->getSpriteRotAngle() +(5.0f * deltaTime)); 
	if (this->getSpriteRotAngle() > 360)
	{
		this->setSpriteRotAngle(this->getSpriteRotAngle() -360);
	}



	SDL_Rect currentSpritePos = this->getSpritePos();
	if (currentSpritePos.x > 0 && currentSpritePos.y > 0 && currentSpritePos.x < 870 && currentSpritePos.y < 670)
	{
	currentSpritePos.x += this->asteroidVelocity.x * deltaTime + X;
	currentSpritePos.y += this->asteroidVelocity.y * deltaTime + Y;
	}
	else
	{
		if (X = xPos)
		{
			X = negXPos;
			Y = negYPos;
		}
		else
		{
			X = xPos;
			Y = yPos;
		}
	}

	this->setSpritePos({ currentSpritePos.x, currentSpritePos.y });
	cout << "Asteroid position - x: " << this->getSpritePos().x << " y: " << this->getSpritePos().y << " deltaTime: " << deltaTime << endl;
	this->setBoundingRect(this->getSpritePos());
}
/*
=================================================================
  Sets the velocity for the Asteroid
=================================================================
*/
void cAsteroid::setAsteroidVelocity(SDL_Point AsteroidVel)
{
	asteroidVelocity = AsteroidVel;
}
/*
=================================================================
  Gets the Asteroid velocity
=================================================================
*/
SDL_Point cAsteroid::getAsteroidVelocity()
{
	return asteroidVelocity;
}
