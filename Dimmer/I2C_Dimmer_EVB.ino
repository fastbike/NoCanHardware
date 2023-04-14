// simple code to test the dimmer evaluation board
// code will connect over I2C, using AdaFruit library and rive voltage up and down on one channel so that can
// be observed

// Basic demo for configuring the MCP4728 4-Channel 12-bit I2C DAC
#include <Adafruit_MCP4728.h>
#include <Wire.h>
#include <nocan.h>;


/* to send the feedback messages */
NocanChannelId cid;
NocanChannelId cid1;
NocanChannelId cid2;

/* this node */
NocanNodeId nodeId;


Adafruit_MCP4728 mcp;

int channelA = 400;
bool upwards = true;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_BUILTIN, OUTPUT);

  /* setup NoCan stuff */
  nodeId = Nocan.open(); //todo: what happens if Pi Master not available etc
  Nocan.registerChannel("brightness", &cid);
  Nocan.subscribeChannel(cid);

  // add some other channels - not really need but want to see the id
  Nocan.registerChannel("brightness1", &cid1);
  Nocan.registerChannel("brightness2", &cid1);
  
  
/* */
  // Try to initialize!
  if (!mcp.begin()) {
   // Serial.println("Failed to find MCP4728 chip");
    while (1) {
      delay(10);
    }
  }
  mcp.setChannelValue(MCP4728_CHANNEL_A, channelA); 
  mcp.setChannelValue(MCP4728_CHANNEL_B, 2048);
  mcp.setChannelValue(MCP4728_CHANNEL_C, 1024);
  mcp.setChannelValue(MCP4728_CHANNEL_D, 0);
  

}

String msg_to_string(NocanMessage &msg)
{
  // nocan messages are always <= 64 bytes long
  char buf[65];

  for (int i=0; i<msg.data_len; i++)
  {
    buf[i] = msg.data[i];
  }
  buf[msg.data_len]=0;
  return String(buf);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(75);
  digitalWrite(LED_BUILTIN, LOW);
  delay(75);

  int brightness = 0;
  NocanMessage msg;
  if (Nocan.receivePending()) {
    Nocan.receiveMessage(&msg);
    if (msg.data_len >=1){
      String _brightness = msg_to_string(msg);
      brightness = _brightness.toInt();
      if (brightness <= 0) {
        brightness = 0;
      }
      if (brightness >= 100) {
        brightness = 100;
      }      
    }
    // voltage control is 1-10v, so 37mv per 1% of brightness, plus offset of 395
    // value needs to be max of 4095
    if (brightness > 0){
      brightness =  brightness * 37 + 395;  
    }
    mcp.setChannelValue(MCP4728_CHANNEL_A, brightness);

/* NB: note that brightness values below 20% are not worth having.
 *  Also that response is not linear so a lookup table required ?
 */
    
  }
  

/*
  if (upwards) {    
    if (channelA > 3990) {
      upwards = false;
    } else {
      channelA = channelA + 50;
    }    
  }
  else {
    if (channelA < 500) {
      upwards = true;
    } else {
      channelA = channelA - 50;
    }        
  }


   mcp.setChannelValue(MCP4728_CHANNEL_A, channelA);
*/
}
