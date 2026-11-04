/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */


#ifndef FILE_COMMON_DEFS_SEEN
#define FILE_COMMON_DEFS_SEEN

#include <arpa/inet.h>

#define RETURNclear (int) 2
#define RETURNerror (int) 1
#define RETURNok (int) 0

//------------------------------------------------------------------------------
#define IPV4_STR_ADDR_TO_INADDR(AdDr_StR, InAdDr, MeSsAgE)                     \
  do {                                                                         \
    if (inet_aton(AdDr_StR, &InAdDr) <= 0) {                                   \
      throw(MeSsAgE);                                                          \
    }                                                                          \
  } while (0)

// for PFCP
constexpr uint64_t SECONDS_SINCE_FIRST_EPOCH = 2208988800;

#define NIPADDR(addr)                                                          \
  (uint8_t)(addr & 0x000000FF), (uint8_t)((addr & 0x0000FF00) >> 8),           \
      (uint8_t)((addr & 0x00FF0000) >> 16),                                    \
      (uint8_t)((addr & 0xFF000000) >> 24)

#ifndef UNUSED
#define UNUSED(x) (void) (x)
#endif

#endif /* FILE_COMMON_DEFS_SEEN */
