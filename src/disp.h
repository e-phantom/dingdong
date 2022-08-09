#include "MyDisp.h"

#include "ball.h"
#include "platform.h"

#define BALL_DEFLECT_SPEED_FACTOR 1.5;

class Disp{
private:
	Ball ball;
	Platform platform;

public:

	void setup_display() {
	   bool fStat;

	   while (true) {
	      fStat = mydisp.begin();
	      if (fStat) {
	         xil_printf("mydisp.begin() succeeded\n\r");
	         break;
	      }
	      else {
	         xil_printf("mydisp.begin() failed\n\r");
	      }
	   }
	}
	
	void drawBall(){
		int *x,*y;
		x = this->ball.getPosition();
		y = x+1;

		mydisp.drawEllipse(true, *x - BALL_RADIUS, *y - BALL_RADIUS, *x + BALL_RADIUS, *y + BALL_RADIUS);
	}


	void drawPlatform(){
		int *x,*y;
		x = this->platform.getPlatformPosition();
		y = x+1;

		mydisp.drawRectangle(true, *x, *y, *x+PLATFORM_WIDTH, *y+ PLATFORM_HEIGHT);
	}
	

	void next(){
		int *ball_x,*ball_y;
		int *ball_vx, *ball_vy;

		// Get the Ball Location
		ball_x = ball.getPosition();
		ball_y = ball_x+1;

		// Get the ball Speed
		ball_vx = ball.getVelocity();
		ball_vy = ball_vx + 1;

		// check if the side wall is hit
		if(*ball_x - BALL_RADIUS <= 0 || *ball_x + BALL_RADIUS >= DISPLAY_WIDTH){
			*ball_vx = - *ball_vx;
		}
		// Check if the ball hits the platform
		else if (platform.isPlatformHit(*ball_x, *ball_y, BALL_RADIUS)){
			// Check Where is it hit
			PlatformPosition platform_hit_position = platform.getPlatformHitPosition(*ball_x);

			if(platform_hit_position == platform_mid){

			}else if(platform_hit_position == platform_left){
				*ball_vx = *ball_vx -  BALL_DEFLECT_SPEED_FACTOR;
			}else{
				*ball_vx = *ball_vx +  BALL_DEFLECT_SPEED_FACTOR;
			}
			*ball_vy = -1 * *ball_vy;
		}
		// Check if the ball hits the roof or floor
		else if ( (*ball_y + BALL_RADIUS >= DISPLAY_HEIGHT) || ( 0 >= (*ball_y) - BALL_RADIUS)  ){
			*ball_vy = -1 * *ball_vy;
		}
		else{

		}

		this->ball.next();
	}

	void renderScreen(){
		mydisp.clearDisplay(0);

		this->drawPlatform();
		this->drawBall();

		this->next();
	}

};
