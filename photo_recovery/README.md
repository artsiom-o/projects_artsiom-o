# JPEG Image Recovery Program

## Description
This program recovers JPEG images from a forensic image. It reads data from an input file in blocks of 512 bytes. When it finds a block that signifies the start of a new JPEG image, it closes the current output file (if any), opens a new one, and starts writing to it. It continues to write to the same output file until it finds another such block. The process repeats until all data blocks have been read.

## Usage
To use this program, compile it with a C compiler and run the resulting executable with the name of the forensic image file as a command-line argument. For example:

```bash
gcc -o recover recover.c
./recover card.raw
