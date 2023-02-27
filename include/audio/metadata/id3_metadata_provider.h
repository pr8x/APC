#pragma once
#include <FS.h>
#include <id3v2lib.h>

#include <algorithm>
#include <array>
#include <iterator>
#include <string>

namespace apc {
namespace audio {

struct metadata {
  std::string artist;
  std::string title;
  std::string album;
  float bpm = -1;
  std::string key;
};

template <class T>
decltype(auto) trace(T&& ret, const char* callExpr) {
  Serial.println(callExpr);
  return ret();
}

#define APC_TRACE(f) trace([&]() { return f; }, #f)

class id3_metadata_provider {
 public:
  virtual metadata read_metadata(File& file) {
    char buffer[1024] = {0};

    size_t bytesRead = APC_TRACE(file.readBytes(buffer, sizeof(buffer)));
    Serial.printf("Read %d bytes\n", bytesRead);

    ID3v2_Tag* tag = APC_TRACE(ID3v2_read_tag_from_buffer(buffer, bytesRead));

    if (tag == nullptr) {
      Serial.println("No ID3 tag found");
      return {};
    }

    metadata meta;

    // ID3v2_TextFrame* artistFrame = APC_TRACE(ID3v2_Tag_get_artist_frame(tag));

    // if (artistFrame != nullptr) {
    //   Serial.println("Artist frame found");
    //   meta.artist.assign(artistFrame->data->text, artistFrame->data->size);
    // }

    // ID3v2_TextFrame* titleFrame = APC_TRACE(ID3v2_Tag_get_title_frame(tag));

    // if (titleFrame != nullptr) {
    //   Serial.println("Title frame found");
    //   meta.title.assign(titleFrame->data->text, titleFrame->data->size);
    // }

    // ID3v2_TextFrame* albumFrame = APC_TRACE(ID3v2_Tag_get_album_frame(tag));

    // if (albumFrame != nullptr) {
    //   Serial.println("Album frame found");
    //   meta.album.assign(albumFrame->data->text, albumFrame->data->size);
    // }

    // ID3v2_TextFrame* bpmFrame =
    //     APC_TRACE((ID3v2_TextFrame*)ID3v2_Tag_get_frame(tag, "TBPM"));

    // if (bpmFrame != nullptr) {
    //   Serial.println("BPM frame found");
    //   char b[5] = {0};
    //   memcpy(b, bpmFrame->data->text, 4);
    //   meta.bpm = atoi(b);
    // }

    // ID3v2_TextFrame* keyFrame =
    //     APC_TRACE((ID3v2_TextFrame*)ID3v2_Tag_get_frame(tag, "TKEY"));

    // if (keyFrame != nullptr) {
    //   Serial.println("Key frame found");
    //   meta.key.assign(keyFrame->data->text, keyFrame->data->size);
    // }

    ID3v2_Tag_free(tag);

    return meta;
  }
};

}  // namespace audio
}  // namespace apc