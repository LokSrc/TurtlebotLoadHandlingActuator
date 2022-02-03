This project was developed as part of course [KONE.533 - Robotics project work](https://www.tuni.fi/en/study-with-us/robotics-project-work-lectures#expander-trigger--f87bd447-1f6f-4d91-974a-c574b59ecb89) at Tampere University.

Goal of this project was to design and implement working actuator for [Turtlebot 3 Waffle Pi](https://www.robotis.us/turtlebot-3-waffle-pi/) that can move and stack pallets.

# Working principle
We ended up using a simple design where 3 separate stepper motors are responsible of all the moving operations of the actuator.
Transfering force from stepper motor to linear motion is done with simple gear+rail system. Limit switches were added to prevent damage caused by driving gears over the limits.

[![Finished application video](https://img.youtube.com/vi/C0iPgLaQcvY/0.jpg)](https://youtu.be/C0iPgLaQcvY)

# Software installation
## Step 0: Install custom OpenCR firmware to arduino IDE
### NOTE: Since pull request to original repo has been merged and published as package there is no need to install custom version of library anymore.
You can follow the guide found at [Official OpenCR site](https://emanual.robotis.com/docs/en/parts/controller/opencr10/#arduino-ide). Make sure you install version 1.4.19 or newer.

~~Follow the instuctions from [LIBRARY_INSTALL.md](/LIBRARY_INSTALL.md)~~

## Step 1: Clone repo
Command: ```git clone https://github.com/LokSrc/TurtlebotLoadHandlingActuator.git```

## Step 2: Open the project in arduino IDE
From arduino IDE press File->Open. A directory dialog will pop up, use this dialog to navigate to the cloned repo path and select the file ```src/turtlebot3_core/turtlebot3_core.ino```

## Step 3: Connect turtlebot
Connect turtlebot with usb cable and select corresponding serial port from arduino IDE Tools->Port

## Step 4: Verify and upload
Use arduino IDE (or other editor with arduino support) to verify and upload sketch to the turtlebot. Verify operation will compile the sketch and Upload will compile and upload the compiled sketch to turtlebot. NOTE: Verify is not required since Upload operation will also build the sketch but Verify can become handy if you do modifications to the sketch.

![Verify button](/resources/verify_button.png)

Verify button is highlighted in the picture above and upload button is right next to it

# Parts list
<ul>
  <li>3x CX28BYJ-48-08 stepper motors</li>
  <li>3x ULN2003A motor drivers</li>
  <li>4x MKSLSS5GLFT limit switches (6x if inner gripper motion is limited as well)</li>
  <li>1x Turtlebot3 Waffle Pi</li>
</ul>

# Electrical diagrams
![Electical diagram](/resources/electrical_diagram.png)

# 3D Models
Due to licensing challenges, 3D models are not made publicly available

# Project developers
Marius Niemenmaa,
Aleksi Luukkonen &
Kristian Klemets
