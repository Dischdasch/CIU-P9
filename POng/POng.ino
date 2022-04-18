//Ejemplo de envío de mensaje por el puerto serial con Arduino

int ledPin = 13;      // LED connected to digital pin 9
int analogPin = 0;   // potentiometer connected to analog pin 3
int val = 0;         // variable to store the read value


void setup()
{
  //initialize serial communications at a 9600 baud rate
  Serial.begin(9600);
}
void loop()
{

  //send 'Hello n' over the serial port
  val = analogRead(analogPin);  // read the input pin
  Serial.println(val);
  //wait 1 second
  delay(50);
}
