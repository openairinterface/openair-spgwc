/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

/*
 *  itti_msg_sx_restore.hpp
 *
 *  Created on: March 27, 2019
 *  Author: lionel.gauthier@eurecom.fr
 */

#ifndef ITTI_MSG_SX_RESTORE_HPP_INCLUDED_
#define ITTI_MSG_SX_RESTORE_HPP_INCLUDED_

#include <set>
#include "3gpp_29.244.h"
#include "itti_msg.hpp"

class itti_sx_restore : public itti_msg {
 public:
  itti_sx_restore(const task_id_t origin, const task_id_t destination)
      : itti_msg(RESTORE_SX_SESSIONS, origin, destination), sessions() {}
  itti_sx_restore(const itti_sx_restore& i)
      : itti_msg(i), sessions(i.sessions) {}
  itti_sx_restore(
      const itti_sx_restore& i, const task_id_t orig, const task_id_t dest)
      : itti_sx_restore(i) {
    origin      = orig;
    destination = dest;
  }
  const char* get_msg_name() { return "SX_RESTORE"; };

  std::set<pfcp::fseid_t> sessions;
};

#endif /* ITTI_MSG_SX_RESTORE_HPP_INCLUDED_ */
