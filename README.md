# -Robot-Line-Follower

This line-following robot was developed using an Arduino Uno with an integrated ESP8266 board. It is a computer vision project focused on object detection. The robot has a camera integrated via a smartphone, which sends data to a computer where the machine learning model is stored. The data is input into the model, which then classifies whether the robot should move forward, stop, or turn left or right. The output from the model is sent to the ESP8266 board, which commands the Arduino and the L298N motor driver. The main function of the robot is to follow a line.

![image](https://github.com/user-attachments/assets/1d348e45-faaf-45ab-a6fd-0a85a5b610e1)
