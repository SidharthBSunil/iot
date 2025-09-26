#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials
char ssid[] = "Your_WiFi_Name";     // change with your WiFi SSID
char pass[] = "Your_WiFi_Password"; // change with your WiFi Password

// Pin for LED
#define LED_PIN 12

BLYNK_WRITE(V1) // When Virtual Pin V1 on Blynk app changes
{
  int pinValue = param.asInt(); // Get value from Blynk app (0 or 1)
  digitalWrite(LED_PIN, pinValue); 
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Keep LED OFF initially

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}