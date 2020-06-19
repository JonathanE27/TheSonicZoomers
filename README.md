# TheSonicZoomers
AVC Project 3

# Install Instructions
# Linux Install AVC Program
1.	Install geany by opening the terminal and typing: sudo apt-get install geany
2.	Then after type: sudo apt-get install g++
3.	Then download the Linux SMFL library from either the GitHub or the website: https://www.sfml-dev.org/download/sfml/2.5.1/ 
4.	Go to your downloads folder and extract the SMFL library
5.	Download the Linux version of the AVC program from: https://github.com/JonathanE27/TheSonicZoomers called: ”AVC_Linux.tar.gz”
6.	Extract the files from github  go to the AVC  robot and server files and for each locate the make files and Open the make file with geany and change the path in the make file for the robot and server to your usernames download folder where is says SFML = *file path to your downloads* 
7.	Then located in the AVC robot and AVC server files then find the robot and server.cpp files in their respective folders then open the robot.cpp and server.cpp file in Geany by right clicking and selecting open with and select geany.
8.	For each cpp file click build at the top and then make for both files
9.	Then press F5 or go to build at the top and then click execute for the server first then the robot.

# Install for Mac
To install SFML libraries on a Mac:

First of all, make sure Geany is installed and runs properly.

If Geany is not installed, go to the website ‘https://www.geany.org’ and follow the download instructions on the home page.

Type/ paste the following into your terminal window to install homebrew:
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
If the terminal becomes stuck at the command line tools for Xcode, go to your system preferences, then software updates, and install any pending updates. This should fix the problem 
Once homebrew is installed, type the following into the terminal:
brew install sfml
Next, open Geany and go to the menu bar. Go to Build, then Set Build Commands. Under C++ commands, on the Build option, paste the following flags at the end of the existing commands:
-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
The command line should then look like this:
 g++ -Wall -o "%e" "%f" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
Once all these steps have been completed, extract the robot and server files through the AVC_Mac file. Click the compile, build and execute buttons for the robot and server files to test they are working. To change between the mazes for core, completion and challenge, go to the config.txt in the server folder. And change between core.txt, completion.txt and challenge.txt.

# Install instructions for Windows
To be able to do Project 3 on Windows there was a different process to install the necessary files compared to Linux and Mac.

To do the coding for the project, Geany and MinGW must be installed. MinGW and Geany work in cohesion to allow the user to write the code and execute. To install Geany and MinGW this can be found on their website. For Geany you would download the Windows version if using windows. Like Geany, do the same for MinGW and download the windows version.

To start getting the necessary files for the project the first thing that needs to be downloaded is off https://www.sfml-dev.org/download/sfml/2.5.1/. There will be options of what to download and the option that should be picked is the MinGW version. It is up to the user whether they download the 32-bit version or the 64-bit version.

Once that is done, the user should download the other following file from the GitHub which is the Project 3 windows version. This should include the following files:
Project 3 Windows version.rar
SFML.zip

These folders will be in a zip version and therefore, will need to be extracted to access and use the files. These files have been zipped using a software called WinRAR. https://www.win-rar.com/download.html?&L=0  
Using this website, download WinRAR. Using this you can unzip the compressed folder

Following the download of these files, the user must do additional changes to the folders. dll files from the bin folder which is located in the MinGW folder had to be put into the AVC_robot and AVC_server folder. As well as that additional dll files within the SFML folder have to be put into AVC_robot and AVC_server. This can be found within the bin folder of the SFML folder. 

With all of that sorted out it is time to make sure that the code builds and runs. Within Geany and underneath ‘build’ there is another button called ‘set build commands’. Within that there must be a change in ‘Make’. This must be changed to the following below.
 
If this is done correctly, then the code will be able to run properly.
To execute the code to see the code run there are a few things that need to be done. Firstly on the server code do the following:
 
Press the arrow next to build and press make all. If it says compilation successful in the bottom left corner of the screen, it means that there are no errors in the code allowing the user to press execute.
 
Three screens come up showing what the server code is reading as well as the camera view tab which shows what the camera is showing and the maze for whatever maze is selected. Once that is done go to the robot code and repeat the said instructions. Once this is done, the user should be able to see the robot moving on the screen.
