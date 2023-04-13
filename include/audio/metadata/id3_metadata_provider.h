#pragma once
#include <audio/metadata/metadata.h>
#include <FS.h>
#include <debug.h>
#include <id3v2lib.h>

#include <codecvt>
#include <locale>
#include <optional>

namespace apc {
namespace audio {

class id3_metadata_provider {
 public:
  virtual std::optional<metadata> read_metadata(File& file) {
    char buffer[1024] = {0};

    size_t bytesRead = APC_TRACE(file.readBytes(buffer, sizeof(buffer)));
    Serial.printf("Read %d bytes\n", bytesRead);

    ID3v2_Tag* tag = APC_TRACE(ID3v2_read_tag_from_buffer(buffer, bytesRead));

    if (tag == nullptr) {
      Serial.println("No ID3 tag found");
      return {};
    }

    metadata meta;

    ID3v2_TextFrame* artistFrame = APC_TRACE(ID3v2_Tag_get_artist_frame(tag));

    if (artistFrame != nullptr) {
      meta.artist.assign(artistFrame->data->text, artistFrame->data->size - 4);
    }

    ID3v2_TextFrame* titleFrame = APC_TRACE(ID3v2_Tag_get_title_frame(tag));

    if (titleFrame != nullptr) {
      meta.title.assign(titleFrame->data->text, titleFrame->data->size - 4);
    }

    ID3v2_TextFrame* albumFrame = APC_TRACE(ID3v2_Tag_get_album_frame(tag));

    if (albumFrame != nullptr) {
      meta.album.assign(albumFrame->data->text, albumFrame->data->size - 4);
    }

    ID3v2_TextFrame* bpmFrame =
        APC_TRACE((ID3v2_TextFrame*)ID3v2_Tag_get_frame(tag, "TBPM"));

    if (bpmFrame != nullptr) {
      char b[5] = {0};
      memcpy(b, bpmFrame->data->text, 4);
      meta.bpm = atoi(b);
    }

    ID3v2_TextFrame* keyFrame =
        APC_TRACE((ID3v2_TextFrame*)ID3v2_Tag_get_frame(tag, "TKEY"));

    if (keyFrame != nullptr) {
      meta.key.assign(keyFrame->data->text, keyFrame->data->size - 4);
    }

    ID3v2_Tag_free(tag);

    return meta;
  }

};

}  // namespace audio
}  // namespace apc