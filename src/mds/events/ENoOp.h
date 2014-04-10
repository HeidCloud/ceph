// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*- 
// vim: ts=8 sw=2 smarttab
/*
 * Ceph - scalable distributed file system
 *
 * Copyright (C) 2004-2006 Sage Weil <sage@newdream.net>
 *
 * This is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1, as published by the Free Software 
 * Foundation.  See file COPYING.
 * 
 */

#ifndef CEPH_MDS_ENOOP_H
#define CEPH_MDS_ENOOP_H

#include "../LogEvent.h"

class ENoOp : public LogEvent {
  uint32_t size;

public:
  ENoOp() : LogEvent(EVENT_NOOP), size(0) { }
  ENoOp(uint32_t size_) : LogEvent(EVENT_NOOP), size(size){ }

  void encode(bufferlist& bl) const;
  void decode(bufferlist::iterator& bl);
  void dump(Formatter *f) const {}

  void replay(MDS *mds);
};

#endif
