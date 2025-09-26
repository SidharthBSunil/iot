#define BLYNK_TEMPLATE_ID "TMPL3FG_sX25Z"
#define BLYNK_TEMPLATE_NAME "Device"
#define BLYNK_AUTH_TOKEN "uUWw6YB1LOua4SFDhjzbOdtdgEZ-4r4Y"   // Your auth token

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials
char ssid[] = "SpaceX";
char pass[] = "12345678";

const int ledPin = 5; // D1 = GPIO5

// Function called when button widget on V0 changes
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();

  if (pinValue) {
    digitalWrite(ledPin, HIGH); 
    Serial.println("LED is ON (D1)");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("LED is OFF (D1)");
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); 

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}
