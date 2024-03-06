#include <WiFi.h>
#include <MQTT.h>

WiFiClient net;
// https://www.shiftr.io/docs/manuals/arduino
MQTTClient client;

const int PIN_RED   = 14;
const int PIN_GREEN = 32;
const int PIN_BLUE  = 15;

void connect() {
  digitalWrite(LED_BUILTIN, LOW);
  while (WiFi.status() != WL_CONNECTED) { delay(1000); }

  while (!client.connect("arduino-feather-2", "mdd-mqtt-example", "PEpYu4e10cyOLqfw")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("Connected!");
  digitalWrite(LED_BUILTIN, HIGH);

  client.subscribe("color/red");
  client.subscribe("color/green");
  client.subscribe("color/blue");
}

void messageReceived(String &topic, String &payload) {
  Serial.println(topic + ": " + payload);
  if(topic == "color/red") {
    analogWrite(PIN_RED, payload.toInt());
  } else if(topic == "color/green") {
    analogWrite(PIN_GREEN, payload.toInt());
  } else if (topic == "color/blue") {
    analogWrite(PIN_BLUE, payload.toInt());
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin("iotroam", "loislane");
  client.begin("mdd-mqtt-example.cloud.shiftr.io", net);
  client.onMessage(messageReceived);
  
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  connect();
}

void loop() {
  client.loop();
  delay(10);

  if (!client.connected()) { connect(); }
}