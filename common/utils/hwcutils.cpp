/*
// Copyright (c) 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#include "hwcutils.h"

#include <poll.h>

#include "hwctrace.h"

namespace hwcomposer {

int HWCPoll(int fd, int timeout) {
  CTRACE();
  int ret;
  struct pollfd fds[1];
  fds[0].fd = fd;
  fds[0].events = POLLIN;

  if ((ret = poll(fds, 1, timeout)) <= 0) {
    ETRACE("Poll Failed in HWCPoll %s", PRINTERROR());
  }
 return ret;
}

}  // namespace hwcomposer
