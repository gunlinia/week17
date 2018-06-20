#include "pitches.h"

int melody2[] = {
 NOTE_C4, NOTE_B3,NOTE_C4,NOTE_E3,NOTE_G3,NOTE_B3,NOTE_C4
};
int melody1[] = {
  NOTE_E5,NOTE_E5,NOTE_E5,NOTE_C5,NOTE_E5,  NOTE_G5
};

int noteDurations=150;

int buttonPin1=A0;
int buttonPin2=A1;
int ledPin=13;
int buttonState1=0;
int buttonState2=0;
long currenttime,previoustime;
bool check;

void setup() {
pinMode(buttonPin1,INPUT);
pinMode(buttonPin2,INPUT);
pinMode(ledPin,OUTPUT);
digitalWrite(buttonPin1,HIGH);
digitalWrite(buttonPin2,LOW);
}

void loop() {
  buttonState1=digitalRead(buttonPin1);
  buttonState2=digitalRead(buttonPin2);
  if(buttonState1==HIGH){
    for (int thisNote = 0; thisNote < 6; thisNote++) {
        if(buttonState2==HIGH){
          noTone(8);
          buttonState1=LOW;
          break;}
        tone(8, melody1[thisNote], noteDurations);
        previoustime=millis();
        digitalWrite(ledPin,HIGH);
        check=false;
        while(!check){
          currenttime=millis();
          if(currenttime-previoustime>100){
            check=true;
            digitalWrite(ledPin,LOW);
          }
        }
        int pauseBetweenNotes = noteDurations * 1.30;
        if (thisNote==2||thisNote==4){
          delay(pauseBetweenNotes);
           delay(pauseBetweenNotes);
        }
        else if(thisNote==5){
           delay(pauseBetweenNotes*20);
        }
        else delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
      }
 }
 if(buttonState2==HIGH){
      for (int thisNote = 0; thisNote < 6; thisNote++) {
        if(buttonState1==HIGH){
          noTone(8);
          buttonState2=LOW;
          break;
          }
        tone(8, melody2[thisNote], noteDurations);
        previoustime=millis();
        digitalWrite(ledPin,HIGH);
        check=false;
        while(!check){
          currenttime=millis();
          if(currenttime-previoustime>50){
            check=true;
            digitalWrite(ledPin,LOW);
          }
        }
        int pauseBetweenNotes = noteDurations * 1.30;
        if (thisNote==2||thisNote==4){
           delay(pauseBetweenNotes);
           delay(pauseBetweenNotes);
        }
        else if(thisNote==5){
           delay(pauseBetweenNotes*20);
        }
        else delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
      }
    }
}
