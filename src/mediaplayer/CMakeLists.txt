# Set library
set(MEDIAPLAYER_LIB Library)

# Add sources and header files to the library
add_library(${MEDIAPLAYER_LIB} STATIC mediaplayer.cc)
target_include_directories(${MEDIAPLAYER_LIB} PUBLIC "./")
