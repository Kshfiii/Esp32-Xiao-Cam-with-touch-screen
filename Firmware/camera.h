#pragma once
#include "esp_camera.h"
#include "config.h"

// ============================================================
//  camera.h — init and grab frames
// ============================================================

bool camera_init() {
  camera_config_t cfg = {};
  cfg.ledc_channel  = LEDC_CHANNEL_0;
  cfg.ledc_timer    = LEDC_TIMER_0;
  cfg.pin_d0        = CAM_PIN_Y2;
  cfg.pin_d1        = CAM_PIN_Y3;
  cfg.pin_d2        = CAM_PIN_Y4;
  cfg.pin_d3        = CAM_PIN_Y5;
  cfg.pin_d4        = CAM_PIN_Y6;
  cfg.pin_d5        = CAM_PIN_Y7;
  cfg.pin_d6        = CAM_PIN_Y8;
  cfg.pin_d7        = CAM_PIN_Y9;
  cfg.pin_xclk      = CAM_PIN_XCLK;
  cfg.pin_pclk      = CAM_PIN_PCLK;
  cfg.pin_vsync     = CAM_PIN_VSYNC;
  cfg.pin_href      = CAM_PIN_HREF;
  cfg.pin_sscb_sda  = CAM_PIN_SIOD;
  cfg.pin_sscb_scl  = CAM_PIN_SIOC;
  cfg.pin_pwdn      = CAM_PIN_PWDN;
  cfg.pin_reset     = CAM_PIN_RESET;
  cfg.xclk_freq_hz  = 20000000;
  cfg.pixel_format  = PIXFORMAT_JPEG;
  cfg.frame_size    = FRAMESIZE_240X240;
  cfg.jpeg_quality  = 12;           // Slightly looser for smooth viewfinder
  cfg.fb_count      = 2;            // Double buffer = no tearing
  cfg.grab_mode     = CAMERA_GRAB_LATEST;
  cfg.fb_location   = CAMERA_FB_IN_PSRAM;

  if (esp_camera_init(&cfg) != ESP_OK) {
    Serial.println("Camera init failed.");
    return false;
  }

  // Auto everything — sensible defaults for a point-and-shoot
  sensor_t *s = esp_camera_sensor_get();
  s->set_whitebal(s, 1);
  s->set_awb_gain(s, 1);
  s->set_exposure_ctrl(s, 1);
  s->set_aec2(s, 1);
  s->set_gain_ctrl(s, 1);

  return true;
}

// Grab one frame — MUST call esp_camera_fb_return(fb) when done
camera_fb_t* camera_grab() {
  return esp_camera_fb_get();
}

// Temporarily raise quality before saving a photo, then restore
void camera_quality_high() {
  esp_camera_sensor_get()->set_quality(esp_camera_sensor_get(), PHOTO_QUALITY);
}

void camera_quality_normal() {
  esp_camera_sensor_get()->set_quality(esp_camera_sensor_get(), 12);
}
