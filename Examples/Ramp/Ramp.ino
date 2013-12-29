// Include libraries this sketch will use
#include  <Wire.h>
#include  <MCP47X6.h>

// Instantiate objects used in this project
MCP47X6 theDAC=MCP47X6(MCP47X6_DEFAULT_ADDRESS);

void setup() {
  Wire.begin();
  TWBR = 12;  // 400 kHz (maximum)

  Serial.begin(9600); // Open serial connection to send info to the host
  while (!Serial) {}  // wait for Serial comms to become ready
  Serial.println("Starting up");
  Serial.println("Testing device connection...");
  Serial.println(theDAC.testConnection() ? "MCP47X6 connection successful" : "MCP47X6 connection failed");

  theDAC.begin();
  theDAC.setVReference(MCP47X6_VREF_VDD);
  theDAC.setGain(MCP47X6_GAIN_1X);
  theDAC.saveSettings();
  
}

void loop() {
  uint16_t level = 0;
  theDAC.setOutputLevel(level++);
}

