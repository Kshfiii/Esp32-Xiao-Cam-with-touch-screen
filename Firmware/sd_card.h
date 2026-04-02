#pragma once
#include <SD.h>
#include <FS.h>
#include "config.h"

static int _next_index = 0;

bool sd_init() {
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD init failed. Is card inserted? Was J3 cut?");
    return false;
  }
  if (!SD.exists("/photos")) SD.mkdir("/photos");

  while (SD.exists("/photos/img_" + String(_next_index) + ".jpg")) {
    _next_index++;
  }
  Serial.printf("SD ready. Next photo: img_%d.jpg\n", _next_index);
  return true;
}

bool sd_save_photo(uint8_t *buf, size_t len) {
  String path = "/photos/img_" + String(_next_index) + ".jpg";
  File f = SD.open(path, FILE_WRITE);
  if (!f) return false;
  f.write(buf, len);
  f.close();
  Serial.printf("Saved %s (%d bytes)\n", path.c_str(), len);
  _next_index++;
  return true;
}

std::vector<String> sd_list_photos() {
  std::vector<String> list;
  File dir = SD.open("/photos");
  if (!dir) return list;
  File entry;
  while ((entry = dir.openNextFile())) {
    String name = String(entry.name());
    if (name.endsWith(".jpg") || name.endsWith(".JPG")) {
      list.push_back("/photos/" + name);
    }
    entry.close();
  }
  dir.close();
  return list;
}
