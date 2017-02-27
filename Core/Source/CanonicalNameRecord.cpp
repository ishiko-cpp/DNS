/*
    Copyright (c) 2017 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include "CanonicalNameRecord.h"
#include <boost/endian/conversion.hpp>

namespace Ishiko
{
namespace DNS
{

CanonicalNameRecord::CanonicalNameRecord(const std::string& domainName,
                                         uint32_t ttl,
                                         const std::string& canonicalDomainName)
    : ResourceRecord(domainName, TYPE_CNAME, CLASS_IN, ttl),
    m_CNAME(canonicalDomainName)
{
}

void CanonicalNameRecord::writeBinary(std::ostream& stream) const
{
    writeBinaryBase(stream);
    uint16_t tmp = boost::endian::native_to_big(m_CNAME.length());
    stream.write((const char*)&tmp, 2);
    m_CNAME.writeBinary(stream);
}

void CanonicalNameRecord::writeText(std::ostream& stream) const
{
}

}
}
