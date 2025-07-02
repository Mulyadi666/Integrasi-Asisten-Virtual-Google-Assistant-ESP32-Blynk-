#define BLYNK_TEMPLATE_ID "TMPL6SCL2TAJu"
#define BLYNK_TEMPLATE_NAME "google asisten"
#define BLYNK_AUTH_TOKEN "L5eC6ynTDQBg2fkkjgFK8HYCt5O-zb5K"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define RELAY_PIN 2

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // 0 or 1
  digitalWrite(RELAY_PIN, pinValue);
  Serial.print("Tombol V0: ");
  Serial.println(pinValue);
}

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}
