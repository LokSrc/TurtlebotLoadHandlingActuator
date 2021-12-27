This project was developed as part of course [KONE.533 - Robotics project work](https://www.tuni.fi/en/study-with-us/robotics-project-work-lectures#expander-trigger--f87bd447-1f6f-4d91-974a-c574b59ecb89) at Tampere University.

Goal of this project was to design and implement working actuator for [Turtlebot 3 Waffle Pi](https://www.robotis.us/turtlebot-3-waffle-pi/) that can move and stack pallets.

# Working principle
We ended up using a simple design... 

TODO

# Software installation
## Step 0: Install custom OpenCR firmware to arduino IDE
Follow the instuctions from [LIBRARY_INSTALL.md](/LIBRARY_INSTALL.md)

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
TODO

# Electrical diagrams
TODO

# 3D Models
TODO

# Project developers
TODO