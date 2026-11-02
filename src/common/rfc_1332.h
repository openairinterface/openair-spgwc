/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

#ifndef FILE_RFC_1332_SEEN
#define FILE_RFC_1332_SEEN

// 2 A PPP Network Control Protocol (NCP) for IP

// Data Link Layer Protocol Field
// Exactly one IPCP packet is encapsulated in the Information field
// of PPP Data Link Layer frames where the Protocol field indicates
// type hex 8021 (IP Control Protocol)

// Code field
// Only Codes 1 through 7 (Configure-Request, Configure-Ack,
// Configure-Nak, Configure-Reject, Terminate-Request, Terminate-Ack
// and Code-Reject) are used. Other Codes should be treated as
// unrecognized and should result in Code-Rejects.
#define IPCP_CODE_CONFIGURE_REQUEST (0x01)
#define IPCP_CODE_CONFIGURE_ACK (0x02)
#define IPCP_CODE_CONFIGURE_NACK (0x03)
#define IPCP_CODE_CONFIGURE_REJECT (0x04)
#define IPCP_CODE_TERMINATE_REQUEST (0x05)
#define IPCP_CODE_TERMINATE_ACK (0x06)
#define IPCP_CODE_REJECT (0x07)

#endif
