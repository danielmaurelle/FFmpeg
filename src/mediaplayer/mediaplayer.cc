#include "mediaplayer.h"
#include <iostream>
#include <string>
#include <filesystem>

extern "C" {
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <SDL2/SDL.h>
}

namespace fs = std::filesystem;

void MediaPlayer::playVideo() {
    std::string currentFilePath = __FILE__;
    std::string currentDirectory = fs::path(currentFilePath).parent_path();
    std::string videoFilePath = currentDirectory + "/video.mp4";

    av_register_all();
    avcodec_register_all();
    avformat_network_init();

    AVFormatContext* formatContext = avformat_alloc_context();
    if (avformat_open_input(&formatContext, videoFilePath.c_str(), nullptr, nullptr) != 0) {
        std::cerr << "Error: Couldn't open file" << std::endl;
        return;
    }

    avformat_find_stream_info(formatContext, nullptr);

    int videoStreamIndex = -1;
    for (unsigned int i = 0; i < formatContext->nb_streams; i++) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStreamIndex = i;
            break;
        }
    }

    if (videoStreamIndex == -1) {
        std::cerr << "Error: Couldn't find video stream" << std::endl;
        avformat_close_input(&formatContext);
        return;
    }

    // Decode and render frames (the code you provided earlier)

    avformat_close_input(&formatContext);

}
