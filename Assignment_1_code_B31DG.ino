
const int pulsesButt = 23; //initialising the pins for the buttons and the LED's
const int modeButt = 22;
const int ledRed =21;
const int ledGreen =15;
int pulseState =0; //setting the initial state of the buttons as off.
int modeState=0;
const int a=1100; //my second name is pollock and it gave me 1100,1200,16,6000 and mode 1
const int b=1200; //this is setting up the time dalay's for the code.
const int d=6000;

void setup() {
  Serial.begin(9600);
  delay(100);
  pinMode(ledRed, OUTPUT); //initailising the inputs and outputs for the buttons and LED's
  pinMode(ledGreen, OUTPUT);
  pinMode(pulsesButt,INPUT);
  pinMode(modeButt,INPUT);
  Serial.print("start");
}

void loop() {
  pulseState=digitalRead(pulsesButt); //reading the buttonpins at the beggining of the loop fuinction
  modeState=digitalRead(modeButt);
  int c=16;
  if(modeState==HIGH){ //setting c to 16 or 13 depending on the mode buttons state
    Serial.print("dfgdf");
    c=13;
  }
  if(pulseState == LOW){ //if the pulse button is not being pressed the pulses will not be disabled
    for(int i=0 ; i<c ; i++){ //for loop that will repeat c times.
      digitalWrite(ledGreen,HIGH); //setting the green LED to be on for a plus an incrementing time.  
      delayMicroseconds(a+(i*50)); //then off for b time. 
      Serial.print("1");
      digitalWrite(ledGreen,LOW);
      delayMicroseconds(b);
    }
  }
  delayMicroseconds(d); //once signal has been outputted wait d time and then turn on red LED for 50 microseconds
  digitalWrite(ledRed,HIGH);
  delayMicroseconds(50);
  digitalWrite(ledRed,LOW);
 //start the loop over again. 

}
