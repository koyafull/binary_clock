Binary Clock project for my friend's 23 birthday (was 2017).

# Introduction

This project propose an implementation for a ["Raspberry Zero"-based](https://www.raspberrypi.org/products/raspberry-pi-zero-w/ "Raspberry Pi Zero W") binary clock.

It basically turns the numerical hour format (such as `15:23:46`) into a vertical binary representation, each second.

The output must be read as:

```bash
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 1 0 0 1 1 
0 0 1 1 0 1 
1 1 0 1 0 0
 
^ ^ ^ ^ ^ ^ 
' ' ' ' ' ' 
' ' ' ' ' '

1 5:2 3:4 6
```

# Disclaimer

I HAVE NOT created the GPIO lib. I took it from GitHub back then, I'm very sorry my newbie time (well, it's not gone yet for sure) make me unreference it on this project.
So if you do recognize the origin of this library, I would be really pleased to properly add the reference to it.

# Use it

Make it run:

```bash
cd binary_clock
make
make clean
./binary_clock
```

Developping tool:

The `shutup.sh` script aims to switch off and unexport the GPIOs as configured by the `main.cpp` program.

# Known limitations

## Time synchronisation

As the Raspbarry Pi Zero does not embed a clock battery, the time must be syncronized each time it is powered on.

I have personnally configured it to connect to my personnal wifi with the help of this tutorial: 
[Setting up WIFI via the command line](https://www.raspberrypi.org/documentation/configuration/wireless/wireless-cli.md "Raspberry WIFI tutorial")
This way it can synchronize time through a predefined [NTP server](https://en.wikipedia.org/wiki/Network_Time_Protocol "Wikipedia").

## Portability

This project has not been designed to be portable at all, but it should not be hard to be ported as I use only few libraries.

## Error management

Is really basics. It would need to be reviewed.

# Mechanical drawing

Is done using [FreeCAD](https://www.freecadweb.org/ "FreeCAD's homepage").

It simply aims to provide basis of what I have done in order to build my own binary clock support.
