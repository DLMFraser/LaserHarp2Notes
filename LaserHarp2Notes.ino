/*
  Program Name: LaserHarp Two Notes
  Purpose:
    - Detect Light and play a tone under
      the condition that not enough 
      light is present
  Circuit:
    - A0 is hooked up to a voltage divider with a photoresistor
      and a 100k resistor
    - A1 is hooked up to a voltage divider with a photoresistor
      and a 100k resistor
    - A piezo is hooked up to pin 11 (PWM~)
  Based on: LaserHarp One Note
  Written By: James Spaleta and Destinee Fraser on 16/11/2014 (DD/MM/YYYY)
*/

//Sensor Pin
int sensor0 = A0; //The analog-in pin A0
                  //Will be used to
                  //Detect light
int sensor1 = A1; //The analog-in pin A1
                  //Will be used to 
                  //Detect light
//Speaker Pin
int speaker = 11;//Speaker is on pin
                  //11 as it must be 
                  //On a PWM~ pin to use
                  //The tone function
//Light Threashold
const int lightThreashold = 50;  //Will play audio when there
                                  //Is a lower reading than
                                  //This from the light sensor
void setup()
{
  pinMode(sensor0, INPUT);
  pinMode(speaker, OUTPUT);
  Serial.begin(9600); //Begin serial communication
                      //At 9600 baud for use in 
                      //Calibration of the sensor
}

void loop()
{
  int lightLevel = analogRead(sensor0); //low number means more light
  Serial.println(lightLevel);
  while(lightLevel > lightThreashold) //While loop will prevent other tones from being played
  {
    tone(speaker, 261);
    lightLevel = analogRead(sensor0);
  }
  noTone(speaker); //Ensures the tone stops 
                    //after exiting the loop
  lightLevel = analogRead(sensor1);
  Serial.println(lightLevel);
  while(lightLevel > lightThreashold) //While loop will prevent other tones from being played
  {
    tone(speaker, 1915);
    lightLevel = analogRead(sensor1);
  }
  noTone(speaker); //Ensures the tone stops 
                    //after exiting the loop
}
