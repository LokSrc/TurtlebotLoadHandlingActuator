TurtlebotLoadHandlingActuator project uses a custom version of OpenCR firmware which can be found at [Github](https://github.com/LokSrc/OpenCR/tree/release/turtlebot3-rc100-raw-data-optionality). At the time of writing this documentation there is open pull request to the official OpenCR repo about this functionality [Pull request #290](https://github.com/ROBOTIS-GIT/OpenCR/pull/290)

This custom OpenCR firmware is version 1.4.18 of normal OpenCR firmware with support to fetch raw input from RC100 controller without interfering with original turtlebot features.

Installing this custom version of OpenCR is almost same as installing normal version of OpenCR firmware. Only difference is the used release (which is hosted on repo linked above).

# Step 0 - Arduino IDE setup

You can follow the guide found at [Official OpenCR site](https://emanual.robotis.com/docs/en/parts/controller/opencr10/#arduino-ide) until the Preferences part.
Instead of using the given link use this link instead ```https://raw.githubusercontent.com/LokSrc/OpenCR/release/turtlebot3-rc100-raw-data-optionality/arduino/opencr_release/package_opencr_index.json``` at the arduino IDE preferences tab.

![preferences tab](/resources/preferences_tab.png)

This link will fetch the customized version of OpenCR library.

# Step 1 - Installing custom OpenCR firmware version

After the arduino IDE has been setup with the releases of OpenCR firmware you can proceed to installing the custom OpenCR firmware to arduino IDE. Select Tools->Board->Boards manager and search for "opencr".

Make sure you select the version "1.4.18-loksrc" and install it to arduino IDE.

![boards manager](/resources/boards_manager.png)

Custom version of OpenCR firmware is now ready to be used and you can move on to uploading code to turtlebot!
