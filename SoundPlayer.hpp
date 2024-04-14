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

#ifndef SOUND_PLAYER_HPP
#define SOUND_PLAYER_HPP
#include "SoundThrower.hpp"
#include "AudioEnums.hpp"
#include <SFML/Audio/SoundBuffer.hpp>
#include <array>

namespace CrazySnakes {

class SoundPlayer {
public:

    template<class FwdIt>
    [[nodiscard]] bool loadSounds(FwdIt filenameIter) {
        for (int i = 0; i < SoundTypeCount; ++i) {
            if (!m_soundBuffers[i].loadFromFile((*filenameIter).string()))
                return false;
            ++filenameIter;
        }
        return true;
    }

    void playSound(SoundType sound, const SoundThrower::Parameters& parameters);

private:

    std::array<sf::SoundBuffer, SoundTypeCount> m_soundBuffers;
    SoundThrower m_soundThrower;
};

}

#endif // !SOUND_PLAYER_HPP
