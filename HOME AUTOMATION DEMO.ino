#include <WiFi.h>
#include <PubSubClient.h>
#include "DHTesp.h"
const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASS = "YOUR_WIFI_PASSWORD";
const char* MQTT_SERVER = "industrial.api.ubidots.com";
const int MQTT_PORT = 1883;

const char* UBIDOTS_TOKEN = "YOUR_UBIDOTS_TOKEN";


const char* DEVICE_LABEL = "esp32_smart_home";


const char* TEMP_LABEL  = "temperature";
const char* LIGHT_LABEL = "light_intensity";
const char* FAN_LABEL   = "fan_status";
const char* BULB_LABEL  = "light_status";

// DHT11
#define DHT_PIN 15
DHTesp dht;

// LDR
#define LDR_PIN 34

// Relay Pins
#define FAN_RELAY   26
#define LIGHT_RELAY 27

float TEMP_THRESHOLD = 30.0;
int LIGHT_THRESHOLD  = 1500;

WiFiClient wifiClient;
PubSubClient client(wifiClient);



void connectWiFi() {

  Serial.print("Connecting to WiFi");

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}


void connectMQTT() {

  while (!client.connected()) {

    Serial.print("Connecting to Ubidots MQTT...");

    if (client.connect(
          DEVICE_LABEL,
          UBIDOTS_TOKEN,
          "")) {

      Serial.println("Connected!");
    }
    else {

      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Retrying in 2 seconds...");

      delay(2000);
    }
  }
}


void setup() {

  Serial.begin(115200);

  // DHT Setup
  dht.setup(DHT_PIN, DHTesp::DHT11);

  // Relay Pins
  pinMode(FAN_RELAY, OUTPUT);
  pinMode(LIGHT_RELAY, OUTPUT);

  // Initially OFF
  digitalWrite(FAN_RELAY, LOW);
  digitalWrite(LIGHT_RELAY, LOW);

  connectWiFi();

  client.setServer(MQTT_SERVER, MQTT_PORT);

  Serial.println("Smart Home Automation System Started");
}
void loop() {

  // Reconnect MQTT if disconnected
  if (!client.connected()) {
    connectMQTT();
  }

  client.loop();
  float temperature = dht.getTemperature();
  int lightValue = analogRead(LDR_PIN);

   bool fanStatus = false;

  if (temperature > TEMP_THRESHOLD) {

    digitalWrite(FAN_RELAY, HIGH);
    fanStatus = true;
  }
  else {

    digitalWrite(FAN_RELAY, LOW);
    fanStatus = false;
  }
  bool lightStatus = false;

  if (lightValue < LIGHT_THRESHOLD) {

    digitalWrite(LIGHT_RELAY, HIGH);
    lightStatus = true;
  }
  else {

    digitalWrite(LIGHT_RELAY, LOW);
    lightStatus = false;
  }
  String payload = "{";

  payload += "\"temperature\":";
  payload += temperature;

  payload += ",";

  payload += "\"light_intensity\":";
  payload += lightValue;

  payload += ",";

  payload += "\"fan_status\":";
  payload += fanStatus;

  payload += ",";

  payload += "\"light_status\":";
  payload += lightStatus;

  payload += "}";
  String topic = "/v1.6/devices/";
  topic += DEVICE_LABEL;

  // Publish Data
  client.publish(topic.c_str(), payload.c_str());
  Serial.println("================================");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Light Intensity: ");
  Serial.println(lightValue);

  Serial.print("Fan Status: ");
  Serial.println(fanStatus ? "ON" : "OFF");

  Serial.print("Light Status: ");
  Serial.println(lightStatus ? "ON" : "OFF");

  Serial.println("Data Published to Ubidots");

   delay(1000);
}