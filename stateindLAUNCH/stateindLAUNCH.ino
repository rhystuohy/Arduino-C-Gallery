const int goPin = 11; // Define the pin connected to your power source
const int cdPin = 12;

void setup() {
  pinMode(goPin, OUTPUT);
  pinMode(cdPin, OUTPUT); // Set the power pin as output
}

void loop() {
  // Start 10 second timer
  delay(5000); // Delay for 10 seconds (10000 milliseconds) 

  // Turn on power for 2 seconds
  digitalWrite(cdPin, HIGH); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, LOW); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, HIGH); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, LOW); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, HIGH); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, LOW); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, HIGH); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, LOW); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, HIGH); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, LOW); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, HIGH); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, LOW); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, HIGH); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, LOW); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, HIGH); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, LOW); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(cdPin, HIGH); // Set the power pin high (turn on power)
  delay(500);
  digitalWrite(goPin, HIGH); // Set the power pin high (turn on power)
  delay(500);// Delay for 2 seconds (2000 milliseconds) 
  digitalWrite(cdPin, LOW); // Set the power pin high (turn on power)
  delay(2000);
  digitalWrite(goPin, LOW); // Set the power pin high (turn on power)
  delay(1000000);
  }
