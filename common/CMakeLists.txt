add_library(escapi_interface STATIC escapi.cpp escapi.h)
target_include_directories(
	escapi_interface INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	)
