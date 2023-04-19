const int SW_pin = 7; // digital pin 2 connected to SW of Joystick Module
const int X_pin = A0; // analog pin A0 connected to VRx of Joystick module
const int Y_pin = A1; // analog pin A1 connected to VRy of Joystick module

int motorPin = 2;
int inPin4 = 4;
int inPin3 = 3;
int motorSpeed = 200;
int start=1;
void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(start);
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
//  delay(500);

if(digitalRead(SW_pin) == 0){
  if(start==1){
    start=-1;
    delay(50);
  }
  else  if(start==-1){
    start=1;
    
    delay(50);
  }
}
if(start==1){
  digitalWrite(13,HIGH);//led
if(analogRead(X_pin)==500 &&analogRead(Y_pin)<=470){
  digitalWrite(inPin4, HIGH);
      digitalWrite(inPin3, LOW);
//      motorSpeed = 200; // adjust this value as needed
      analogWrite(motorPin, motorSpeed);
}



else if(analogRead(Y_pin)<100){
  digitalWrite(inPin4, LOW);
      digitalWrite(inPin3, HIGH);

      analogWrite(motorPin, motorSpeed);
}
else if(analogRead(Y_pin) > 900){
  digitalWrite(inPin4, HIGH);
      digitalWrite(inPin3, LOW);

      analogWrite(motorPin, motorSpeed);
}
}
else if(start==-1){
  digitalWrite(13,LOW);
   digitalWrite(inPin4, LOW);
      digitalWrite(inPin3, LOW);
//      delay(1000);
 }
}
