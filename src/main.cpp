#include <Arduino.h>
const int dotDuration = 250;
const int dashDuration =3*dotDuration; 
const int letterGap =3*dotDuration; 
const int wordGap = 7*dotDuration; 
const int pin = 13; 
String Map[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", 
  ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
  ".--", "-..-", "-.--", "--.."
};
void dot() {
  digitalWrite(pin, HIGH); 
  delay(dotDuration); 
  digitalWrite(pin, LOW);
}
void dash() {
  digitalWrite(pin, HIGH);
  delay(dashDuration);
  digitalWrite(pin, LOW);
}
void morsencoder(char c){
  if(c==' '){
    delay(letterGap);
    return;
  }
  int index = toupper(c)-'A';
  if(index>=0&&index<26){
    String letter  =Map[index];
  for (int i=0;i<letter.length();i++) {
    if(letter[i]=='.') {
      dot();
    }
    else if(letter[i]=='-'){
      dash();
    } 
    if(i<letter.length()-1) {
      delay(dotDuration); 
   }
 }
  delay(letterGap);
  }
}
void setup() {
  pinMode(pin, OUTPUT);
  Serial.begin(9600);  // Start Serial communication
  Serial.println("Morse code program started!");  
}
void loop() {
  String word = "HELLO"; 
  for (int i = 0; i < word.length(); i++) {
    morsencoder(word[i]);
  }
  delay(wordGap);
}