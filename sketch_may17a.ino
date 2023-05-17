#include <ESP32Servo.h>

#define LDR_PIN 34 // LDR analog input pin
#define LED_PIN_1 32 // LED 1 pin
#define LED_PIN_2 33 // LED 2 pin
#define SERVO_PIN 12 // Servo motor control pin


Servo servo;     // Servo object
void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  
  servo.attach(SERVO_PIN);
  servo.write(90); // definir posicao inicial em 90
}

void loop()
{
  
  int ldrValue = analogRead(LDR_PIN);
  int servoAngle = map(ldrValue, 1850, 4095, 0, 180);
  Serial.print("LDR OUTPUT Value: ");
  Serial.println(ldrValue);
  if (ldrValue < 3000) {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, LOW);
  } else {
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, HIGH);
  }
  servo.write(servoAngle);

  delay(100);
}