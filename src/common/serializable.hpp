/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */


#ifndef FILE_SERIALIZABLE_HPP_SEEN
#define FILE_SERIALIZABLE_HPP_SEEN

#include <iostream>
#include <string>

class stream_serializable {
 public:
  virtual void dump_to(std::ostream& os)   = 0;
  virtual void load_from(std::istream& is) = 0;
  // virtual ~serializable() = 0;
};

#endif /* FILE_SERIALIZABLE_HPP_SEEN */
