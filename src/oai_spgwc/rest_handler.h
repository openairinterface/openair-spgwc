/*
 * Copyright (c) 2017 Sprint
 *
 * SPDX-License-Identifier: LicenseRef-CSSL-1.0
 */

#ifndef REST_HANDLER_H_
#define REST_HANDLER_H_

#include <iostream>
#include <pistache/endpoint.h>
#include <pistache/router.h>

#include <memory>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

extern RAPIDJSON_NAMESPACE::Document docSchema;

class RestHandler : public Pistache::Http::Handler {
 public:
  HTTP_PROTOTYPE(RestHandler)
  void onRequest(
      const Pistache::Http::Request& request,
      Pistache::Http::ResponseWriter response);
};

#endif /* REST_HANDLER_H_ */
