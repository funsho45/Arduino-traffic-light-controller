/*
 Traffic light controller system

 This program simulates and controls a traffic light system at a street junction with a pedestrian crossing.

  
Created by Funsho Adebari

*/

int GREENMR =3;   /*This is the integer name given to pin 3 of the digital port. 
                    It represents the green light on the main road traffic light.*/

int YELLOWMR =4;  /*This is the integer name given to pin 4 of the digital port. 
                    It represents the yellow light on the main road traffic light.*/

int REDMR =5;      /*This is the integer name given to pin 5 of the digital port. 
                    It represents the red light on the main road traffic light.*/
              
int GREENSR =8;    /*This is the integer name given to pin 8 of the digital port. 
                    It represents the green light on the side road traffic light.*/

int YELLOWSR =9;   /*This is the integer name given to pin 9 of the digital port. 
                    It represents the yellow light on the side road traffic light.*/

int REDSR =10;     /*This is the integer name given to pin 10 of the digital port. 
                    It represents the red light on the side road to traffic light.*/

int PEDRED =7;     /*This is the integer name given to pin 7 of the digital port. 
                    It represents the red light on the pedestrian traffic light.*/

int PEDGREEN =6;   /*This is the integer name given to pin 6 of the digital port. 
                    It represents the green light on the pedestrian traffic light.*/

/*These are the integer names given to pin 12 and 11 of the digital port. 
  They represent the “Push Buttons” that will be used to request a green light on the pedestrian traffic light*/
int pushbutton1=12;
int pushbutton2=11;

int POTimer;   /*This is the integer name given to an analog pin on  anaolog port. 
                 It represents the “potentiometer” that will be used to control the time the pedestrian traffic light should stay green.*/

int POTcoil;   /*This is the integer name given to an analog pin on the analog port. 
                 It represents “potentiometer” that will be used to emulate the functions of the induction coils on the side road.*/

/*The "MainroadTL" function will simulate the traffic light sequence on the main road. 
  The sequence will then stop when the main road red traffic light is reached which will then play the"PedCrossLight"function.
  And once that function has been executed the function with and continue from where it left off.*/

void MainroadTL(){
  digitalWrite(GREENMR,HIGH);   // Turn the GREEN LED ON. 
  delay(6000);                  //Wait for 6 seconds.
  digitalWrite(GREENMR,LOW);    // Turn the GREEN LED OFF. 
  digitalWrite(YELLOWMR,HIGH);  // Turn the YELLOW LED ON. 
  delay(1000);                  //Wait for 1 second.
  digitalWrite(YELLOWMR,LOW);   // Turn the YELLOW LED OFF. 
  digitalWrite(REDMR,HIGH);     // Turn the RED LED ON. 
  delay(5000);                  //Wait for 5 seconds.
  PedCrossLight();              //Call and execute the “PedCrossLight” function.  
  digitalWrite(REDMR,HIGH);     // Turn the RED LED ON. 
  delay(5000);                  //Wait for 5 seconds.
  digitalWrite(YELLOWMR,HIGH);  // Turn the YELLOW LED ON. 
  delay(2000);                  //Wait for 2 seconds.
  digitalWrite(REDMR,LOW);      // Turn the RED LED OFF. 
  digitalWrite(YELLOWMR,LOW);   // Turn the YELLOW LED OFF. 
  digitalWrite(GREENMR,HIGH);   // Turn the GREEN LED ON. 
} 

/*The “MainroadTL2” function will simulate a traffic light sequence of the second set of traffic lights on the main road. 
  And is for when the “MainroadTL” function is completed and ends with the green LED on.
  The sequence will stop when the main road traffic light reaches red which will then play the “SideroadTL” function. 
  And once that function has been executed the “MainroadTL2” function will continue from where it left off.*/

void MainroadTL2(){
  digitalWrite(GREENMR,HIGH);        // Turn the GREEN LED ON.
  delay(6000);                       //Wait for 6 seconds.
  digitalWrite(GREENMR,LOW);         // Turn the GREEN LED OFF.
  digitalWrite(YELLOWMR,HIGH);       // Turn the YELLOW LED ON.
  delay(1000);                       //Wait for 1 seconds.
  digitalWrite(YELLOWMR,LOW);        // Turn the YELLOW LED LOW.
  digitalWrite(REDMR,HIGH);          // Turn the RED LED ON.
  delay(5000);                       //Wait for 5 seconds.
  SideroadTL();                      //Call and execure the "SideroadTL" function.
  digitalWrite(REDMR,HIGH);          // Turn the RED LED ON.
  delay(5000);                       //Wait for 5 seconds.
  digitalWrite(YELLOWMR,HIGH);       // Turn the YELLOW LED ON.
  delay(2000);                       //Wait for 2 seconds.
  digitalWrite(REDMR,LOW);           // Turn the RED LED OFF.
  digitalWrite(YELLOWMR,LOW);        // Turn the YELLOW LED OFF.
  digitalWrite(GREENMR,HIGH);        // Turn the GREEN LED ON.
}  

/*The ”SideroadTL” will simulate the traffic light sequence on the side road. 
  The sequence will start on the red light and the cycle will then go from red, yellow and green then back to red.*/

