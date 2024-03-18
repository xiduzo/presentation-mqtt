#include <MQTT.h>
#include <WiFi.h>

WiFiClient net;
// https://www.shiftr.io/docs/manuals/arduino
MQTTClient client;

const int PIN_RED = 23;
const int PIN_GREEN = 22;
const int PIN_BLUE = 14;

void connect() {
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  while (!client.connect("arduino-feather-2", "mdd", "loislane")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("Connected!");

  client.subscribe("color/+");
}

void messageReceived(String &topic, String &payload) {
  Serial.println(topic + ": " + payload);
  if (topic == "color/red") {
    analogWrite(PIN_RED, payload.toInt());
  } else if (topic == "color/green") {
    analogWrite(PIN_GREEN, payload.toInt());
  } else if (topic == "color/blue") {
    analogWrite(PIN_BLUE, payload.toInt());
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin("H369AAB4EBC", "9CFCA63ADC96");
  client.begin("mdd-tardis.net", net);
  client.onMessage(messageReceived);

  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  client.loop();
  delay(10);
  digitalWrite(LED_BUILTIN, client.connected()); // Status LED
  if (!client.connected()) {
    connect();
  }
}
