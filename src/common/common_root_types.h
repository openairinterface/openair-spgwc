/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

/*! \file common_root_types.h
  \brief
  \company Eurecom
  \email: lionel.gauthier@eurecom.fr
*/

#ifndef FILE_COMMON_ROOT_TYPES_SEEN
#define FILE_COMMON_ROOT_TYPES_SEEN

#include <arpa/inet.h>
#include <inttypes.h>
#include <stdint.h>

//------------------------------------------------------------------------------
#define PRIORITY_LEVEL_MAX (15)
#define PRIORITY_LEVEL_MIN (1)
#define BEARERS_PER_UE (11)
#define IMEI_DIGITS_MAX (15)
#define IMEISV_DIGITS_MAX (16)
#define MAX_APN_PER_UE (5)

#define PROC_ID_FMT "0x%" PRIx64

// TEIDs
typedef uint32_t teid_t;
#define TEID_FMT "0x%" PRIx32
#define TEID_SCAN_FMT SCNx32
#define INVALID_TEID ((teid_t) 0x00000000)
#define UNASSIGNED_TEID ((teid_t) 0x00000000)

// SEIDs
typedef uint64_t seid_t;
#define SEID_FMT "0x%" PRIx64
#define SEID_SCAN_FMT SCNx64
#define INVALID_SEID ((seid_t) 0x00000000)
#define UNASSIGNED_SEID ((seid_t) 0x00000000)

//------------------------------------------------------------------------------
// IMSI
typedef uint64_t imsi64_t;
#define IMSI_64_FMT "%" SCNu64
#define INVALID_IMSI64 (imsi64_t) 0

//------------------------------------------------------------------------------
typedef uint64_t bitrate_t;
#define PRIORITY_LEVEL_FMT "0x%" PRIu8
#define QCI_FMT "0x%" PRIu8
#define QCI_SCAN_FMT SCNu8

#define PRE_EMPTION_CAPABILITY_FMT "0x%" PRIu8
#define PRE_EMPTION_VULNERABILITY_FMT "0x%" PRIu8

#endif /* FILE_COMMON_ROOT_TYPES_SEEN */
