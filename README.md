# ATTiny Reverse Shell

## TLDR

`ATTiny Reverse Shell` HID script to be used with an ATTiny85 USB. It will perform various things on the target host swiftly.

```
This script will perform various tasks on the target host and should be exercised with caution.

DO NOT RUN SCRIPT ON HOSTS YOU DON'T HAVE EXPLICIT PERMISSION TO PERFORM ON!

What will it do?
----------------
1. Enable running scripts on PowerShell.
2. Download and execute payload from fileserver and provide a persistent reverse shell capable of transfering files, taking screenshots, and exiting without leaving a trace.
3. Activate a keylogger and will send the recording to your unique webhook.site URL.
4. Create an admin user account and allow Remote Desktop Access as a backdoor access alternative to the reverse shell.


```

## Pre-Requisites

Your machine or VPS must have the following:

1. Python 3
2. Bash (or anything that can run bash scripts)
3. An internet connection (obviously)

Your target machine should have the following:

1. Is running Windows
2. Has powershell
3. Is connected to internet

## Setup

1. On your machine or VPS, clone this repository.

`To be continued`
