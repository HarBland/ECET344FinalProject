/*
 *   Program name: finalProjv2.cpp
 *   Name: Harry A. Blanda and Kevin Branco
 *   Date: 12/9/2021
 *   Course ID: ECET 344-001
 *   Description: This program reads the position of the x and y axis of a joystick. Then it turns on or off LEDs that correspond with the joystick position
 *   
 *   Algorithm:
 *   1) Set pinmodes
 *   2) Set all LEDs to LOW state
 *   3) read position of x axis and store value
 *   4) read position of y axis and store value
 *   5) if xAxis and yAxis are > -30 and < 30 turn on center LED
 *   6) if xAxis is < -50 turn on left LED
 *   7) if xAxis is >  50 turn on right LED
 *   8) if yAxis is < -50 turn on bottom LED
 *   9) if yAxis is > 50 turn on top LED
 *   10) repeat steps 3-9 for ever
 */

//Setting constants for LED pins
const int leftLEDPin = 8;
const int upLEDPin = 9;
const int rightLEDPin = 10;
const int downLEDPin = 11;
const int centerLEDPin = 12;

//setting constants for xAxis and yAxis pins
const int xAxis = 2;
const int yAxis = 1;

//This function will determine if the left or right LED should be on or off
void leftOrRight(int xValue)
{
  if(xValue < 50 && xValue > -50)
  {
    digitalWrite(leftLEDPin, LOW);
    digitalWrite(rightLEDPin, LOW);
  }
  else if(xValue > 50)
  {
    digitalWrite(leftLEDPin, HIGH);
    digitalWrite(rightLEDPin, LOW);
  }
  else
  {
    digitalWrite(leftLEDPin, LOW);
    digitalWrite(rightLEDPin, HIGH);
  }
}

//This function will determine if the uo or down LED should be on or off
void upOrDown(int yValue)
{
  if(yValue < 50 && yValue > -50)
  {
    digitalWrite(upLEDPin, LOW);
    digitalWrite(downLEDPin, LOW);
  }
  else if(yValue > 50)
  {
    digitalWrite(upLEDPin, HIGH);
    digitalWrite(downLEDPin, LOW);
  }
  else
  {
    digitalWrite(upLEDPin, LOW);
    digitalWrite(downLEDPin, HIGH);
  }
}

//this function controls if the center LED should be on or off
void centerOnorOff(int xValue, int yValue)
{
  if (xValue < 30 && xValue > -30 && yValue < 30 && yValue > -30)
    digitalWrite(centerLEDPin, HIGH);
  else
    digitalWrite(centerLEDPin, LOW);
}

void setup()
{
  //setting LED pinmodes as output
  pinMode(leftLEDPin, OUTPUT);
  pinMode(upLEDPin, OUTPUT);
  pinMode(rightLEDPin, OUTPUT);
  pinMode(downLEDPin, OUTPUT);
  pinMode(centerLEDPin, OUTPUT);

  //making all LEDs have voltage value of LOW
  digitalWrite(leftLEDPin, LOW);                                                                                                          
  digitalWrite(upLEDPin, LOW);
  digitalWrite(rightLEDPin, LOW);
  digitalWrite(downLEDPin, LOW);
  digitalWrite(centerLEDPin, LOW);

  //starting serial connection at 115200 baud rate
  Serial.begin(115200);
}

void loop()
{
  //reading xAxis and yAxis
  int yRead = analogRead(yAxis)-500; //subtracting 500 to get negative values
  int xRead = analogRead(xAxis)-500;

  //printing xRead and yRead values to serial
  Serial.print("X-Axis: ");
  Serial.println(xRead);
  Serial.print("Y-Axis: ");
  Serial.println(yRead);

  //Calling leftOrRight function
  leftOrRight(xRead);
 
  //Calling upOrDown function
  upOrDown(yRead);

  //Calling centerOnOrOff function
  centerOnorOff(xRead, yRead);
}
