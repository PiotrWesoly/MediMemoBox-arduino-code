#include "pitches.h"

char command;
String string;
boolean ledon = false;
#define led1 9
#define led2 12
#define led3 13
#define led4 4
#define led5 11
#define led6 7
#define led7 3
#define led8 6
#define led9 2
#define led10 5
#define buzzer 10

void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0)
      {string = "";}
  while(Serial.available() > 0)
      {command = ((byte)Serial.read());
       if(command == ':')
          {
            break;
          }
       else
          {
            string += command;
          }
        delay(1);
        }

if(string =="1"){
     turnOn(led1);
      sound();
      sound();
      turnOff(led1);
      delay(500);
      }
      else if(string == "2")
      {
      turnOn(led2);
      sound();
      sound();
      turnOff(led2);
      delay(500);
      }
      else if(string == "3")
      {
       turnOn(led3);
      sound();
      sound();
      turnOff(led3);
      delay(500);
      }
       else if(string == "4")
      {
       turnOn(led4);
      sound();
      sound();
      turnOff(led4);
      delay(500);
      }
       else if(string == "5")
      {
      turnOn(led5);
      sound();
      sound();
      turnOff(led5);
      delay(500);
      }
       else if(string == "6")
      {
      turnOn(led6);
      sound();
      sound();
      turnOff(led6);
      delay(500);
      }
       else if(string == "7")
      {
       turnOn(led7);
      sound();
      sound();
      turnOff(led7);
      delay(500);
      }
       else if(string == "8")
      {
       turnOn(led8);
      sound();
      sound();
      turnOff(led8);
      delay(500);
      }
       else if(string == "9")
      {
       turnOn(led9);
      sound();
      sound();
      turnOff(led9);
      delay(500);
      }
       else if(string == "10")
      {
      turnOn(led10);
      sound();
      sound();
      turnOff(led10);
      delay(500);
      }



  //  if ((string.toInt()>=0)&&(string.toInt()<=255))
  //{
  //if (ledon==true)
  //{
  //analogWrite(led1, string.toInt());
  //Serial.println(string); //debug
  //delay(10);
  //}
  //}
}


void turnOn(int led)
{
analogWrite(led, 255);
delay(50);
}


void turnOff(int led)
{
analogWrite(led, 0);
delay(10);
}

int melody[] = {
  NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5, 
  NOTE_E5, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5, 
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_FS5, 
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5
};

int durations[] = {
  8, 8, 8, 4, 4, 4, 
  4, 5, 8, 8, 8, 8, 
  8, 8, 8, 4, 4, 4, 
  4, 5, 8, 8, 8, 8
};

int songLength = sizeof(melody)/sizeof(melody[0]);

void sound()
{
    for (int thisNote = 0; thisNote < songLength; thisNote++){
    // determine the duration of the notes that the computer understands
    // divide 1000 by the value, so the first note lasts for 1000/8 milliseconds
    int duration = 1000/ durations[thisNote];
    tone(buzzer, melody[thisNote], duration);
    // pause between notes
    int pause = duration * 1.3;
    delay(pause);
    // stop the tone
    noTone(buzzer);
  }
}
