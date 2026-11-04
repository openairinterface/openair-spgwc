################################################################################
# SPDX-License-Identifier: LicenseRef-CSSL-1.0
################################################################################
add_library(GTPV2C STATIC
    3gpp_29.274.cpp
    gtpv2c.cpp
)

include_directories(${SRC_TOP_DIR}/common)
include_directories(${SRC_TOP_DIR}/common/msg)
include_directories(${SRC_TOP_DIR}/common/utils)
include_directories(${SRC_TOP_DIR}/gtpv2c)
include_directories(${SRC_TOP_DIR}/itti)
include_directories(${SRC_TOP_DIR}/oai_spgw_c)
include_directories(${SRC_TOP_DIR}/udp)
include_directories(${SRC_TOP_DIR}/../build/ext/spdlog/include)
