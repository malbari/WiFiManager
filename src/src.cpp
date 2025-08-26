#include <WiFiManager.h>
#include <nvs_flash.h>
#include <nvs.h>
#include <SPIFFS.h>

void setup()
{
    Serial.begin(115200);

    delay(500);

    if (!SPIFFS.begin(true))
    {
        Serial.printf("SPIFFS fallita\n");
        return;
    }
    else
    {
        Serial.printf("SPIFFS OK\n");
    }

    Serial.printf("Initializing NVS\n");

    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        Serial.printf("Erasing NVS\n");

        nvs_flash_erase();
        nvs_flash_init();
    }
    else
    {
        Serial.printf("NVS already OK\n");
    }

    Serial.printf("WiFiManager Starting config portal\n");

    WiFiManager wm;

    WiFiManagerParameter custom_wpaUser("wpaUser", "WPA User", "myuser", 64);
    wm.addParameter(&custom_wpaUser);
    wm.autoConnect();

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.printf("WiFiManager sucesfully CONNECTED\n");
    }
    else
    {
        Serial.printf("WiFiManager configuration failed or timed out\n");
    }
}

void loop()
{
}