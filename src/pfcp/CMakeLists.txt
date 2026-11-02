################################################################################
# SPDX-License-Identifier: LicenseRef-CSSL-1.0
################################################################################
include_directories(${SRC_TOP_DIR}/common)
include_directories(${SRC_TOP_DIR}/itti)
include_directories(${SRC_TOP_DIR}/common/msg)
include_directories(${SRC_TOP_DIR}/common/utils)
include_directories(${SRC_TOP_DIR}/oai_spgwc)
include_directories(${SRC_TOP_DIR}/pfcp)
include_directories(${SRC_TOP_DIR}/udp)
include_directories(${SRC_TOP_DIR}/../build/ext/spdlog/include)

add_library(PFCP STATIC
    3gpp_29.244.cpp
    pfcp.cpp
    )
