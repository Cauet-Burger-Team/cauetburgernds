#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <time.h>


#include "burgos.hpp"
#include "burger.hpp"
#include "function.hpp"


extern int win;
extern int flor;
int tim;

void minigame1(){
	NF_PlayRawSound(1, 127, 64, false, 0);
	NF_HideBg(1, 0);
	tim = 210 - flor*6;
	win = -2;
	NF_MoveSprite(1, 0, 0*64, 192);
	NF_MoveSprite(1, 1, 1*64, 192);
	NF_MoveSprite(1, 2, 2*64, 192);
	NF_MoveSprite(1, 3, 3*64, 192);
	
	Burger bj0(4, 0);
	Burger bj1(5, 0);
	Burger bj2(6, 1);
	Burger bj3(7, 1);
	for(int i = 0; i < tim; i++){
		bj1.Check();
		bj2.Check();
		bj3.Check();
		bj0.Check();
		
		if(bj2.condition == true){
			win += 1;
			bj2.condition = false;
		}
		if(bj0.condition == true){
			win -= 4;
			bj0.condition = false;
		}
		if(bj1.condition == true){
			win -= 4;
			bj1.condition = false;
		}
		if(bj3.condition == true){
			win += 1;
			bj3.condition = false;
		}
		mainLoop();
		burgosLoop();
	}
	bj1.end();
	bj2.end();
	bj3.end();
	bj0.end();
	soundKill(0);
}