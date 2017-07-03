int val; 
 int encoder0PinA = 0; // Reads in the wave-edge from A Channel
 int encoder0PinB = 1; // Reads in the wave-edge from B Channel
 int encoder0Pos = 0; // Number of encoder edges 
 int indicatorPin = 3; // This indicates if the circuit has been completed
 int encoder0PinALast = LOW;
 int n = LOW;

 void setup() { 
   pinMode (encoder0PinA,INPUT);
   pinMode (encoder0PinB,INPUT);
   pinMode (indicatorPin, INPUT); 
   Serial.begin (9600);
 } 

 boolean semaphore = false; 

 double deltaRotation = 0;
 double linearDisplacement = 0;

 void loop() { 
  Serial.print(digitalRead(indicatorPin));
   if (!semaphore) {
     n = digitalRead(encoder0PinA);
     if ((encoder0PinALast == LOW) && (n == HIGH)) {
       if (digitalRead(encoder0PinB) == LOW) {
         encoder0Pos--;
       } else {
         encoder0Pos++;
       }
       Serial.print (encoder0Pos);
       Serial.print ("/");
     } 
     encoder0PinALast = n;
     if(digitalRead(indicatorPin) > 0) {
      deltaRotation = ((encoder0Pos)/(2 * 4096)) * 360;
      linearDisplacement = deltaRotation*0.1613556893;
      Serial.print("Rotational Distance is: ");
      Serial.print(deltaRotation);
      Serial.print("Linear Distance is: ");
      Serial.print(linearDisplacement); 
      semaphore = true; 
      //Serial.print(semaphore);
     }
   }
 } 

 
