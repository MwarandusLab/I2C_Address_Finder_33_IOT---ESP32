#include <Wire.h>

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
  while (!Serial);

  // Initialize the I2C communication
  Wire.begin();

  Serial.println("Scanning for I2C devices...");
}

void loop() {
  byte error, address;
  int devices = 0;

  // Loop through possible I2C addresses (7-bit)
  for (address = 1; address < 127; address++) {
    // Try to connect to the device
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {  // No error means a device is found
      Serial.print("Found I2C device at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println();

      devices++;
      delay(100);  // Optional delay for readability
    }
  }

  if (devices == 0) {
    Serial.println("No I2C devices found.");
  }

  delay(5000);  // Delay for 5 seconds before scanning again
}
