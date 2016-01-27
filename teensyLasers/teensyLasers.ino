/*
Code to output 3 distinct square waves with a Teensy 3.1
and set the frequency of each through serial communication

Al Fischer
2016-01-26
*/

int bluePin = 25; // FTM2
int greenPin = 5; // FTM0
int redPin = 3;   // FTM1
int motorPin = 4;
int i;
char inChar[8];
String inCharStr;

void setup()
{
  Serial.begin(9600);
  analogWriteResolution(12); // provides better resolution on duty cycle
  setupPin(bluePin, 1368, 4095);
  setupPin(greenPin, 1370, 4095);
  setupPin(redPin, 1372, 4095);
}

void loop()
{
  while (Serial.available() > 0)
  {
     inChar[i] = Serial.read();
     i++;
   }
   
   if (i > 0) inCharStr = String(inChar);
   if(inCharStr.startsWith("b.")) setFreq(inCharStr, bluePin);
   if(inCharStr.startsWith("g.")) setFreq(inCharStr, greenPin);
   if(inCharStr.startsWith("r.")) setFreq(inCharStr, redPin);
   if(inCharStr.startsWith("s")) {
     digitalWrite(motorPin, HIGH);
     delay(50);
     digitalWrite(motorPin, LOW);
   }
   i = 0;
   inCharStr = " ";
   delay(50);
}

void setFreq(String laser, int pin) {
  String freqStr = laser.substring(2);
  int freq = laser.toInt();
  analogWriteFrequency(pin, freq);
  analogWrite(pin, 4095/2);
}

void setupPin(int pin, int freq, int bits) {
  pinMode(pin, OUTPUT);
  analogWriteFrequency(bluePin, freq);
  analogWrite(pin, bits/2);
}
