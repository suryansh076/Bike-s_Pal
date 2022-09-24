#include <String.h>
#include <Keypad.h>
int buzz = 11;
int active = 10;
int i = 0;
String s1 = "66115";
String s = "";
const int R = 4;
const int C = 4;
const char matkey[R][C] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rpin[R] = {2, 3, 4, 5};
byte cpin[C] = {6, 7, 8, 9};
Keypad newkey = Keypad(makeKeymap(matkey),rpin,cpin,R,C);
void setup() {
  Serial.begin(9600);
  delay(1000); 
  pinMode(buzz, OUTPUT);
  pinMode(active, OUTPUT);
  digitalWrite(buzz, HIGH);
  digitalWrite(active, HIGH);
}
void loop() {
  while (true)
  {
    char mykey = newkey.getKey();
    if (mykey != 0) {
      Serial.println(mykey);
      s = s + mykey;
      i++;
      if (i == (s1.length()))
      {
        i = 0;
        break;
      }
    }
  }
  //Serial.println(s);
  if (s == s1)
  {
    while (true)
    {
       Serial.println("you are great");
      digitalWrite(buzz, LOW);
      digitalWrite(active, LOW);
      s = "";
    }
  }
  s = "";
  delay(1000);
}