void SideroadTL(){
  digitalWrite(REDSR,HIGH);      // Turn the RED LED ON.
  delay(5000);                   //Wait for 5 seconds.
  digitalWrite(YELLOWSR,HIGH);   // Turn the YELLOW LED ON.
  delay(2000);                   //Wait for 2 seconds.
  digitalWrite(REDSR,LOW);       // Turn the RED LED OFF.
  digitalWrite(YELLOWSR,LOW);    // Turn the YELLOW LED OFF.
  digitalWrite(GREENSR,HIGH);    // Turn the GREEN LED ON.
  delay(6000);                   //Wait for 6 seconds.
  digitalWrite(GREENSR,LOW);     // Turn the GREEN LED OFF.
  digitalWrite(YELLOWSR,HIGH);   // Turn the YELLOW LED ON.
  delay(1000);                   //Wait for 1 seconds.
  digitalWrite(YELLOWSR,LOW);    // Turn the YELLOW LED OFF.
  digitalWrite(REDSR,HIGH);      // Turn the RED LED ON.
  
}

/* The “PedCrossLight” function simulates the pedestrian traffic lights.
   A potentiometer is used to control the duration of the green pedestrian light, which will be blinking during its duration.
   Once the time for the green pedestrian light finishes the red pedestrian light will turn on. */

void PedCrossLight(){
  //Read the analog "A1" in value "POTimer"
  POTimer=analogRead(A1);       
  float timer=POTimer*(10.0/1023.0);  /*This is to convert the pot values 0-1023 to seconds between 1 to 10. 
                                        We then store the value in the float variable “timer”.*/
  
  digitalWrite(PEDRED,LOW);        // Turn the RED LED OFF for the pedestrain traffic light.
 
   //If the “timer” variable is between 0 and 10 then execute the code within the code blocks.
   if(timer>=0 && timer<=10 ){ 
    for (int x=1;x<=timer;x++){    /*If the integer X is equal to 1, while X is less than or equal to the ”timer” value, 
                                     then carry out the code within the code block. And then increment X by 1.*/
       
    digitalWrite(PEDGREEN,HIGH);   // Turn the GREEN LED ON for the pedestrain traffic light.
    delay(500);                    //Wait for 0.5 seconds
    digitalWrite(PEDGREEN,LOW);    // Turn the GREEN LED OFF for the pedestrain traffic light.
    delay(500);                    //Wait for 0.5 seconds
    }
  
   
   } 
  
  digitalWrite(PEDRED,HIGH);       //Turn the RED LED ON for the pedestrain traffic light.
  Serial.begin(9600);              // initialize serial communications at 9600 bps (bits per seconds).
  Serial.println(timer);           // print the "timer" results to the Serial Monitor. 
}

  
/* In the setup function the pins are allocated to be either INPUT or OUTPUT 
   and the initial state of the traffic light system is set. 
   The function runs only once when you press reset or power the board.*/
void setup(){
  
  pinMode(GREENMR,OUTPUT);       //Configure pin 3 of the digital port to be used as an output.
  pinMode(YELLOWMR,OUTPUT);      //Configure pin 4 of the digital port to be used as an output.
  pinMode(REDMR,OUTPUT);         //Configure pin 5 of the digital port to be used as an output.
  pinMode(GREENSR,OUTPUT);       //Configure pin 8 of the digital port to be used as an output.
  pinMode(YELLOWSR,OUTPUT);      //Configure pin 9 of the digital port to be used as an output.
  pinMode(REDSR,OUTPUT);         //Configure pin 10 of the digital port to be used as an output.
  pinMode(PEDRED,OUTPUT);        //Configure pin 7 of the digital port to be used as an output.
  pinMode(PEDGREEN,OUTPUT);      //Configure pin 6 of the digital port to be used as an output.
  digitalWrite(GREENMR,HIGH);    //Turn the GREEN LED ON for the main road traffic light.
  digitalWrite(REDSR,HIGH);      //Turn the RED LED ON for the side road traffic light.
  digitalWrite(PEDRED,HIGH);     //Turn the RED LED ON for the pedestrain traffic light. 
  pinMode(pushbutton1,INPUT);    //Configure pin 12 of the digital port to be used as an input.
  pinMode(pushbutton2,INPUT);    //Configure pin 11 of the digital port to be used as an input.
 
  Serial.begin(9600);            // initialize serial communications at 9600 bps (bits per seconds).

}


/* The loop function will loop once either of the pushbuttons has been pressed. 
   If either pushbutton has been pressed a Boolean variable will be checked 
   and if the Boolean variable is false then the “MainroadTL” function will be executed. 
   The Boolean variable after this will equal true, thus stopping the function.
   The loop function will run again once either of the push buttons is pushed.
   
   A potentiometer, using an analogue port,  is used to simulate a car waiting on the induction coils. 
   And if the pot value reads 512 and the Boolean variable is equal to true then the “MainroadTL2” will be executed. 
   */
void loop(){
 int buttonstate=digitalRead(pushbutton1);     // read the state of the "pushbutton1" value.
 int buttonstate2=digitalRead(pushbutton2);    // read the state of the "pushbutton1" value
 bool finsishMainroadTL= false;
 
  if (buttonstate==HIGH || buttonstate2==HIGH){ // if either of the two push buttons is pressed, then execute the code in the code block.
    finsishMainroadTL= false;    // The boolean variable “finsishMainroadTL” is still false.
    MainroadTL();         //Call and execute the “MainroadTL” function.
    finsishMainroadTL= true; // The boolean variable “finsishMainroadTL” is now true, so stop this loop.
    
  }
  
  POTcoil=analogRead(A0); //Read the analog "A0" in value "POTcoil."
  
  if (POTcoil>=512 && finsishMainroadTL==true){ /*If the "POTcoil" value is greater than and equal to 512 and the “finsishMainroadTL” is still true, 
                                                  then execute the code in the code block.*/
                                                  
    MainroadTL2();                              //Call and execute the "MainroadTL2" function.
    
  }
  Serial.println(POTcoil);                     // print the "POTcoil" results to the Serial Monitor. 
   
 
}
