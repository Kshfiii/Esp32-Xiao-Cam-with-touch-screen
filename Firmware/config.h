#pragma once

// ============================================================
//  config.h — all pins and settings in one place
// ============================================================

// Shutter button (right side of case)
#define PIN_SHUTTER        D0

// SD card chip select (Round Display's SD slot — after J3 cut)
#define SD_CS_PIN          D2

// Display resolution
#define SCREEN_W           240
#define SCREEN_H           240

// Camera pins (XIAO ESP32-S3 Sense — fixed, do not change)
#define CAM_PIN_PWDN       -1
#define CAM_PIN_RESET      -1
#define CAM_PIN_XCLK       10
#define CAM_PIN_SIOD       40
#define CAM_PIN_SIOC       39
#define CAM_PIN_Y9         48
#define CAM_PIN_Y8         11
#define CAM_PIN_Y7         12
#define CAM_PIN_Y6         14
#define CAM_PIN_Y5         16
#define CAM_PIN_Y4         18
#define CAM_PIN_Y3         17
#define CAM_PIN_Y2         15
#define CAM_PIN_VSYNC      38
#define CAM_PIN_HREF       47
#define CAM_PIN_PCLK       13

// Photo JPEG quality (1=best/biggest, 63=worst/smallest)
#define PHOTO_QUALITY      10

// Minimum swipe distance (px) to change photo in gallery
#define SWIPE_THRESHOLD    40
