/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

#include "itti_msg.hpp"
#include "itti.hpp"

extern itti_mw* itti_inst;

itti_msg::itti_msg()
    : msg_type(ITTI_MSG_TYPE_NONE), origin(TASK_NONE), destination(TASK_NONE) {
  msg_num = itti_inst->increment_message_number();
};

itti_msg::itti_msg(
    const itti_msg_type_t msg_type, task_id_t origin, task_id_t destination)
    : msg_type(msg_type), origin(origin), destination(destination) {
  msg_num = itti_inst->increment_message_number();
};

itti_msg::itti_msg(const itti_msg& i)
    : msg_type(i.msg_type),
      msg_num(i.msg_num),
      origin(i.origin),
      destination(i.destination){};

const char* itti_msg::get_msg_name() {
  return "UNINITIALIZED";
}
