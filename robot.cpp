#include <iostream>
#include "robot.hpp"
using namespace std;
	int x = 0;
    int y = 0;
    double leftturn = 0.0;
    int r = 0;
    int error = 0;
    int redError = 0;
    double vLeft = 30.0;
    double vRight = 30.0;
	double proportion = 0.2;
	bool running = true;
    
void findPix(){
	int isRed = 0;
	int isWhite = 0;
	int isBlack = 0;
	int size = 150;
    double values [size];
    double red [size];
    
	  for(int i = 0; i <150; i++){
			int pix = get_pixel(cameraView,50,i,3);
			int redPix = get_pixel(cameraView,50,60,0);
			int greenPix = get_pixel(cameraView,50,i,1);
			int bluePix = get_pixel(cameraView,50,i,2);
			
			if(redPix > 2*greenPix && redPix>2*bluePix){
				isRed = 1;
				redError = redError +(i-20);
				}
				else{
					isRed = 0;
					}
			if (pix > 250) {
			isWhite = 1;
				error = error +(i-90);
				} 
			else {isWhite=0;}
			if (pix == 0 && isRed == 0){ isBlack = 1;
				running = false;} 

			else{isBlack = 0;}
			values[i] = isWhite;
			red[i] = isRed;
        x = std::distance(values, std::find(values, values + size, 1));		//cout<<x<<std::endl; //find white values
		r = std::distance(red, std::find(red, red + size, 1));	// //find red values
	
		}
		vLeft = 30.0;
		vRight = 30.0;
	  }

void followLine(){
	while(running ==true){
		//Sets up the code for taking a picture for the camera. The picture detects the white line which makes the robot follow the line
		takePicture();

		findPix();

		// if the error value is less than zero, & a white pixle is detected in front, turn left.
     	if((error<0)&&((x>114) && (52<x)) && (error<0)){vRight = 60;} // If white Left And Front & right, turn right.
	    // If neither white Left And Front & right, turn arround left.
	    if(!((error<0)&&((x<114) && (52<x)) && (error<0))){
		
		if ((y<114) && (52<y)){
		 vLeft = 40; 
		 vRight = 40;} 
		 else{vLeft = 60;}
		}
		
	 	if((error > 75)&&((x<114) && (52<x))){vLeft = 60;}

		//If the error value is greather then 75 and their is whuute directly in front, make the robot turn left.					
		if((error < 75)&&((x<114) && (52<x))){vRight = 60;}

		if (error > 0){
			vLeft = 30.0 + abs(proportion * error);
			vRight = 30.0;
		}
		//If the error value is greater then 0, make the robot turn right
		if (error < 0) {
			vRight = 30.0 + abs(proportion * error);
			vLeft = 30.0;
		}
		if (vLeft > 80) {
			vLeft = 80;
		}
		if (vRight >80) {
			vRight = 80;
		}
	  error = 0;
	  std::cout<<std::endl;
      setMotors(vLeft,vRight); 
      //std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
  }
  if(!running){
	  vRight = 0;
	  vLeft = 0;
	  setMotors(vLeft,vRight); 
	  std::cout<<"Robot reached finish line"<<std::endl;
	  }
		  }


void followLineRed(){
	while(running){
		takePicture();
		findPix();	
		// if the error value is less than zero, & a white pixle is detected in front, turn left.
     	if((redError > 400)){
						vRight = 0; vLeft = 23.98895;
			 }
			 // If white Left And Front & right, turn right.
		else if((r==150)||(redError > 3000)){
	       
	    if(leftturn < 19){
			vRight=20; vLeft=20;
			leftturn++;
			redError =0;
		}

	   else{
		if(running){
			for(int i = 0;i<20;i++){
				vLeft = 40; vRight =40;
				setMotors(vLeft,vRight);
			}

			vLeft = 0; vRight =330;//225.5;
			setMotors(vLeft,vRight);
			for(int i = 0;i<8;i++){
				vLeft = 40; vRight =40;
				setMotors(vLeft,vRight);
			}
			vLeft = 0; vRight =338;//225.5;
			setMotors(vLeft,vRight);
			vLeft = 40; vRight =40;//225.5;
			setMotors(vLeft,vRight);
			}

		}
	}  

	else {vLeft = 60; vRight=60;
		redError = 0;	
		}
		redError = 0;
		std::cout<<std::endl;
		setMotors(vLeft,vRight); 
      //std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		  }
		  
	if(!running){
	  vRight = 0;
	  vLeft = 0;
	  setMotors(vLeft,vRight); 
	  std::cout<<"Robot reached finish line"<<std::endl;
	}
}
	
int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	std::cout<<"Enter 1 for Core and Completion, Enter 2 for challenge: "<<std::endl;
		int choice;
		std::cin>>choice;
		if(choice == 1){
			followLine();
		}
		if(choice == 2){
			followLineRed();
		}
}
