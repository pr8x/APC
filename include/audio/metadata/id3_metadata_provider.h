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

class id3_metadata_provider {
 public:
  virtual metadata read_metadata(File& file) {
    char buffer[4096] = {0};

    file.readBytes(buffer, sizeof(buffer));

    ID3v2_Tag* tag = ID3v2_read_tag_from_buffer(buffer, sizeof(buffer));

    if (tag == nullptr) {
      return {};
    }

    metadata meta;

    ID3v2_TextFrame* artistFrame = ID3v2_Tag_get_artist_frame(tag);

    if (artistFrame != nullptr) {
      meta.artist.assign(artistFrame->data->text, artistFrame->data->size);
    }

    ID3v2_TextFrame* titleFrame = ID3v2_Tag_get_title_frame(tag);

    if (titleFrame != nullptr) {
      meta.title.assign(titleFrame->data->text, titleFrame->data->size);
    }

    ID3v2_TextFrame* albumFrame = ID3v2_Tag_get_album_frame(tag);

    if (albumFrame != nullptr) {
      meta.album.assign(albumFrame->data->text, albumFrame->data->size);
    }

    ID3v2_TextFrame* bpmFrame =
        (ID3v2_TextFrame*)ID3v2_Tag_get_frame(tag, "TBPM");

    if (bpmFrame != nullptr) {
      char b[5] = {0};
      memcpy(b, bpmFrame->data->text, 4);
      meta.bpm = atoi(b);
    }

    ID3v2_TextFrame* keyFrame =
        (ID3v2_TextFrame*)ID3v2_Tag_get_frame(tag, "TKEY");

    if (keyFrame != nullptr) {
      meta.key.assign(keyFrame->data->text, keyFrame->data->size);
    }

    ID3v2_Tag_free(tag);

    return meta;
  }
};

}  // namespace audio
}  // namespace apc