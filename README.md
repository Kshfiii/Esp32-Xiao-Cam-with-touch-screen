# Xiao esp32-s3 sense based Camera with touch screen

XIAO Cam is a small camera built around the Seeed Studio XIAO ESP32-S3 Sense microcontroller. It displays a live camera feed on a 1.28" round touchscreen, captures photos to a microSD card with a  button press, and lets you browse your shots through a swipe-based gallery; housed inside a custom 3D printed case.
It's for people who are interested in a simple hardware build that actually serves a function. 



## About

XIAO Cam is a custom point-and-shoot camera built from scratch. I did everything myself, from the 3d printed case to the firmware and component selection.

I made this because I wanted to sharpen my CAD skills. I challenged myself to build something that actually works as a real device, and looks professional. Plus I've wanted to buy a digi cam for a while and i thought why not make it myself.
## Usage & Features

1. Power on using the slide switch on the side camera
2. The round screen shows a live camera feed automatically on boot
3. Press the shutter button on the right side of the case to take a photo — it saves instantly to the SD card
4. Swipe up on the touchscreen to open the photo gallery
Swipe left or right to browse your saved photos
5. Swipe down to return to the live viewfinder
6. Charge via the USB-C port on the XIAO esp32 s3 sense

#
P.s. There is a placeholder to attach a lanyard to the camera for practicality.

## Project snippets
![Assembly_front](https://github.com/user-attachments/assets/a1629904-7616-4744-82ce-1f8faa3d9746)
![case](https://github.com/user-attachments/assets/29335652-aac3-4b5a-96c6-8e42c1b66702)
![cad](https://github.com/user-attachments/assets/04864a12-d9a6-4c8d-b14b-d87ade8b941e)


📎 OnShape CAD model (public link): [https://cad.onshape.com/documents/d0d02c920c1d3887f88da338/w/cd12746e145d8d660cbdb08a/e/dfaf3792be18770a6bf41023]

## Firmware setup

Required Libraries:

TFT_eSPI by Bodmer
TJpg_Decoder by Bodmer
Seeed_Arduino_RoundDisplay by Seeed Studio
ESP32 board package by Espressif (via Board Manager)

#Steps before flashing:

1. Cut J3 on the Sense expansion board — see Hardware Note below
2. In TFT_eSPI/User_Setup_Select.h, uncomment:

cpp   #include <User_Setups/Setup202_Seeed_XIAO_Round_Display.h>

3. In Arduino IDE: Tools → Board → XIAO_ESP32S3
4. Tools → PSRAM → OPI PSRAM ← do not skip this, camera will not work without it
5. Upload firmware/xiao_cam/xiao_cam.ino

## Firmware files:

_Files and their functions:_

1. xiao_cam.inoMain : loop and state machine
2. config.hAll : pin definitions and settings
3. camera.h : Camera init and frame 
4. capturesd_card.hSD card init, save photos, list files
5. gallery.hSwipe-based photo gallery

## Hardware Note — J3 Solder Jumper

The XIAO ESP32-S3 Sense and the Round Display both have SD card pull-up resistors on the same SPI lines. This causes a conflict and neither SD slot will work unless you fix it.

_Steps to Fix:_

1. Remove the camera ribbon cable from the Sense board
Flip the Sense expansion board over and find the J3 solder jumper
2. Slice through the solder bridge with a hobby knife
3. Verify with a multimeter that there is no continuity across J3.


This disables the sd card slot of the esp32-sense 
 (don't worry, it's reversible. Just solder J3 back)


## Component List

1. Seeed studio Xiao Esp32-s3 sense
2. 3.7v 400mah rechargeable Lipo Battery 
3. Xiao Esp32 S3 1.28" round touch screen Display
4. Seeed studio OV5640 Camera
5. Tactile switch 
6. Slide switch

## Bill of Materials
| Component | Quantity | Est. Cost (USD) | Purchase Links | 
| :--- | :---: | :--- | :--- | 
| **Seeed studio Xiao Esp32-s3 sense**| 1 | $16.50 | https://www.aliexpress.com/item/1005006988111963.html | 
| **Xiao Esp32 S3 1.28in round touch screen**| 1 | $21.00 | https://www.aliexpress.com/item/1005006989795918.html | 
| **Seeed studio OV5640 Camera** | 1 | $23.71 |https://www.aliexpress.com/item/1005007469761633.html?spm=a2g0o.detail.0.0.1775oeOwoeOwDY&mp=1&pdp_npi=6%40dis%21PKR%21PKR%206618.06%21PKR%206461.46%21%21PKR%206461.46%21%21%21%40213ba8cc17748604581288280e9169%2112000040885627353%21ct%21PK%21-1%21%211%210%21 | 
| ** Tactile Switch Set (20pcs)** | 1 | $1.20 |https://www.aliexpress.com/item/1005005845072975.html | 
| ** Brass Inserts** | 1 | $2.50 | https://www.aliexpress.com/item/1005008684741327.html | 
| ** 3.7V 400mAh LiPo Battery** | 1 | $0.50 | https://digilog.pk/products/3-7v-300mah-602030-rechargeable-lithium-polymer-battery-lipo-cells | 
| **Total Build Cost:** |  | **~$66.00** |

#
Happy Building :)



