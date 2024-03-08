# Set executable
set(EXECUTABLE_NAME movieplayer)

# Add the executable and link it to the libraries
add_executable(${EXECUTABLE_NAME} main.cc)
target_link_libraries(${EXECUTABLE_NAME} ${MEDIAPLAYER_LIB} ${FFMPEG_LIB})