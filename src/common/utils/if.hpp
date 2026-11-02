/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

#ifndef FILE_IF_HPP_SEEN
#define FILE_IF_HPP_SEEN
#include <string>

int get_gateway_and_iface(std::string* gw /*OUT*/, std::string* iface /*OUT*/);
int get_inet_addr_from_iface(
    const std::string& if_name, struct in_addr& inet_addr);
int get_mtu_from_iface(const std::string& if_name, uint32_t& mtu);
int get_inet_addr_infos_from_iface(
    const std::string& if_name, struct in_addr& inet_addr,
    struct in_addr& inet_netmask, unsigned int& mtu);

#endif /* FILE_IF_HPP_SEEN */
