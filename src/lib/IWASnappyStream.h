/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libetonyek project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef IWASNAPPYSTREAM_H_INCLUDED
#define IWASNAPPYSTREAM_H_INCLUDED

#include <librevenge-stream/librevenge-stream.h>

#include "libetonyek_utils.h"

namespace libetonyek
{

class IWASnappyStream : public librevenge::RVNGInputStream
{
public:
  explicit IWASnappyStream(const RVNGInputStreamPtr_t &stream);
  ~IWASnappyStream() override;

  // for unit tests
  static RVNGInputStreamPtr_t uncompressBlock(const RVNGInputStreamPtr_t &block);

  bool isStructured() override;
  unsigned subStreamCount() override;
  const char *subStreamName(unsigned id) override;
  bool existsSubStream(const char *name) override;

  librevenge::RVNGInputStream *getSubStreamByName(const char *name) override;
  librevenge::RVNGInputStream *getSubStreamById(unsigned id) override;

  const unsigned char *read(unsigned long numBytes, unsigned long &numBytesRead) override;
  int seek(long offset, librevenge::RVNG_SEEK_TYPE seekType) override;
  long tell() override;
  bool isEnd() override;

private:
  RVNGInputStreamPtr_t m_stream;
};

}

#endif // IWASNAPPYSTREAM_H_INCLUDED

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
