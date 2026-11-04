/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */


#ifndef FILE_CONVERSIONS_HPP_SEEN
#define FILE_CONVERSIONS_HPP_SEEN
#include <netinet/in.h>
#include <stdint.h>
#include <string>

/* Used to format an uint32_t containing an ipv4 address */
#define IN_ADDR_FMT "%u.%u.%u.%u"
#define PRI_IN_ADDR(aDDRESS)                                                   \
  (uint8_t)((aDDRESS.s_addr) & 0x000000ff),                                    \
      (uint8_t)(((aDDRESS.s_addr) & 0x0000ff00) >> 8),                         \
      (uint8_t)(((aDDRESS.s_addr) & 0x00ff0000) >> 16),                        \
      (uint8_t)(((aDDRESS.s_addr) & 0xff000000) >> 24)

#define IPV4_ADDR_DISPLAY_8(aDDRESS)                                           \
  (aDDRESS)[0], (aDDRESS)[1], (aDDRESS)[2], (aDDRESS)[3]

class conv {
 public:
  static void hexa_to_ascii(uint8_t* from, char* to, size_t length);
  static int ascii_to_hex(uint8_t* dst, const char* h);
  static struct in_addr fromString(const std::string addr4);
  static std::string toString(const struct in_addr& inaddr);
  static std::string toString(const struct in6_addr& in6addr);
  static std::string mccToString(
      const uint8_t digit1, const uint8_t digit2, const uint8_t digit3);
  static std::string mncToString(
      const uint8_t digit1, const uint8_t digit2, const uint8_t digit3);
};
#endif /* FILE_CONVERSIONS_HPP_SEEN */
