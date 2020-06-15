#include <iostream>
#include "robot.hpp"
using namespace std;
	int x = 0;
    int y = 0;
    int error = 0;
    double vLeft = 30.0;
    double vRight = 30.0;
	double proportion = 0.2;
	bool running = true;
    
    int findPix(){
	    int size = 150;
    double values[size];
    double black [size];
	  for(int i = 0; i <150; i++){
			int pix = get_pixel(cameraView,50,i,3);
			int isWhite = 0;
		    int isBlack = 0;
			if (pix > 250) {
			isWhite = 1;
				error = error +(i-90);
				} 
			else {isWhite=0;}
			if (pix == 0){ isBlack = 1;
				running = false;}
			else{isBlack = 0;}
			values[i] = isWhite;
			black[i] = isBlack;
			cout<<values[i]<<std::endl; 
		//std::cout<<isWhite<<" ";
	   // std::cout<<isBlack<<" ";
        y = std::distance(black, std::find(values, black + size, 1));		cout<<x<<std::endl; //find black values
        x = std::distance(values, std::find(values, values + size, 1));		cout<<x<<std::endl; //find white values

			//Print out isWhite 
			//std::cout<<isWhite<<" ";
		}
		//Print out the error in the tansmission window
		//std::cout<<error<<std::endl;
		vLeft = 30.0;
		vRight = 30.0;
	  }
	  
int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    //Sets up the code for taking a picture for the camera. The picture detects the white line which makes the robot follow the line
    while(running){
		takePicture();
		findPix();
		
		// if the error value is less than zero, & a white pixle is detected in front, turn left.
     	 if((error<0)&&((x<114) && (52<x)) && (error<0)){vRight = 60;} // If white Left And Front & right, turn right.
	    // If neither white Left And Front & right, turn arround left.
	    if(!((error<0)&&((x<114) && (52<x)) && (error<0))){
			  if ((y<114) && (52<y)){
		 vLeft = 40; 
		 vRight = 40;} else{
			vLeft = 60;}
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
	  }
  
}
