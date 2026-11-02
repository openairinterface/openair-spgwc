/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

#ifndef FILE_PGW_PCO_HPP_SEEN
#define FILE_PGW_PCO_HPP_SEEN

#include <stdint.h>

/**
 * protocol_configuration_options_ids_t
 *
 * Container for caching which protocol/container identifiers have been set in
 * the message sent by the UE.
 *
 * ID specifications based on 3GPP #24.008.
 */
typedef struct protocol_configuration_options_ids_s {
  // Protocol identifiers (from configuration protocol options list)
  uint8_t pi_ipcp : 1;

  // Container identifiers (from additional parameters list)
  uint8_t ci_dns_server_ipv4_address_request : 1;
  uint8_t ci_ip_address_allocation_via_nas_signalling : 1;
  uint8_t ci_ipv4_address_allocation_via_dhcpv4 : 1;
  uint8_t ci_ipv4_link_mtu_request : 1;
} protocol_configuration_options_ids_t;

#endif
