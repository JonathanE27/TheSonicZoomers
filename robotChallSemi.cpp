#include <iostream>
#include "robot.hpp"
using namespace std;
	int x = 0;
    int y = 0;
    double leftturn = 0.0;
    int r = 0;
    int g = 0;
    int error = 0;
    int greenerror = 0;
    double vLeft = 30.0;
    double vRight = 30.0;
	double proportion = 0.2;
	bool running = true;
   int isRed = 0;
   int isWhite = 0;
   int isBlack = 0;
   int isGreen = 0;
   bool redturn = true;
    int findPix(){
		
	    int size = 150;
    double values [150];
    double black [150];
    double red [150];
    double green[150];
    int redchecker = 0;
	//for(int j = 0; j<100;j++){
	  for(int i = 0; i <150; i++){
			int pix = get_pixel(cameraView,50,i,3);
			int redPix = get_pixel(cameraView,50,60,0);
			int greenPix = get_pixel(cameraView,50,i,1);
			int bluePix = get_pixel(cameraView,50,i,2);
			   //cout<<redPix<<std::endl;
			   //cout<<greenPix<<std::endl;
			   //cout<<bluePix<<std::endl;
			  if(greenPix > 2*redPix && redPix>2*bluePix){
				isGreen = 1;
				error = error +(i-20);
				//cout<<error<<std::endl;
				}
				else{
					isRed = 0;
					//cout<<isRed<<std::endl;
					}
			if(redPix > 2*greenPix && redPix>2*bluePix){
				isRed = 1;
				error = error +(i-20);
				//cout<<error<<std::endl;
				}
				else{
					isRed = 0;
					//cout<<isRed<<std::endl;
					}
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
			red[i] = isRed;
			cout<<"error"<<error<<std::endl;

			//cout<<values[i]<<std::endl; 
		//std::cout<<isWhite<<" ";
	   // std::cout<<isBlack<<" ";
        y = std::distance(black, std::find(black, black + size, 1));		//cout<<x<<std::endl; //find black values
        x = std::distance(values, std::find(values, values + size, 1));		//cout<<x<<std::endl; //find white values
		r = std::distance(red, std::find(red, red + size, 1));	// //find white values
	//	cout<<r<<std::endl;
		//for ( int i = 0; i < 100; i++){
      //for ( int j = 0; j < 150; j++ ) {
		
         
      //}
  //}
			//Print out isWhite 
			//std::cout<<isWhite<<" ";
		}
	//}
		//Print out the error in the tansmission window
		//std::cout<<error<<std::endl;
		vLeft = 30.0;
		vRight = 30.0;
	  }
	  
	  int followLine(){
		   while(1){
		//Sets up the code for taking a picture for the camera. The picture detects the white line which makes the robot follow the line
		takePicture();
		
		findPix();
		
		// if the error value is less than zero, & a white pixle is detected in front, turn left.
     	 if((error<0)&&((x>114) && (52<x)) && (error<0)){vRight = 60;} // If white Left And Front & right, turn right.
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
  while(1){
	  vRight = 0;
	  vLeft = 0;
	  setMotors(vLeft,vRight); 
	  }
		  }
		  
		  
		  int followLineRed(){
			  while(1){
				takePicture();
				findPix();
				
			  // if the error value is less than zero, & a white pixle is detected in front, turn left.
        //  if(error > 1000){vLeft = 60; vRight=60;}
            
			std::cout<<" red ="<<r<<std::endl;
     	 if((error > 440)){
		// vLeft=23.98895;
						vRight = 0; vLeft = 23.98895;
			//if(error == -189){break;}

			 } // If white Left And Front & right, turn right.
			 else if((error == 0)||(error > 3000)){
	       if(leftturn < 19){
			   vRight=20; vLeft=20;
			   leftturn++;
			   error =0;
			   }
	
	       else{
			   for(int i = 0;i<5;i++){
				    vLeft = 40; vRight =40;
				   setMotors(vLeft,vRight);
				   }
				   
			   vLeft = 0; vRight =330;//225.5;
			   setMotors(vLeft,vRight);
				for(int i = 0;i<8;i++){
					 vLeft = 40; vRight =40;
				   setMotors(vLeft,vRight);
					
					}
					vLeft = 0; vRight =340;//225.5;
			   setMotors(vLeft,vRight);
			   vLeft = 20; vRight =20;//225.5;
			   setMotors(vLeft,vRight);
			   
			   
			   //break;
					
			  }
	       //error = 1;
			}  
	    
	    else {vLeft = 60; vRight=60;
			error = 0;
			
			}
	    
	    
	    
	    
	  error = 0;
	  std::cout<<std::endl;
      setMotors(vLeft,vRight); 
      //std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
			  
		  }
		  while(1){
	  vRight = 0;
	  vLeft = 0;
	  setMotors(vLeft,vRight); 
	  }
			  
			  }
	  
int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
	
   //followLine();
  followLineRed();
}
