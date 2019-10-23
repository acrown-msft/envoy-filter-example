#include "echo2.h"

#include "envoy/buffer/buffer.h"
#include "envoy/network/connection.h"

#include "common/common/assert.h"

#include <iostream>

namespace Envoy {
namespace Filter {

Network::FilterStatus Echo2::onData(Buffer::Instance& data, bool) {
  ENVOY_CONN_LOG(trace, "echo: got {} bytes", read_callbacks_->connection(), data.length());
  std::cout << "Filter example code being executed" << std::endl;
  read_callbacks_->connection().write(data, false);
  return Network::FilterStatus::StopIteration;
}

} // namespace Filter
} // namespace Envoy
