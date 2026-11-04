/*
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */


#ifndef FILE_PGWC_SXAB_HPP_SEEN
#define FILE_PGWC_SXAB_HPP_SEEN
//--related header -------------------------------------------------------------
//--C includes -----------------------------------------------------------------
//--C++ includes ---------------------------------------------------------------
#include <thread>
//--Other includes -------------------------------------------------------------
#include "itti_msg_sxab.hpp"
#include "pfcp.hpp"
#include "pgw_pfcp_association.hpp"

namespace pgwc {

// Values different from 0
#define TASK_PGWC_SX_TRIGGER_HEARTBEAT_REQUEST (11)
#define TASK_PGWC_SX_TIMEOUT_ASSOCIATION_REQUEST (13)

class pgwc_sxab : public pfcp::pfcp_l4_stack {
 private:
  std::thread::id thread_id;
  std::thread thread;

  std::time_t recovery_time_stamp;  // timestamp in seconds

  pfcp::cp_function_features_t cp_function_features;

 public:
  pgwc_sxab();
  pgwc_sxab(pgwc_sxab const&) = delete;
  void operator=(pgwc_sxab const&) = delete;

  void handle_itti_msg(itti_sxab_heartbeat_request& s){};
  void handle_itti_msg(itti_sxab_heartbeat_response& s){};
  void handle_itti_msg(itti_sxab_association_setup_request& s){};
  void handle_itti_msg(itti_sxab_association_setup_response& s){};
  void handle_itti_msg(itti_sxab_association_update_request& s){};
  void handle_itti_msg(itti_sxab_association_update_response& s){};
  void handle_itti_msg(itti_sxab_association_release_request& s){};
  void handle_itti_msg(itti_sxab_association_release_response& s){};
  void handle_itti_msg(itti_sxab_version_not_supported_response& s){};
  void handle_itti_msg(itti_sxab_node_report_response& s){};
  void handle_itti_msg(itti_sxab_session_set_deletion_request& s){};
  void handle_itti_msg(itti_sxab_session_establishment_request& s){};
  void handle_itti_msg(itti_sxab_session_modification_request& s){};
  void handle_itti_msg(itti_sxab_session_deletion_request& s){};
  void handle_itti_msg(itti_sxab_session_report_response& s){};

  void send_sx_msg(itti_sxab_heartbeat_request& s){};
  void send_sx_msg(itti_sxab_heartbeat_response& s){};
  void send_sx_msg(itti_sxab_association_setup_request& s);
  void send_sx_msg(itti_sxab_association_setup_response& s);
  void send_sx_msg(itti_sxab_association_update_request& s){};
  void send_sx_msg(itti_sxab_association_update_response& s){};
  void send_sx_msg(itti_sxab_association_release_request& s){};
  void send_sx_msg(itti_sxab_association_release_response& s){};
  void send_sx_msg(itti_sxab_version_not_supported_response& s){};
  void send_sx_msg(itti_sxab_node_report_request& s){};
  void send_sx_msg(itti_sxab_session_set_deletion_response& s){};
  void send_sx_msg(itti_sxab_session_establishment_request& s);
  void send_sx_msg(itti_sxab_session_modification_request& s);
  void send_sx_msg(itti_sxab_session_deletion_request& s);
  void send_sx_msg(itti_sxab_session_report_response& s);

  void send_heartbeat_request(std::shared_ptr<pfcp_association>& a);
  void send_heartbeat_response(
      const endpoint& r_endpoint, const uint64_t trxn_id);

  void handle_receive_pfcp_msg(pfcp::pfcp_msg& msg, const endpoint& r_endpoint);
  void handle_receive(
      char* recv_buffer, const std::size_t bytes_transferred,
      const endpoint& r_endpoint);

  void handle_receive_heartbeat_request(
      pfcp::pfcp_msg& msg, const endpoint& r_endpoint);
  void handle_receive_heartbeat_response(
      pfcp::pfcp_msg& msg, const endpoint& r_endpoint);
  void handle_receive_association_setup_request(
      pfcp::pfcp_msg& msg, const endpoint& r_endpoint);
  void handle_receive_association_setup_response(
      pfcp::pfcp_msg& msg, const endpoint& r_endpoint);

  void handle_receive_session_establishment_response(
      pfcp::pfcp_msg& msg, const endpoint& r_endpoint);
  void handle_receive_session_modification_response(
      pfcp::pfcp_msg& msg, const endpoint& r_endpoint);
  void handle_receive_session_deletion_response(
      pfcp::pfcp_msg& msg, const endpoint& r_endpoint);
  void handle_receive_session_report_request(
      pfcp::pfcp_msg& msg, const endpoint& r_endpoint);

  void time_out_itti_event(const uint32_t timer_id);

  uint16_t pfcp_registered_port_number() const {
    return udp_s_registered.get_port();
  }

  std::time_t get_recovery_time_stamp() const { return recovery_time_stamp; };

 protected:
  void notify_ul_error(
      const endpoint& remote_endpoint, const uint8_t message_type,
      const uint32_t message_sequence_number, const uint64_t trxn_id,
      const ::cause_value_e cause);
};
}  // namespace pgwc
#endif /* FILE_PGWC_SXAB_HPP_SEEN */
