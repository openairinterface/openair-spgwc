/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */


#ifndef FILE_ASYNC_SHELL_CMD_HPP_SEEN
#define FILE_ASYNC_SHELL_CMD_HPP_SEEN

#include <string>
#include <thread>
#include "itti_msg.hpp"
#include "thread_sched.hpp"

namespace util {

class async_shell_cmd {
 private:
  std::thread::id thread_id;
  std::thread thread;

 public:
  explicit async_shell_cmd(util::thread_sched_params& sched_params);
  ~async_shell_cmd() {}
  async_shell_cmd(async_shell_cmd const&) = delete;
  void operator=(async_shell_cmd const&) = delete;

  int run_command(
      const task_id_t sender_itti_task, const bool is_abort_on_error,
      const char* src_file, const int src_line, const std::string& cmd_str);
};

}  // namespace util
#endif /* FILE_ASYNC_SHELL_CMD_HPP_SEEN */
