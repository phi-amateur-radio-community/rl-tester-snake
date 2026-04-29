// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/util/Logger.hpp
// Header file of logger.

#pragma once

#include <fstream>
#include <variant>
#include <core/Action.hpp>

using namespace std;

struct SpawnApple {
    int position;
};

struct SpawnSnake {
    int position;
};

struct LogTypeVisitor {
    string operator()(Action action) const;
    string operator()(SpawnApple spawn) const;
    string operator()(SpawnSnake spawn) const;
};

using LogType = variant<Action, SpawnApple, SpawnSnake>;

class Logger {
    fstream log_file_;
    bool active_;
public:
    explicit Logger(const string &path);
    explicit Logger(const string &path, bool active);
    void write(LogType data);
    LogType read();
};