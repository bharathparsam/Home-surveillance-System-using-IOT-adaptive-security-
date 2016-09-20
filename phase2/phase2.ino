int led = 13;                // Pin for LED attachment
int sensor = 2;              // Sensor pin attachment 
int state = LOW;             // Defaultly no motion is detected
int val = 0;                 // Store the Sensor Values

void setup() {
  pinMode(led, OUTPUT);      // Intilization of LED Output
  pinMode(sensor, INPUT);    // Intilization of Sensor Value INPUT
  Serial.begin(9600);        // Serail pin intilazion
}

void loop(){
  val = digitalRead(sensor);   // reading the sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    delay(10);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update the variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}
