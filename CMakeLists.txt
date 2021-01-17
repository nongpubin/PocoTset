
cmake_minimum_required(VERSION 2.8.1)

project (server)

set(CMAKE_CXX_FLAGS "-std=c++14  ${CMAKE_CXX_FLAGS}")

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/ SRC_LIST)
#include_directories(${CMAKE_CURRENT_LIST_DIR}/libevent/include)
#include_directories(${CMAKE_CURRENT_LIST_DIR} )
include_directories(${CMAKE_CURRENT_LIST_DIR}/PocoHead/)
include_directories(${CMAKE_CURRENT_LIST_DIR}/PocoHead/Net/)
include_directories(${CMAKE_CURRENT_LIST_DIR}/PocoHead/Poco/)

message ("CMAKE_CURRENT_LIST_DIR =  ${CMAKE_CURRENT_LIST_DIR}")

link_directories(${CMAKE_CURRENT_LIST_DIR}/lib/lib/)

message(" CMAKE_CURRENT_LIST_DIR =  ${CMAKE_CURRENT_LIST_DIR} ")
add_executable (hello_bin ${SRC_LIST})

target_link_libraries(hello_bin PocoFoundation.a)

# 添加链接库
# target_link_libraries(hello_bin)
 

# LINK_DIRECTORIES(${PRODUCT_DIR}/libmosquitto/mosquitto/lib)
# LINK_DIRECTORIES(${TOP_CMAKE_DIR}/third_party/libpoco/lib/${BUILD_SYS_PATH}/)

# INCLUDE_DIRECTORIES(${PRODUCT_DIR})
# ADD_EXECUTABLE(${NP_BUILD_NAME}  ${SRC_LIST})

# TARGET_LINK_LIBRARIES(${NP_BUILD_NAME} -Wl,--start-group pthread mosquitto libPocoFoundation.a libPocoNet.a  libPocoUtil.a libPocoNetSSL.a
#                             libPocoFoundation.a  libPocoCrypto.a  libPocoEncodings.a -lssl libPocoJSON.a crypto -Wl,--end-group)