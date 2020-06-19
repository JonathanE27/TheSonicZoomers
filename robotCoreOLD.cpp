
#include "robot.hpp"
int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	int error = 0;
	double proportion = 0.2;
    double vLeft = 30.0;
    double vRight = 30.0;
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
    //Sets up the code for taking a picture for the camera. The picture detects the white line which makes the robot follow the line
    while(1){
		takePicture();
		for(int i = 0; i <150; i++){
			int pix = get_pixel(cameraView,50,i,3);
			int isWhite = 0;
			if (pix > 250) {
				isWhite = 1;
				error = error +(i-75);
				} 
			else {isWhite=0;}
			//Print out isWhite 
			std::cout<<isWhite<<" ";
		}
		//Print out the error in the tansmission window
		std::cout<<error<<std::endl;
		vLeft = 30.0;
		vRight = 30.0;
			
		//If the error value is greather then 0, make the robot turn left					
		if (error > 0 ){
			vLeft = 30.0 + (proportion * error);
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
      std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
      
  } //while

} // main
