/* oTTo DIY is a great project that use a 3D pronted robot to teach coding to the kids.
* You can see all the information about oTTo to the oTTo official page: https://www.ottodiy.com
* 
* With this code you can test the servos and the buzzer. Also you can mount all the servoc properly.
*/

// include the Servo library
#include <Servo.h>
#include "pitches.h"

Servo leftl;  // create a servo object
Servo leftf;  // create a servo object
Servo rightf;  // create a servo object
Servo rightl;  // create a servo object
int pause (1000);

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};



void setup() {
  tone(13, 2000, 300);
  leftl.attach(2); 
  rightl.attach(3);
  leftf.attach(4); 
  rightf.attach(5);
  Serial.begin(9600);
  Serial.println("Ready to test !");
  
}

void loop() {
  Serial.print("Left leg degree: ");
  for (int i = 0; i < 180; i++) {
    leftl.write(i);
    delay(50);
    Serial.print(i);
  }
  leftl.write(90);
  Serial.println();
  Serial.println("DONE");
  delay(pause);
  
  Serial.print("Right leg degree: ");
  for (int i = 0; i < 180; i++) {
    rightl.write(i);
    delay(50);
    Serial.print(i);
  }
  rightl.write(90);
  Serial.println();
  Serial.println("DONE");
  delay(pause);
  
  Serial.print("Left foot degree: ");
  for (int i = 0; i < 180; i++) {
    leftf.write(i);
    delay(50);
    Serial.print(i);
  }
  leftf.write(90);
  Serial.println();
  Serial.println("DONE");
  delay(pause);
  
  Serial.print("Right foot degree: ");
  for (int i = 0; i < 180; i++) {
    rightf.write(i);
    delay(50);
    Serial.print(i);
  }
  rightf.write(90);
  Serial.println();
  Serial.println("DONE");
  delay(pause);
  delay(2000);
  Serial.println("FINISH TEST!");
  sound();
  while (true){}
  
}

void sound(){
      // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(13, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
    }    
}
