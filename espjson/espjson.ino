#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

// WiFi Parameters
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
// variables
int key = 0;
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
}

void loop() {
  // Check WiFi Status
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;  //Object of class HTTPClient
    http.begin("http://demo4657392.mockable.io/list-tag-ids");
    int httpCode = http.GET();
    //Check the returning code                                                                  
    if (httpCode > 0) {
      // Parsing
      const size_t capacity = JSON_ARRAY_SIZE(10000) + 10001*JSON_OBJECT_SIZE(1) + 265450;
      DynamicJsonDocument doc(capacity);
      deserializeJson(doc, http.getString());
      JsonArray student_id = doc["student_id"];
      unsigned long StartTime = millis();
      Serial.print("Enter the Key");
      key = Serial.read()
      Serial.println("the corresponding value to the key is: ")
      Serial.print(student_id[key-1]["key"]);
      unsigned long CurrentTime = millis();
      unsigned long ElapsedTime = CurrentTime - StartTime;
      Serial.println("time elapsed in query(ms): ")
      Serial.print(ElapsedTime)


    }
    http.end();   //Close connection
  }
  // Delay
  delay(60000);
}
