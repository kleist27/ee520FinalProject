# ee520FinalProject
New public repository created for my final project for EEP 520 Software Engineering for embedded systems.

Goal of Project -

	The original goal of this project is to create a very complicated maze for a robot consisting of
	multiple sensors to find its way through a maze. Comparing the distance that the robot is from the 
	front, right, left to make a decision on when to stop moving forward and turn.

	The robot will be moving its way from the top left of the maze to the bottom left, taking a 
	multitude of turns. 

Key Challenges Description - 

	One of the biggest challenges I faced was the deeply time consuming efforts of creating a well layed
	out maze for the robot to be tested against. As I originally started with using blocks in the 
	homework 8. But once that was cancelled, I realized I could make it from the static objects. But
	still with that, it was very much a guess and check to make sure it perfectly lined up. 

	Second key challenge is getting the user to interact with the buttons in order to change specific
	characteristics of the robot such as location, or adding in a second robot with different speeds
	and calibrations for rotational speeds. From the documentation I found I was unable to finally get
	it to fully function.

	Third challenge was I debated to have two wanderers go through the maze together but it seemed to 
	randomly get stuck which did not allow for a guarantee it will work for final assesment.

How to Install and Run - 

	Clone the Repository to local computer 
	git clone https://github.com/kleist27/ee520FinalProject.git
	cd ../local directory
	docker run -p80:80 -p8765:8765 -v ${PWD}:/source -it klavins/enviro:alpha bash
	esm init
	esm start
	make
	enviro

How to Run and/or Use the Project - 

	esm start
	make
	enviro
		- Robot will start at beginning of the maze (upper left) and make it way through
		  the maze to the end (lower left).

Sources of Information -

	- Class Notes 
	- Klavins Git Repo for class 
	- Github Repo for Enviro

Methods - 

	Wanderer - 
	For the actual ability of my robot the only method I was in need of using was extending on the Wanderer.h.
	The main differece between this Final Project and the Maze creation for what was hw_8 was the difficulty of 
	the maze that it needed to survive and solve. I calibrated the classes of MoveForward and Rotation to better
	suit a well working maze solver. Depending on which direction has a farther distance left or right the robot 
	will decide to rotate through that way. Along with deciding to increase or decrease in speed depending on 
	the forward distance to the wall it is going towards.
	Config.json - 
	I set up the entire maze with the static walls as used for the outside wall, hoping to cause as much confusion
	to the robot as possible.
	Here is where I added a button as well, and tried to trouble shoot to get it to show up but felt a working
	maze would be better to turn in then that of a maze with a non-visible button that disrupts the system.

Side Notes - 

	-------- Additions to the code that ended up not working ------------
	click "RESET" button 
		- Robot will restart robot at initial position
	click "ADD" button
		- An additional robot appears into the maze and would follow maybe at a different speed to 
		  turn it into a race of the turtle and the hare.
	Also tested out eh coronaVIRUS example to work with the shooting down the virus, seemed like a fun game
	but I started with the maze and thought I should stick with it for the project.