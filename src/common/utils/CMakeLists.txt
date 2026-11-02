################################################################################
# SPDX-License-Identifier: LicenseRef-CSSL-1.0
################################################################################
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${SRC_TOP_DIR}/common)
include_directories(${SRC_TOP_DIR}/common/msg)
include_directories(${SRC_TOP_DIR}/common/utils)
include_directories(${SRC_TOP_DIR}/itti)
include_directories(${SRC_TOP_DIR}/../build/ext/spdlog/include)


set(CN_UTILS_SRC STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/3gpp_conversions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/async_shell_cmd.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/conversions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/epc.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/get_gateway_netlink.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/if.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pid_file.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/string.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/thread_sched.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fqdn.cpp
    )


add_library(CN_UTILS ${CN_UTILS_SRC})


