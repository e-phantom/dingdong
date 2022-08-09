#include <stdlib.h>
#include "screen_config.h"

#define BALL_RADIUS 15

class Ball{

private:

	int position[COORDINATES];
	int velocity[COORDINATES];
	int *x,*y;
	int *vx,*vy;

	short step;

	void initVelocity(){

		// Directing the pointers to Velocity
		vx = &velocity[0];
		vy = &velocity[1];

		// initialize random positions

		*vx = rand() % STEP ;
		*vy = rand() % STEP ;

	}


	void initPosition(){

		// Directing the pointers to positions
		this->x = &position[0];
		this->y = &position[1];

		// initialize random velocities
		*this->x = rand() % DISPLAY_WIDTH;
		*this->y = rand() % DISPLAY_HEIGHT;
	}

public:

	Ball(){

		this->step = STEP;

		// Preset the values of velocity and position vectors
		this-> initPosition();
		this-> initVelocity();


	}

	int * getPosition(){
		return position;
	}

	int * getVelocity(){
		return velocity;
	}

	void next(){
		*this->x = *this->x + *this->vx;
		*this->y = *this->y + *this->vy;
	}
};

