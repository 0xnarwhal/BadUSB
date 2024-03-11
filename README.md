# Bad USB Framework

## DISCLAIMER

This framework is intended for educational purposes. Malicious use of this framework is **NOT** encouraged. If you wish to perform any action on other computers, ensure you have prior approval from the rightful owner. Remember: **hack responsibly.**

## TLDR

This framework is intended to get you started with scripting your own malicious USB using the `ATTiny85 Digispark scripting`. The entirety of this framework is intended to be used on your attacker machine/VPS. I highly recommend cloning this repository and working off of it. Follow the `Step-by-Step Guide` to fully setup using `DigitalOcean` as the attacker VPS of choice.

### NOTE

> None of this is originally made by me. This is a collection of my favourite scripts out there and modified to suit this framework. To se the original creators, head over to the `Credits` section of this document.

## Pre-Requisites

You can purchase a pre-made bad USB online or make one your own. **Make sure that it is using an ATTiny85 arduino!**

You need the following on your machine to load the scripts onto your USB:

1. Arduino IDE configured following this [tutorial](https://startingelectronics.org/tutorials/arduino/digispark/digispark-windows-setup/).

You need to have the following on your VPS or attacker machine:

1. Python3
2. Internet Connection (Duh)

## Setup

For this demo/tutorial we will be focussing on the basic script to get you started. Use what you know and have learned to make your own attack methods. Be creative!

The file we are focusing on is `./scripts/The-Go-To.ino` where we will enable scripts on the victims machine and return a persistent reverse shell to us, the attacker.

### Seting Up your VPS

Setup a `Digital Ocean VPS Droplet` with Ubuntu LTS and perform a full upgrade.

Clone this repository into the droplet and go into the directory.

![The frameworks home directory](./README_img/home_directory.png)

### Modifying Files

There are two files we need to modify for this demo: `./payloads/payload.ps1` and `./scritps/The-Go-To.ino`.

Within the files, you will find either `[FILE_SERVER]` or `[IP_ADDRESS]`.

In `payloads.ps1`, just change it to the VPS's IP address. In `The-Go-To.ino`, change it to `http://<IP_ADDRESS>`.

### Setting Up Payload File Server

Within the `payloads/` directory, host a simple HTTP server using Python3 using:

```bash
cd payloads
python3 -m http.server 80
```

![Hosting the fileserver.](./README_img/hosting_fileserver.png)

*Note: To run this HTTP server after you close the CLI, consider using `screen`. Documentation can be found [here](https://www.gnu.org/software/screen/manual/screen.html).*

### Your Bad USB

You can use the readily available script in the file [The-Go-To.ino](./scripts/The-Go-To.ino) for this tutorial.

Open `Arduino IDE` and paste the contents of the file. Load the script onto your `Bad USB`.

*Note: Remember to alter the script contents to fit your needs, such as the attacker's HTTP server where you are hosting the payload.*

## The Attack

Now all you need to do is plug in your `Bad USB` on your victim's machine and let the magic happen. On your attacker machine, you should be able to see a connection being made from the victims machine. This means that the payload has been downloaded and if all goes well you should be able to obtain a persitent reverse shell by running:

```bash
nc -lnvp 4444
```

![Reverse Shell](./README_img/netcat.png)

### Exploitations

From here you can perform tasks just as any other reverse shell. There are some additional commands as well:

1. `screenshot` (Returns a Base64 encoding of their screenshot. Pipe the output into a file and use `./exfiltrated_data/reverse_shell/Base62_Decoder.sh` to decode the files.)
2. `transfer` (Similar to `screenshot` but transfers files. Must use absolute path.)
3. `rm-all` (Removes connection and deletes all files. Leaving no trace.)

### Recommendations

Change to the `./exfiltrated_data/reverse_shell/` directory and run `netcat` here. Be sure to pipe the outputs into a file.

```bash
nc -lnvp 4444 | tee output
```

Once done, you can decode all the exfiltrated files and screeenshots using the following command:

```bash
bash ./Base62_Decoder.sh ./output
```

It will then decode all the files that you've extracted.

## Moving On

This is just the start for you. Go crazy. But remember: **hack responsibly**. Have fun suckers - *narwhal*

## Credits

[AFNordal - Persistant Reverse Shell](https://github.com/AFNordal/powershell_reverseTCPshell)

[CedArctic - Various DigitSpark Scripts](https://github.com/CedArctic/DigiSpark-Scripts)
