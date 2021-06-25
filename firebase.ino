#include <WiFi.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "https://aula-esp32-96abd-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "MLhFrHWxLI9e3ZHbF6BiqhQhf0ru7r8l6A4ErmQ6"
#define WIFI_SSID "iptime_ring"
#define WIFI_PASSWORD ""

FirebaseData firebaseData;

FirebaseJson json;

int i=0;
void setup() {
 Serial.begin(115200);
 Serial.println();
 WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
 Serial.print("Conectado al Wi-Fi");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
}

 
void loop() {
  json.set("/esp", i);
  i++;
  Firebase.updateNode(firebaseData,"/wow",json);
  delay(500);
}
