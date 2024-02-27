# Set executable
set(EXECUTABLE_NAME movieplayer)

# Add the executable and link it to the libraries
add_executable(${EXECUTABLE_NAME} main.cc)
target_link_libraries(${EXECUTABLE_NAME} ${LIBRARY_NAME} ${FFMPEG_LIB})