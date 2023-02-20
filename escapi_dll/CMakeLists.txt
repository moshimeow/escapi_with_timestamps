add_library(escapi_dll STATIC 
    capture.cpp
    capture.h
    choosedeviceparam.h
    conversion.cpp
    escapi_dll.cpp
    interface.cpp
    scopedrelease.h
    videobufferlock.cpp
    videobufferlock.h
)
#target_include_directories(
#	escapi_dll INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
#	)

target_link_libraries(escapi_dll PUBLIC escapi_interface)
target_include_directories(escapi_dll INTERFACE escapi_interface)