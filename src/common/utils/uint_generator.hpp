/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */


#ifndef FILE_UINT_GENERATOR_HPP_SEEN
#define FILE_UINT_GENERATOR_HPP_SEEN

#include <mutex>
#include <set>

namespace util {

template<class UINT>
class uint_generator {
 private:
  UINT uid_generator;
  std::mutex m_uid_generator;

  std::set<UINT> uid_generated;
  std::mutex m_uid_generated;

 public:
  uint_generator() : m_uid_generator(), m_uid_generated() {
    uid_generator = 0;
    uid_generated = {};
  };

  uint_generator(uint_generator const&) = delete;
  void operator=(uint_generator const&) = delete;

  UINT get_uid() {
    std::unique_lock<std::mutex> lr(m_uid_generator);
    UINT uid = ++uid_generator;
    while (true) {
      // may happen race conditions here
      std::unique_lock<std::mutex> ld(m_uid_generated);
      if (uid_generated.count(uid) == 0) {
        uid_generated.insert(uid);
        ld.unlock();
        lr.unlock();
        return uid;
      }
      uid = ++uid_generator;
    }
  }

  void free_uid(UINT uid) {
    std::unique_lock<std::mutex> l(m_uid_generated);
    uid_generated.erase(uid);
    l.unlock();
  }
};

template<class UINT>
class uint_uid_generator {
 private:
  UINT uid_generator;
  std::mutex m_uid_generator;

  std::set<UINT> uid_generated;
  std::mutex m_uid_generated;

  uint_uid_generator() : m_uid_generator(), m_uid_generated() {
    uid_generator = 0;
    uid_generated = {};
  };

 public:
  static uint_uid_generator& get_instance() {
    static uint_uid_generator instance;
    return instance;
  }

  uint_uid_generator(uint_uid_generator const&) = delete;
  void operator=(uint_uid_generator const&) = delete;

  UINT get_uid() {
    std::unique_lock<std::mutex> lr(m_uid_generator);
    UINT uid = ++uid_generator;
    while (true) {
      // may happen race conditions here
      std::unique_lock<std::mutex> ld(m_uid_generated);
      if (uid_generated.count(uid) == 0) {
        uid_generated.insert(uid);
        lr.unlock();
        ld.unlock();
        return uid;
      }
      uid = ++uid_generator;
    }
  }

  void free_uid(UINT uid) {
    std::unique_lock<std::mutex> l(m_uid_generated);
    uid_generated.erase(uid);
    l.unlock();
  }
};

}  // namespace util
#endif  // FILE_UINT_GENERATOR_HPP_SEEN
