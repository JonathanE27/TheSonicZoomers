#include <iostream>
#include "robot.hpp"
using namespace std;
	int x = 0;
    int y = 0;
    int R = 0;
    int error = 0;
    double vLeft = 30.0;
    double vRight = 30.0;
	double proportion = 0.2;
	bool running = true;
    
    int findPix(){
	    int size = 150;
    double values [100] [size];
    double black [100] [size];
    double red [100] [size];
		
	  for(int j = 0; j<100;j++)
	  for(int i = 0; i <150; i++){
		    int pix = get_pixel(cameraView,j,i,3);
		    int pixelred = get_pixel(cameraView,j,i,0);
		    int pixelgreen = get_pixel(cameraView,j,i,1);
		    int pixelblue = get_pixel(cameraView,j,i,2);
   
		    
            int isRed = 0;
            if(pixelred> 100){int isRed = 1;}
            else{isRed = 0;}
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
			values[j][i] = isWhite;
			black[j][i] = isBlack;
			red[j][i] = isRed;
			cout<<values[i]<<std::endl; 
		//std::cout<<isWhite<<" ";
	   // std::cout<<isBlack<<" ";
   //     y = std::distance(black, std::find(values, black + size, 1));		cout<<y<<std::endl; //find black values
       // x = std::distance(values, std::find(values, values + size, 1));		cout<<x<<std::endl; //find white values
       // R = std::distance(values, std::find(red, red + size, 1));		cout<<R<<std::endl; //find red values

			//Print out isWhite 
			//std::cout<<isWhite<<" ";
		 std::cout<<isRed<<"";
		// std::cout<<R<<"";
		}
		//Print out the error in the tansmission window
		//std::cout<<error<<std::endl;
		vLeft = 60.0;
		vRight = 60.0;
	  }
	  
int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    //Sets up the code for taking a picture for the camera. The picture detects the white line which makes the robot follow the line
  while(1){
  takePicture();
		findPix();
  
  if(R >= 150 ){
	  takePicture();
		findPix();
	
	if(R >= 150){vLeft = 0; vRight = 60;}
	

	
	
	}
	  
	  
	  
	  
	   else{
  
    while(running){
		
	
		takePicture();
		findPix();
		
		// if the error value is less than zero, & a white pixle is detected in front, turn left.
     	 if((error<0)&&((x<114) && (52<x)) && (error<0)){vRight = 60;} // If white Left And Front & right, turn right.
	    //If neither white Left And Front & right, turn arround left.
	    if(!((error<0)&&((x<114) && (52<x)) && (error<0))){
			  if ((y<114) && (52<y)){
		 vLeft = 80; 
		 vRight = 80;} else{
			}
		}
	 		if((error > 75)&&((x<114) && (52<x))){vLeft = 120;}

		//If the error value is greather then 75 and their is whuute directly in front, make the robot turn left.					
		if((error < 75)&&((x<114) && (52<x))){vRight = 120;}
		
		 if (error > 0){
			vLeft = 60.0 + abs(proportion * error);
			vRight = 60.0;
		}
		//If the error value is greater then 0, make the robot turn right
		if (error < 0) {
			vRight = 60.0 + abs(proportion * error);
			vLeft = 60.0;
		}
		if (vLeft > 160) {
			vLeft = 160;
		}
		if (vRight >160) {
			vRight = 1600;
		}
	  error = 0;
	  std::cout<<std::endl;
      setMotors(vLeft,vRight); 
      std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
  }}}
  if(!running){
	  vRight = 0;
	  vLeft = 0;
	  setMotors(vLeft,vRight); 
	  }
  
}
