# The Bad USB Framework

## Changelogs

> 21/08/2024 - Revisited this project and want a proper close and end to it. So, this marks the final update to the guide and closure of the project. Minor updates will be posted.

## DISCLAIMER

This framework guide is intended for **educational purposes only!** Malicious use of this framework is **NOT** encouraged. If you wish to perform of the actions shown on property that you do not own, ensure you have prior approval from the rightful owner. 

Remember: **hack responsibly.**

## About The Framework

This framework is your one-stop-shop to get you up and running to create malicious USBs and start your phishing campaign using accessible and easy to obtain tools:

1. `ATTiny85 Micro Controller`
2. `Arduino IDE`
3. `Digital Ocean VPS`

With this guide you will be using this repository in your private VPS (we will be using Digital Ocean) and setting up your "hacker server".

### Disclaimer

> None of this is originally made by me. This is a collection of my favourite scripts out there and modified to suit this framework. To se the original creators, head over to the `Credits` section of this document.

## Pre-Requisites

You will need the following:

1. ATTiny85 Micro Controller (You can purchase one online for cheap)
2. A [Digital Ocean](https://digitalocean.com) account
3. A computer (Obviously)

## Setting Up your PC

Firstly, we will set up your PC to program your ATTiny85.

1. Download and install the latest [Digistump Arduino Release](https://github.com/digistump/DigistumpArduino/releases) by running `Install Drivers.exe`.
2. Download the latest version of [Arduino IDE](https://docs.arduino.cc/software/ide/).
3. After install go to `File > Preferences` and under `Additional boards manager URLs` insert the following URL: `https://raw.githubusercontent.com/digistump/arduino-boards-index/master/package_digistump_index.json`.
   1. ![File to Preference](./img/file_to_preferences.png)
   2. ![Additional Board Manager](./img/additional_boards_manager.png)
   3. > NOTE: If there is already a URL, you can insert multiple URLs by separating them with a semi-colon `;`.
4. Under `Tools > Board: > Board Manager`, select `Digistump AVR Boards` and install.
   1. ![Getting to Boards Manager](./img/install_digistump.png)
   2. ![Installing Digistump](./img/install_digistump2.png)
5. You're ready to program your ATTiny85!

## Setting Up your Attacker VPS

Before we start programming your malicious USB, for this guide, you are going to need to setup your attacker VPS.

You need to have the following on your VPS or attacker machine:

1. Python3

Setup a `Digital Ocean VPS Droplet` with Ubuntu LTS and perform a full upgrade.

Clone this repository into the droplet and go into the directory.

![The frameworks home directory](./img/home_directory.png)

### Modifying The Payload

There is only 1 file we need to modify for this demo: `./payloads/payload.ps1`.

Within the files, you will find `[IP_ADDRESS]` and `[PORT]`.

Change `[IP_ADDRESS]` to your VPS' public IP address and `[PORT]` to your preferred `netcat` port. Default is `4444`.

### Setting Up Payload File Server

Within the `payloads/` directory, host a simple HTTP server using Python3 using the following commands:

```bash
cd payloads
python3 -m http.server 80
```

![Hosting the file server.](./img/hosting_fileserver.png)

*Note: To run this HTTP server after you close the CLI, consider using `screen`. Documentation can be found [here](https://www.gnu.org/software/screen/manual/screen.html).*

## Programming the Bad USB

Now we can focus on programming your malicious USB. Back to your personal computer, under the `scripts` folder, it contains various Arduino scripts to get you started on your journey of programming bad USBs. For the sake of simplicity, we will be using `The-Go-To.ino` file. It is a script sequence to provide us, the attacker, a reverse shell instance from our victim.

1. To begin, select the correct board by selecting `Tools > Board > Digistump AVR Boards > Digispark (Default - 16.5mhz)`.
2. Copy and paste the script into the Arduino IDE.
   1. Be sure to change the `[FILE SERVER]` to your hacker machine IP address. For example: `http://999.999.999.999`. If the port is not port 80, specify the port as well.
3. Then click `Upload` and once prompted to plug in the USB, do so. It should take at most 5 seconds to program. Once done, remove the USB.
4. Now it is primed to be used at your own discretion. All you have to do is plug it in to your victim's machine.

## The Attack

Now all you need to do is plug in your `Bad USB` on your victim's machine and let the magic happen. On your attacker machine, you should be able to see a connection being made from the victims machine. This means that the payload has been downloaded and if all goes well you should be able to obtain a persistent reverse shell by running:

```bash
nc -lnvp 4444
```

![Reverse Shell](./img/netcat.png)

### Exploitations

From here you can perform tasks just as any other reverse shell. There are some additional commands as well:

1. `screenshot` (Returns a Base64 encoding of their screenshot. Pipe the output into a file and use `./exfiltrated_data/reverse_shell/Base62_Decoder.sh` to decode the files.)
2. `transfer` (Similar to `screenshot` but transfers files. **Must use absolute path.**)
3. `rm-all` (Removes connection and deletes all attacker files. Leaves no trace.)

### How to Save and Decode Screenshots and Extracted Files

Change to the `./exfiltrated_data/reverse_shell/` directory and run `netcat` here. Be sure to pipe the outputs into a file.

```bash
nc -lnvp 4444 | tee output
```

Once done, you can decode all the files and screeenshots using the following command:

```bash
bash ./Base62_Decoder.sh ./output
```

It will return with all the different files and you can view them as if they were the original.

## Moving On

This is just the start for you. Go crazy. But remember: **hack responsibly**. Have fun suckers - *narwhal*

## Credits

[AFNordal - Persistant Reverse Shell](https://github.com/AFNordal/powershell_reverseTCPshell)

[CedArctic - Various DigitSpark Scripts](https://github.com/CedArctic/DigiSpark-Scripts)
