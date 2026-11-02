/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

/*! \file thread_sched.cpp
  \brief
  \company Eurecom
  \email: lionel.gauthier@eurecom.fr
*/

#include "thread_sched.hpp"

//------------------------------------------------------------------------------
void util::thread_sched_params::apply(
    const int task_id, _Logger& logger) const {
  if (cpu_id >= 0) {
    cpu_set_t cpuset;
    CPU_SET(cpu_id, &cpuset);
    if (int rc = pthread_setaffinity_np(
            pthread_self(), sizeof(cpu_set_t), &cpuset)) {
      logger.warn(
          "Could not set affinity to ITTI task %d, err=%d", task_id, rc);
    }
  }

  struct sched_param sparam;
  memset(&sparam, 0, sizeof(sparam));
  sparam.sched_priority = sched_priority;
  if (int rc = pthread_setschedparam(pthread_self(), sched_policy, &sparam)) {
    logger.warn(
        "Could not set schedparam to ITTI task %d, err=%d", task_id, rc);
  }
}
