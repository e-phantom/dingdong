#include "disp.h"

int main(){

	Disp disp;
	disp.setup_display();

	while(1){
		disp.renderScreen();
	}

	return 0;
}
