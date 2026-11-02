/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */


#ifndef FILE_ITTI_ASYNC_SHELL_CMD_SEEN
#define FILE_ITTI_ASYNC_SHELL_CMD_SEEN

#include "itti_msg.hpp"

class itti_async_shell_cmd : public itti_msg {
 public:
  itti_async_shell_cmd(
      const task_id_t origin, const task_id_t destination,
      const std::string& system_cmd, bool is_abort_on_error,
      const char* src_file, const int src_line)
      : itti_msg(ASYNC_SHELL_CMD, origin, destination),
        system_command(system_cmd),
        is_abort_on_error(is_abort_on_error),
        src_file(src_file),
        src_line(src_line) {}
  itti_async_shell_cmd(const itti_async_shell_cmd& i)
      : itti_msg(i),
        system_command(i.system_command),
        is_abort_on_error(i.is_abort_on_error),
        src_file(i.src_file),
        src_line(i.src_line) {}
  const char* get_msg_name() { return typeid(itti_msg_ping).name(); };
  std::string system_command;
  bool is_abort_on_error;
  // debug
  std::string src_file;
  int src_line;
};

#endif /* FILE_ITTI_ASYNC_SHELL_CMD_SEEN */
