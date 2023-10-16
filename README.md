# ATTiny85 Digispark Scripts

## DISCLAIMER

This is highly for education purposes only and testing. This should not be used for malicious intent. Any misuse of the provided scripts is highly illegal and can get you into trouble. If you do wish to perform any action on other computers, ensure you have prior approval from the rightful owner. Remember: hack responsibly.

## TL;DR

This repository contains the framework to use a `Bad USB` using ATTiny85 Digispark scripting. The entirety of this framework is to be used on your attacker machine/VPS. I highly recommend cloning this repository and working off of it. Follow the `Step-by-Step Guide` to fully setup using `DigitalOcean` as the attacker VPS of choice.

### NOTE

> None of this is originally made by me. This is a collection of my favourite scripts out there and modified to suit this framework. To se the original creators, head over to the `Credits` section of this document.

## Pre-Requisites

You need the following on your machine to load the scripts onto your USB:

1. Arduino IDE configured following this [site](https://startingelectronics.org/tutorials/arduino/digispark/digispark-windows-setup/).

You need to have the following on your VPS or attacker machine:

1. Python3
2. Internet Connection

## Initial Setup

### Your Attacker VPS

Setup a `Digital Ocean VPS Droplet` with Ubuntu LTS and perform a full upgrade.

Clone this repository into the droplet and go into the directory.

Within the `payloads/` directory, host a simple HTTP server using Python3 using:

```bash
cd payloads
python3 -m http.server 80
```

*Note: To run this HTTP server after you close the CLI, consider using `screen`. Documentation can be found [here](https://www.gnu.org/software/screen/manual/screen.html).*

### Your Bad USB

You can use the readily available script in the file [The-Go-To.ino](./scripts/The-Go-To.ino) for this tutorial.

Open `Arduino IDE` and paste the contents of the file. Load the script onto your `Bad USB`.

*Note: Remember to alter the script contents to fit your needs, such as the attacker's HTTP server where you host the payload.*

## The Attack

Now all you need to do is plug in your `Bad USB` on your victim's machine and let the magic happen. On your attacker machine, you should be able to see a connection being made from the victims machine. This means that the payload has been downloaded and if all goes well you should be able to obtain a persitent reverse shell by running:

```bash
nc -lnvp 4444
```

### Exploitation

From here you can perform tasks just as any other reverse shell. There are some additional commands as well:

1. screenshot
2. transfer
3. rm-all

For a more detailed and in-depth guide, here is a YouTube video:

TBD
