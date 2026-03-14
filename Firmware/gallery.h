#pragma once
#include <TFT_eSPI.h>
#include <TJpg_Decoder.h>
#include <SD.h>
#include "sd_card.h"
#include "config.h"

// ============================================================
//  gallery.h — swipe left/right to browse saved photos
//              swipe down to return to viewfinder
// ============================================================

extern TFT_eSPI tft;

static std::vector<String> _photos;
static int _current = 0;

void gallery_load() {
  _photos = sd_list_photos();
  // Start at the most recent photo
  _current = _photos.empty() ? 0 : (int)_photos.size() - 1;
}

void gallery_draw() {
  tft.fillScreen(TFT_BLACK);

  if (_photos.empty()) {
    tft.setTextColor(TFT_DARKGREY, TFT_BLACK);
    tft.setTextSize(1);
    tft.setCursor(70, 108);
    tft.print("No photos yet.");
    tft.setCursor(62, 124);
    tft.print("Press shutter!");
    return;
  }

  // Load JPEG from SD and draw it
  File f = SD.open(_photos[_current]);
  if (f) {
    size_t sz = f.size();
    uint8_t *buf = (uint8_t*)ps_malloc(sz);
    if (buf) {
      f.read(buf, sz);
      f.close();
      TJpgDec.drawJpg(0, 0, buf, sz);
      free(buf);
    } else {
      f.close();
    }
  }

  // "2 / 7" counter at the bottom
  String counter = String(_current + 1) + " / " + String(_photos.size());
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);
  int16_t tw = tft.textWidth(counter);
  tft.fillRect((SCREEN_W - tw) / 2 - 4, 220, tw + 8, 14, TFT_BLACK);
  tft.setCursor((SCREEN_W - tw) / 2, 222);
  tft.print(counter);

  // Swipe hint
  tft.setTextColor(TFT_DARKGREY, TFT_BLACK);
  tft.setCursor(52, 8);
  tft.print("swipe down: back");
}

void gallery_go_next() {
  if (_photos.empty()) return;
  _current = (_current + 1) % _photos.size();
  gallery_draw();
}

void gallery_go_prev() {
  if (_photos.empty()) return;
  _current = (_current - 1 + _photos.size()) % _photos.size();
  gallery_draw();
}
