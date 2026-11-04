/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

#include "fqdn.hpp"
#include "logger.hpp"
#include <boost/asio.hpp>
#include <iostream>

#define ADDR_TYPE_IPV4 0
#define ADDR_TYPE_IPV6 1

bool fqdn::resolve(
    const std::string& host_name, std::string& address, uint32_t& port,
    uint8_t& addr_type, const std::string& protocol) {
  try {
    boost::asio::io_context io_context = {};

    boost::asio::ip::tcp::resolver resolver{io_context};
    boost::asio::ip::tcp::resolver::results_type endpoints =
        resolver.resolve(host_name, protocol);

    addr_type = ADDR_TYPE_IPV4;  // IPv4 by default
    for (auto it = endpoints.cbegin(); it != endpoints.cend(); it++) {
      // get the first Endpoint
      boost::asio::ip::tcp::endpoint endpoint = *it;
      address                                 = endpoint.address().to_string();
      port                                    = endpoint.port();
      Logger::spgwu_app().debug(
          "Resolve a DNS (name %s, protocol %s): Ip Addr %s, port %u",
          host_name.c_str(), protocol.c_str(), address.c_str(), port);
      if (endpoint.address().is_v4())
        addr_type = ADDR_TYPE_IPV4;
      else
        addr_type = ADDR_TYPE_IPV6;
      return true;
    }
  } catch (std::exception& e) {
    throw std::runtime_error(
        "Cannot resolve a DNS name " + std::string(e.what()));
    return false;
  }

  return false;
}
