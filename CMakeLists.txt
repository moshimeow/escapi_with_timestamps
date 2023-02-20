

add_library(meow_escapi STATIC 
    escapi_dll/capture.cpp
    escapi_dll/capture.h
    escapi_dll/choosedeviceparam.h
    escapi_dll/conversion.cpp
    escapi_dll/escapi_dll.cpp
    escapi_dll/interface.cpp
    escapi_dll/scopedrelease.h
    escapi_dll/videobufferlock.cpp
    escapi_dll/videobufferlock.h
    common/escapi.cpp
    common/escapi.h
)


target_include_directories(
	meow_escapi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/common
	)

#target_link_libraries(meow_escapi PUBLIC escapi_interface)
#target_include_directories(meow_escapi INTERFACE escapi_interface)