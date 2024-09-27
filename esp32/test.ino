#include <usbdrvce.h> // Include the usbdrvce library

void setup() {
    // Initialize USB communication
    usbdrvce_init();
    Serial.begin(9600);
}

void loop() {
    // Check if the USB device is connected
    if (usbdrvce_connected()) {
        // Read data from the calculator
        if (usbdrvce_available()) {
            char data = usbdrvce_read();
            // Process the data
            processData(data);
        }
    }
}

void processData(char data) {
    // Implement your data processing logic here
}