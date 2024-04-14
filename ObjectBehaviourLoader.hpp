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

#ifndef OBJECT_BEHAVIOUR_LOADER_HPP
#define OBJECT_BEHAVIOUR_LOADER_HPP
#include "ObjectBehaviour.hpp"

namespace sf {
class InputStream;
}

namespace CrazySnakes {

class ObjectBehaviour;
enum class ObjectCommand;
enum class ObjectBehaviourKeyword;

class ObjectBehaviourLoader {
public:

    [[nodiscard]] static std::optional<std::string>
        loadFromStream(std::vector<ObjectBehaviour>& objBehvrs, sf::InputStream& stream, bool endiannessRequired);

private:

    enum class LoaderKeyWord {
        Comma,
        Condition,
        Command,
        End
    };

    enum class Context {
        KeywordExpected,
        InputingCommand,
        InputingCommandExpr,
        InputingConditionExpr,
        Ended
    };

    class StuffForCreating {
    public:

        [[nodiscard]] std::optional<std::string> createObject();
        [[nodiscard]] bool inputCommand();
        [[nodiscard]] std::optional<std::string> inputKeyword();

        std::vector<ObjectBehaviour> objBehPrep;

        // Object behaviour template to load
        std::vector<std::vector<std::uint32_t>> condExp, modExp;
        std::vector<ObjectCommand> obcommands;

        Context context = Context::KeywordExpected;
        std::uint32_t input = 0;
    };
};

}

#endif // !OBJECT_BEHAVIOUR_LOADER_HPP