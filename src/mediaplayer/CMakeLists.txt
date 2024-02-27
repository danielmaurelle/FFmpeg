# Set library
set(LIBRARY_NAME Library)

# Add sources and header files to the library
add_library(${LIBRARY_NAME} STATIC mediaplayer.cc)
target_include_directories(${LIBRARY_NAME} PUBLIC "./")
