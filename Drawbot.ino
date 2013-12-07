int m1FPin = 7;
int m1BPin = 11;
int m2FPin = 10;
int m2BPin = 9;



int sens_raw;

const byte DIR_FORWARD = 0;
const byte DIR_BACKWARD = 1;
const byte DIR_LEFT = 2;
const byte DIR_RIGHT = 3;
const byte DIR_STOP = 4;





void walkDir( byte dir ){
    if( dir==DIR_FORWARD ){
        analogWrite( m1FPin, 0 );
        analogWrite( m1BPin, 50 );
        analogWrite( m2FPin, 0 );
        analogWrite( m2BPin, 50 );
    }
    else if( dir==DIR_LEFT ){
        analogWrite( m1FPin, HIGH );
        analogWrite( m1BPin, LOW );
        analogWrite( m2FPin, LOW );
        analogWrite( m2BPin, HIGH );
    }
    else if( dir==DIR_STOP ){
        analogWrite( m1FPin, LOW );
        analogWrite( m1BPin, LOW );
        analogWrite( m2FPin, LOW );
        analogWrite( m2BPin, LOW );
    }
}

int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:



void loop() {

        walkDir( DIR_FORWARD );
        digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);               // wait for a second
        digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);               // wait for a second
// Serial.print(sens_raw);
// delay(500);
}
