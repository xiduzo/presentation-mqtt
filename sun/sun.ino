#include <WiFi.h>
#include <MQTT.h>

WiFiClient net;
// https://www.shiftr.io/docs/manuals/arduino
MQTTClient client;

// When the WIFI is on we can not use any of the ADC2 channels
// See https://arduino.stackexchange.com/a/84895
// https://cdn-learn.adafruit.com/assets/assets/000/111/179/original/wireless_Adafruit_HUZZAH32_ESP32_Feather_Pinout.png?1651089809
const int LDR_PIN = A2;
int previousValue = 0;

void connect() {
  while (WiFi.status() != WL_CONNECTED) { delay(1000); }

  while (!client.connect("arduino-feather-4", "mdd", "loislane")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("Connected!");
}

void setup() {
  Serial.begin(115200);
  WiFi.begin("H369AAB4EBC", "9CFCA63ADC96");
  client.begin("mdd-tardis.net", net);

  pinMode(LDR_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  client.loop();
  delay(10);

  digitalWrite(LED_BUILTIN, client.connected()); // Status LED
  if (!client.connected()) { connect(); }

  int value = analogRead(LDR_PIN);

  Serial.println(value);
  client.publish("brightness", String(value));
}
