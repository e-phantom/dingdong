
#include "screen_config.h"

#define PLATFORM_WIDTH 70
#define PLATFORM_HEIGHT 10

#define PLATFORM_MID_MARGINE 15

enum PlatformPosition { platform_left, platform_mid, platform_right};

class Platform{

private:
	int position[COORDINATES];
	int *x,*y;

public:

	Platform(){
		this->x = this->position;
		this->y = this->position+1;

		*this->x  = DISPLAY_WIDTH/2;
		*this->y = DISPLAY_HEIGHT - PLATFORM_HEIGHT;
	}

	bool isPlatformHit(int x,int y, int radius){
		static int yball;
		yball= y+radius;

		if ( yball >=  *this->y &&
					(x+radius >= *this->x &&
							x-radius <= *this->x+PLATFORM_WIDTH) ){
			return true;
		}else{
			return false;
		}
	}


	int getPlatformMidPosition(){
		return *this->x + PLATFORM_WIDTH / 2;
	}


	PlatformPosition getPlatformHitPosition(int x){
		static int mid;
		mid = getPlatformMidPosition();

		if (x >= mid - PLATFORM_MID_MARGINE && x<= mid + PLATFORM_MID_MARGINE){
			return platform_mid;
		}else if( x < mid - PLATFORM_MID_MARGINE){
			return platform_left;
		}else{
			return platform_right;
		}
	}

	int *  getPlatformPosition(){
		return position;
	}

	void movePlatform(PlatformPosition platform_position){
		int nextMove;

		if(platform_position == platform_left){
			nextMove = *x- STEP;
			if(nextMove > 0){
				*x = nextMove;
			}
		}else if(platform_position == platform_right){
			nextMove = *x +STEP;
			if(nextMove+PLATFORM_WIDTH < DISPLAY_WIDTH){
				*x = nextMove;
			}
		}else{
			// Do nothing
		}
	}

};
