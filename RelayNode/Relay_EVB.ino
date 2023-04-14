// simple code to test the relay output evaluation board

#include <nocan.h>;


/* to send the feedback messages */
NocanChannelId cid;

/* this node */
NocanNodeId nodeId;

#define ON_PIN  5
#define OFF_PIN  4

// relay state ON / Off
bool State = false;

void SetRelay(){
  if (State) {
    digitalWrite(ON_PIN, HIGH);
    delay(15);
    digitalWrite(ON_PIN, LOW);    
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(OFF_PIN, HIGH);
    delay(15);
    digitalWrite(OFF_PIN, LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }    
}


void setup() {
  // put your setup code here, to run once:

  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(OFF_PIN, OUTPUT);
  pinMode(ON_PIN, OUTPUT);


  /* setup NoCan stuff */
  nodeId = Nocan.open(); //todo: what happens if Pi Master not available etc
  Nocan.registerChannel("relay", &cid);
  Nocan.subscribeChannel(cid);
  SetRelay();
}


void loop() {
  // put your main code here, to run repeatedly:

  NocanMessage msg;
  if (Nocan.receivePending()) {
    Nocan.receiveMessage(&msg);
    if (msg.data_len >=1){
      switch (msg.data[0]) {
        case 'c':
        case 'C':
        case '1':
          State = true;
         // digitalWrite(RELAY_PIN, HIGH);
          break;
        case 'o':
        case 'O':
        case '0': 
          State = false;
          //digitalWrite(RELAY_PIN, LOW);
          break;
      }
      SetRelay();

    }
  }    
}
