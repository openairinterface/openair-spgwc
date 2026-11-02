/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

/*! \file thread_sched.hpp
  \brief
  \company Eurecom
  \email: lionel.gauthier@eurecom.fr
*/

#ifndef FILE_THREAD_SCHED_HPP_SEEN
#define FILE_THREAD_SCHED_HPP_SEEN

#include <sched.h>
#include "logger.hpp"

namespace util {

class thread_sched_params {
 public:
  thread_sched_params()
      : cpu_id(0), sched_policy(SCHED_FIFO), sched_priority(84) {}
  int cpu_id;
  int sched_policy;
  int sched_priority;
  void apply(const int task_id, _Logger& logger) const;
};

}  // namespace util
#endif /* FILE_THREAD_SCHED_HPP_SEEN */
