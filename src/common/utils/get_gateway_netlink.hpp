/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

#ifndef FILE_GET_GATEWAY_NETLINK_HPP_SEEN
#define FILE_GET_GATEWAY_NETLINK_HPP_SEEN

#include <string>

namespace util {
bool get_iface_l2_addr(const std::string& iface, std::string& mac);
bool get_gateway_and_iface(std::string& gw, std::string& iface);
}  // namespace util
#endif /* FILE_GET_GATEWAY_NETLINK_HPP_SEEN */
