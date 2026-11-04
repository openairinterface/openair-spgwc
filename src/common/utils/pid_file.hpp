/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

#ifndef FILE_PID_FILE_SEEN
#define FILE_PID_FILE_SEEN
#include <string>

namespace util {

/*
 * Generate the exe absolute path using a specified base_path.
 *
 * @param base_path
 *        the root directory to use.
 *
 * @return a string for the exe absolute path.
 */
std::string get_exe_absolute_path(
    const std::string& base_path, const unsigned int instance);

bool is_pid_file_lock_success(const char* pid_file_name);

void pid_file_unlock(void);

int lockfile(int fd, int lock_type);

}  // namespace util
#endif
