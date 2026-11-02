/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */


#ifndef FILE_SGWC_S11_HPP_SEEN
#define FILE_SGWC_S11_HPP_SEEN

#include "gtpv2c.hpp"
#include "itti_msg_s11.hpp"

#include <thread>

namespace sgwc {

class sgw_s11 : public gtpv2c::gtpv2c_stack {
 private:
  std::thread::id thread_id;
  std::thread thread;

  void handle_receive_gtpv2c_msg(
      gtpv2c::gtpv2c_msg& msg, const endpoint& remote_endpoint);
  void handle_receive_echo_request(
      gtpv2c::gtpv2c_msg& msg, const endpoint& remote_endpoint);
  void handle_receive_echo_response(
      gtpv2c::gtpv2c_msg& msg, const endpoint& remote_endpoint);
  void handle_receive_create_session_request(
      gtpv2c::gtpv2c_msg& msg, const endpoint& remote_endpoint);
  void handle_receive_delete_session_request(
      gtpv2c::gtpv2c_msg& msg, const endpoint& remote_endpoint);
  void handle_receive_modify_bearer_request(
      gtpv2c::gtpv2c_msg& msg, const endpoint& remote_endpoint);
  void handle_receive_release_access_bearers_request(
      gtpv2c::gtpv2c_msg& msg, const endpoint& remote_endpoint);
  void handle_receive_downlink_data_notification_acknowledge(
      gtpv2c::gtpv2c_msg& msg, const endpoint& remote_endpoint);

 public:
  sgw_s11();
  sgw_s11(sgw_s11 const&) = delete;
  void operator=(sgw_s11 const&) = delete;

  void handle_receive(
      char* recv_buffer, const std::size_t bytes_transferred,
      const endpoint& remote_endpoint);
  void notify_ul_error(
      const endpoint& r_endpoint, const teid_t l_teid,
      const cause_value_e cause, const uint64_t gtpc_tx_id);

  void send_msg(itti_s11_create_session_response& m);
  void send_msg(itti_s11_delete_session_response& m);
  void send_msg(itti_s11_modify_bearer_response& m);
  void send_msg(itti_s11_release_access_bearers_response& m);
  void send_msg(itti_s11_downlink_data_notification& m);

  void send_echo_response(const endpoint& r_endpoint, const uint64_t trxn_id);

  void time_out_itti_event(const uint32_t timer_id);
};
}  // namespace sgwc
#endif /* FILE_SGWC_S11_HPP_SEEN */
