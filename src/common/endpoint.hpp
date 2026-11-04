/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */


#ifndef FILE_ENDPOINT_HPP_SEEN
#define FILE_ENDPOINT_HPP_SEEN

#include "conversions.hpp"

#include <arpa/inet.h>
#include <inttypes.h>
#include <string.h>
#include <sys/socket.h>

class endpoint {
 public:
  struct sockaddr_storage addr_storage;
  socklen_t addr_storage_len;
  endpoint()
      : addr_storage(), addr_storage_len(sizeof(struct sockaddr_storage)){};
  endpoint(const endpoint& e)
      : addr_storage(e.addr_storage), addr_storage_len(e.addr_storage_len){};
  endpoint(const struct sockaddr_storage& addr, const socklen_t len)
      : addr_storage(addr), addr_storage_len(len){};
  endpoint(const struct in_addr& addr, const uint16_t port) {
    struct sockaddr_in* addr_in = (struct sockaddr_in*) &addr_storage;
    addr_in->sin_family         = AF_INET;
    addr_in->sin_port           = htons(port);
    addr_in->sin_addr.s_addr    = addr.s_addr;

    addr_storage_len = sizeof(struct sockaddr_in);
  };

  endpoint(const struct in6_addr& addr6, const uint16_t port) {
    struct sockaddr_in6* addr_in6 = (struct sockaddr_in6*) &addr_storage;
    addr_in6->sin6_family         = AF_INET6;
    addr_in6->sin6_port           = htons(port);
    addr_in6->sin6_flowinfo       = 0;
    memcpy(&addr_in6->sin6_addr, &addr6, sizeof(struct in6_addr));
    addr_in6->sin6_scope_id = 0;

    addr_storage_len = sizeof(struct sockaddr_in6);
  };

  uint16_t port() const {
    return ntohs(((struct sockaddr_in*) &addr_storage)->sin_port);
  }

  void set_port(uint16_t port) const {
    ((struct sockaddr_in*) &addr_storage)->sin_port = htons(port);
  }

  sa_family_t family() const { return addr_storage.ss_family; }

  bool operator==(const endpoint& e) const {
    if ((addr_storage_len == e.addr_storage_len) &&
        (memcmp(
             (const void*) &addr_storage, (const void*) &e.addr_storage,
             addr_storage_len) == 0)) {
      return true;
    } else {
      return false;
    }
  };

  std::string toString() const {
    std::string str;
    if (addr_storage.ss_family == AF_INET) {
      struct sockaddr_in* addr_in = (struct sockaddr_in*) &addr_storage;
      str.append(conv::toString(addr_in->sin_addr));
      str.append(":").append(std::to_string(ntohs(addr_in->sin_port)));
    } else if (addr_storage.ss_family == AF_INET6) {
      struct sockaddr_in6* addr_in6 = (struct sockaddr_in6*) &addr_storage;
      str.append(conv::toString(addr_in6->sin6_addr));
      str.append(":").append(std::to_string(ntohs(addr_in6->sin6_port)));
    }
    return str;
  }
};

#endif
