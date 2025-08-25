#include <WiFiManager.h> 

void setup() {
    Serial.begin(115200);
    
    delay(500);

    Serial.printf("WiFiManager Starting config portal\n");

    WiFiManager wm;

    WiFiManagerParameter custom_wpaUser("wpaUser", "WPA User", "myuser", 64);
    wm.addParameter(&custom_wpaUser);
    
    wm.startConfigPortal();
    if (WiFi.status() == WL_CONNECTED) {
        Serial.printf("WiFiManager sucesfully CONNECTED\n");
    } else {
        Serial.printf("WiFiManager configuration failed or timed out\n");
    }
}

void loop() {
    
}