// Include libraries this sketch will use
#include  <Wire.h>
#include  <MCP47X6.h>

// Instantiate objects used in this project
MCP47X6 theDAC=MCP47X6(MCP47X6_DEFAULT_ADDRESS);

void setup() {
  theDAC.testConnection();
  theDAC.begin();
  theDAC.begin(MCP47X6_VREF_VREFPIN & MCP47X6_GAIN_2X);
  theDAC.setVReference(MCP47X6_VREF_VDD);
  theDAC.setGain(MCP47X6_GAIN_1X);
  theDAC.saveSettings();
}

void loop() {
  uint16_t level = 0x123;
  uint8_t byteLevel = 0x45;
  theDAC.setOutputLevel(level);
  theDAC.setOutputLevel(byteLevel);
  theDAC.powerDown();
}

