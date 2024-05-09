////////////////////////////////////////////////////////////
//
// Snatan - Extreme Snake Game
// Copyright (c) 2024 Oleh Kiprik (oleg.kiprik@proton.me)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
////////////////////////////////////////////////////////////

// the modification of SFML source files. Here's the notice:

////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2024 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#include "MemoryOutputStream.hpp"
#include <cassert>
#include <cstring>

namespace CrazySnakes {

MemoryOutputStream::MemoryOutputStream() noexcept :
    m_memory(nullptr),
    m_pointer(0)
{}

MemoryOutputStream::MemoryOutputStream(std::vector<std::uint8_t>& handle) noexcept:
    m_memory(&handle),
    m_pointer(0)
{}

void MemoryOutputStream::open(std::vector<std::uint8_t>& handle) noexcept
{
    m_memory = &handle;
    m_pointer = 0;
}

std::int64_t MemoryOutputStream::write(const void* data, std::int64_t size) {
    assert(m_memory);
    if ((std::uint64_t)(m_pointer + size) > m_memory->size()) {
        m_memory->resize(m_pointer + size);
    }
    std::memcpy(m_memory->data() + m_pointer, data, size);
    m_pointer += size;
    return size;
}

std::int64_t MemoryOutputStream::seek(std::int64_t position) noexcept {
    assert(m_memory);
    if (position < 0) {
        return -1;
    }
    m_pointer = position;
    return m_pointer;
}

std::int64_t MemoryOutputStream::tell() noexcept {
    assert(m_memory);
    return m_pointer;
}

std::int64_t MemoryOutputStream::getSize() noexcept {
    assert(m_memory);
    return m_memory->size();
}

}
