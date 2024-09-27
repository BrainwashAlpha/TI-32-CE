#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <TinyUSB.h>

// WiFi credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// GPT-3 API endpoint
const char* gpt3_endpoint = "https://api.openai.com/v1/engines/davinci-codex/completions";
const char* gpt3_api_key = "your_GPT3_API_KEY";

// USB setup
TinyUSB_Device device;

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    // Initialize USB
    TinyUSB_Device_Init(0);
}

void loop() {
    if (TinyUSB_Device_IsConnected()) {
        if (Serial.available()) {
            String question = Serial.readStringUntil('\n');
            String answer = getGPT3Response(question);
            Serial.println(answer);
        }
    }
}

String getGPT3Response(String question) {
    WiFiClientSecure client;
    HTTPClient http;

    http.begin(client, gpt3_endpoint);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Authorization", String("Bearer ") + gpt3_api_key);

    String payload = "{\"prompt\":\"" + question + "\",\"max_tokens\":100}";
    int httpResponseCode = http.POST(payload);

    String response;
    if (httpResponseCode > 0) {
        response = http.getString();
    } else {
        response = "Error in HTTP request";
    }

    http.end();
    return response;
}