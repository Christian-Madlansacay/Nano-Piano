/*
  Nano Piano

  A simple, small piano that is not only small as the name implies, but it runs off of the Arduino Nano Every.

  created 2/25/2021
  by Christian Madlansacay

  GitHub: https://github.com/Christian-Madlansacay
  Hacksterio: https://www.hackster.io/christian-madlansacay
  Instagram: https://www.instagram.com/c_madlansacay/
  Twitter: https://twitter.com/c_madlansacay
  YouTube: https://www.youtube.com/channel/UCSJFVhXUiDDvXZKhmj4Wijg
  

  https://www.hackster.io/christian-madlansacay/nano-piano-8da96d
*/

// Customize the frequency values for each note (Note: It is not possible to generate tones lower than 31Hz.).
int noteOneFreq = 170;
int noteTwoFreq = 180;
int noteThreeFreq = 190;
int noteFourFreq = 200;

// Variables for each of the digital pins for components.
const int noteOne = 2;
const int noteTwo = 3;
const int noteThree = 4;
const int noteFour = 5;
const int passiveBuzzer = 6;

// Variables set to a default value.
int noteOneState = false;
int noteTwoState = false;
int noteThreeState = false;
int noteFourState = false;

void setup() {
// Setting INPUT pins.
  pinMode(noteOne, INPUT);
  pinMode(noteTwo, INPUT);
  pinMode(noteThree, INPUT);
  pinMode(noteFour, INPUT);

// Setting OUTPUT pins.
  pinMode(passiveBuzzer, OUTPUT);
}

void loop() {
// Creating variables to read the state of each of the INPUT pins.
  noteOneState = digitalRead(noteOne);
  noteTwoState = digitalRead(noteTwo);
  noteThreeState = digitalRead(noteThree);
  noteFourState = digitalRead(noteFour);
  
  if (noteOneState == HIGH) {   // Checks if note state is sending a HIGH signal.
    tone(passiveBuzzer, noteOneFreq);   // Sends a frequency value to the passive buzzer according to which button is pressed.
  } else if (noteTwoState == HIGH) {   // Repeats.
    tone(passiveBuzzer, noteTwoFreq);
  } else if (noteThreeState == HIGH) {
    tone(passiveBuzzer, noteThreeFreq);
  } else if (noteFourState == HIGH) {
    tone(passiveBuzzer, noteFourFreq);
  } else
    noTone(passiveBuzzer);   // If none of the notes are sending a HIGH signal send noTone to the passive buzzer.
}