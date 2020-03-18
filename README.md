# ee520FinalProject
New public repository created for my final project for EEP 520 Software Engineering for embedded systems.

Goal of Project -

	The original goal of this project is to create a very complicated maze for a robot consisting of
	multiple sensors to find its way through a maze. Comparing the distance that the robot is from the 
	front, right, left to make a decision on when to stop moving forward and turn.

Key Challenges Description - 

	One of the biggest challenges I faced was the deeply time consuming efforts of creating a well layed
	out maze for the robot to be tested against. As I originally started with using blocks in the 
	homework 8. But once that was cancelled, I realized I could make it from the static objects. But
	still with that, it was very much a guess and check to make sure it perfectly lined up. 

	Second key challenge is getting the user to interact with the buttons in order to change specific
	characteristics of the robot such as location, or adding in a second robot with different speeds
	and calibrations for rotational speeds. There is very little  

How to Install and Run - 

	Clone the Repository to local computer 
	git clone https://github.com/kleist27/ee520FinalProject.git
	cd ../local directory
	docker run -p80:80 -p8765:8765 -v ${PWD}:/source -it klavins/enviro:alpha bash
	esm start
	make
	enviro

How to Run and/or Use the Project - 

	esm start
	make
	enviro
		- Robot will start at beginning of the maze and make it way through the maze

Sources of Information -

	Class Notes

Side Notes - 
	-------- Additions to the code that ended up not working ------------
	click "RESET" button 
		- Robot will restart robot at initial position
	click "ADD" button
		- An additional robot appears into the maze
	---------------------------------------------------------------------
