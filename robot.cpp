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
    int choice;
void findPix(){
	int isRed = 0;
	int isWhite = 0;
	int isBlack = 0;
	int size = 150;
    double values [size];
    double red [size];
    
	  for(int i = 0; i <150; i++){// goes through a loop scaning all of the pixels
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
			
			if (pix == 0 && isRed == 0 && choice == 2 || (pix==0 && choice == 1)){ isBlack = 1;
				running = false;} 
			else{isBlack = 0;}
			values[i] = isWhite;//places the white pixels in an array
			red[i] = isRed;//places the red pixels in an array
        x = std::distance(values, std::find(values, values + size, 1)); //finds the position of white pixels in the white array
		r = std::distance(red, std::find(red, red + size, 1));	//finds the position of the red pixels in the red array
	
		}
		vLeft = 30.0; // sets the inital speed
		vRight = 30.0;
	  }

void followLine(){
	while(running){//while(running) meand that as long as the robot has not detected any black the rest of the function will run
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
		//If the error value is greater then 75 and their is white directly in front, make the robot turn right.
	 	if((error > 75)&&((x<114) && (52<x))){vLeft = 60;}

		//If the error value is less then 75 and their is white directly in front, make the robot turn left.					
		if((error < 75)&&((x<114) && (52<x))){vRight = 60;}
        
        //if the error value is greater than 0, make thev robot turn right.         
		if (error > 0){
			vLeft = 30.0 + abs(proportion * error);
			vRight = 30.0;
		}
		//If the error value is greater then 0, make the robot turn left
		if (error < 0) {
			vRight = 30.0 + abs(proportion * error);
			vLeft = 30.0;
		}//if the robot is turning right higher than 80, reset its turning to 80.
		if (vLeft > 80) {
			vLeft = 80;
		}//if the robot is turning left higher than 80, reset its turning to 80.
		if (vRight >80) {
			vRight = 80;
		}
	  error = 0;// resets the error value
	  std::cout<<std::endl;
      setMotors(vLeft,vRight); 
      //std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
  }
  if(!running){// if the robot detects black, stops the program and prints a message.
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
	       // when no red is detected, for a period of time, the robot will continue to go forward.
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
          //after a period of time the robot will turn left
			vLeft = 0; vRight =330;//225.5;
			setMotors(vLeft,vRight);
			for(int i = 0;i<8;i++){
				vLeft = 40; vRight =40;
				setMotors(vLeft,vRight);
			}//after another set period of time, the robot will turn left again.
			vLeft = 0; vRight =338;//225.5;
			setMotors(vLeft,vRight);
			vLeft = 40; vRight =40;//225.5;
			setMotors(vLeft,vRight);
			}

		}
	}  
// resets the robots speed to 60, and has it go in a straight line.
	else {vLeft = 60; vRight=60;
		redError = 0;	
		}
		redError = 0;
		std::cout<<std::endl;
		setMotors(vLeft,vRight); 
      //std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		  }
		  
	if(!running){// if black is detected, stops the program and prints a message
	  vRight = 0;
	  vLeft = 0;
	  setMotors(vLeft,vRight); 
	  std::cout<<"Robot reached finish line"<<std::endl;
	}
}
	
int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}// Alows the use to choose which function will be used depending on the task. If the task is core or completion, 1 would be selected, and for challenge 2.
	std::cout<<"Enter 1 for Core and Completion, Enter 2 for challenge: "<<std::endl;
		std::cin>>choice;
		if(choice == 1){
			followLine();
		}
		if(choice == 2){
			followLineRed();
		}
}
