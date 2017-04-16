zakaria.belk [11:17 AM] 
volatile int flow_frequency; // Measures flow sensor pulses
 float l_sec; // Calculated litres/hour
 float lastAmount=0;;
 float newAmount=0;
unsigned char flowsensor = 2; // Sensor Input
unsigned long currentTime;
unsigned long cloopTime;
void flow () // Interrupt function
{
   flow_frequency++;
}
void setup()
{
   pinMode(flowsensor, INPUT);
   pinMode(3,OUTPUT);
   pinMode(4,OUTPUT);
   pinMode(6,OUTPUT);
   pinMode(8,OUTPUT);
   pinMode(10,OUTPUT);
   pinMode(12,OUTPUT);

  digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up
   Serial.begin(9600);
   attachInterrupt(0, flow, RISING); // Setup Interrupt
   sei(); // Enable interrupts
   currentTime = millis();
   cloopTime = currentTime;
}
void loop ()
{


  currentTime = millis();
   // Every 2 seconds, calculate and print litres/hour
   if(currentTime >= (cloopTime + 1000))
   {
    
      cloopTime = currentTime; // Updates cloopTime
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      l_sec = (flow_frequency  / (60*7.5)); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      flow_frequency = 0; // Reset Counter
      newAmount=lastAmount+(l_sec);
      Serial.print(l_sec); // Print litres/hour
      Serial.print(" L/sec");
      Serial.print("---");
      Serial.print(newAmount);
      Serial.println(" L");

  }    
  if(l_sec==0){
    delay(6000);
    if(l_sec==0){
    newAmount=0;
    lastAmount=0;
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(12,HIGH);      
   }
    }
  

   if(newAmount > 0.2 && newAmount < 0.4){
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(12,LOW);
    }

   if(newAmount > 0.4 && newAmount < 0.6){
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(12,LOW);
    }
    if(newAmount > 0.6 && newAmount < 0.8){
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);
    }
    
   if(newAmount > 0.8 && newAmount < 1){
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);
    }
    if(newAmount > 1 && newAmount < 1.2){
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);
    }

   if(newAmount > 1.2){
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);
    }

   lastAmount=newAmount;
   
}
