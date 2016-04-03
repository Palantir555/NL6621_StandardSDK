# NL6621_StandardSDK
NL6621标准SDK代码

--------------------------------------------------------------------------------

GCC port of the NL6621 Standard SDK
===================================

The [NL6621_StandardSDK](https://github.com/NufrontIOT/NL6621_StandardSDK) is
written for the Keil IDE. The purpose of this project is to port that SDK to gcc
and create a more open SDK all around.

The NL6621:

- 160MHz ARM Cortex-M3 SoC
- Wi-Fi
- 448KB RAM
- 32 GPIOs, SPI, I2C, I2S digital audio…

## Contents of the Standard SDK

### Root

| Folder   | Contents                                                                             |
|----------|--------------------------------------------------------------------------------------|
| Document | A PDF with the SDK manual in Chinese                                                 |
| Project  | 2 uVision projects (Keil) which include the NL6621's linker script in `scat` format  |
| Source   | SDK Source Code                                                                      |
| Tool     | Examples and Multiple .exe applications for flashing, generating binaries, etc.      |

### SDK Source Code File Hierarchy

| Folder  | Contents                                                                              |
|---------|---------------------------------------------------------------------------------------|
| App     | 2 sample applications: `DhcpServer` and `DnsServer`                                   |
| BOOT    | 1 assembly startup file: `CortexM3_startup.s`                                         |
| BSP     | Multiple peripheral libraries and 1 assembly file: `cortexm3_macro.s`                 |
| Lib     | Multiple pre-compiled library files for `libairkiss` and `wcore`                      |
| Include | Headers for the pre-compiled libraries in `Lib`                                       |
| LwIP    | LwIP source code with NL6621 port                                                     |
| Ports   | Cortex-M3 os and cpu source code and 2 assembly files: `cpu_a.asm` and `os_cpu_a.asm` |
| Sys     | Sample application using uCOS and other SDK elements                                  |
| uCOS-II | source code for the uCOS RTOS with its NL6621 port                                    |

## Roadmap

### Compile the SDK using GCC

The first step is to write a [Makefile](Source/Makefile) that compiles the SDK
using the `arm-none-eabi-gcc` toolchain.

We won't try to link anything because we don't have a GNU linker script yet.
The idea is to make sure the SDK doesn't have any kind of Keil-specific
dependencies.

- [Good post](http://www.keil.com/support/docs/2968.htm) on porting source code
from GCC to Keil. Gives compiler instruction differences between the compilers.
- [Great comment](https://github.com/tidklaas/nl6621/issues/1#issuecomment-204756480)
from @tidklaas explaining some of the memory regions. He's managed to build and
flash the NL6621 on SRAM.

TODO:

- Fix the compilation warnings regarding __dsb(0xf) and __isb(0xf) in mpu.c:64
and mpu.c:66 -- `-Wimplicit-function-declaration`
- Get rid of all the `-Wincompatible-pointer-types` compilation warnings
- Write the compilation commands for the asm sources. Currently commented in the
Makefile's File Creation Rules.

### Write a GNU linker script

In order to compile our apps into flashable binaries, we'll need a linker script.

The StandardSDK includes 3 of them:

1. [scatter.scat](Project/PrjSdkOsIpRom/scatter.scat)
2. [scatter_jtag.scat](Projects/PrjSdkRam/scatter_jtag.scat)
3. [scatter_loader.scat](Projects/PrjSdkRam/scatter_loader.scat)

The problem with these linker scripts is that they're written in scatter format.
GCC does not support that format, so either we find a way to add GCC scatter support
or -preferably- we port the scripts for GNU.

### Write the linker step and compile a flashable binary

Once we have the SDK compiling and the linker script ready we should be able to
compile our own hello world!

Wine doesn't seem to like tha flasher .exe, so we'll have to use Windows to flash
the binary for the time being.

### Reverse the custom flashing protocol

There's a big issue with releasing an .exe application to flash the devices with your SDK:
There's no way for anybody else to know what the device expects exactly when we try
to send our binary over the wire.

Reversing the protocol (or identifying it if it's a standard one) should be easy
enough: Sniff the serial traffic while the StandardSDK's magic binary flashes the
device and read through the bytes to reverse the protocol.

### Write a flashing script

Once we undersand the byte sequence expected by the device, writing a script
that reproduces it shouldn't be an issue.

### Port uCOS-II to FreeRTOS

The uCOS-II RTOS used by the StandardSDK is under a commercial license.
In order to use a more open alternative like FreeRTOS, we need 2 things:

1. Port FreeRTOS for the NL6621. Since the NL6621 is a Cortex-M3, it's most likely
already supported by FreeRTOS. Including it in the SDK and modifying the Makefile
would be straightforward.
2. Re-implement the multiple RTOS references across the SDK. Using #defines we
could support both FreeRTOS and uCOS-II and pick one via Make arguments.

The big problem with porting the RTOS is in the 2nd step. If one of the binaries
that form part of the Standard SDK includes references to the uCOS-II RTOS,
there's no way for us to modify it for FreeRTOS. If we can't compile a useful
app without that binary, the SDK would be **NOT PORTABLE** to any other RTOS.
