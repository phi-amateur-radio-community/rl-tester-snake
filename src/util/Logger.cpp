// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/util/Logger.cpp
// Record and read log file.

#include <filesystem>
#include <iostream>
#include <util/Logger.hpp>

struct LogTypeVisitor {
    string operator()(const Action action) const {
        string msg;
        switch (action) {
            case Action::Up:
                msg = "U";
                break;
            case Action::Down:
                msg = "D";
                break;
            case Action::Left:
                msg = "L";
                break;
            case Action::Right:
                msg = "R";
                break;
        }
        return msg;
    }

    string operator()(const SpawnApple spawn) const {
        return "A" + to_string(spawn.position);
    }

    string operator()(const SpawnSnake spawn) const {
        return "S" + to_string(spawn.position);
    }
};

Logger::Logger(const string &path) {
    log_file_ = fstream(path, ios::in);
    active_ = true;
    if (!log_file_) {
        cout << "Error opening log file." << endl;
        exit(1);
    }
}

Logger::Logger(const string &path, bool active): active_(active) {
    if (active) {
        log_file_ = fstream(path, ios::out | ios::trunc);
        if (!log_file_) {
            cout << "Error opening log file." << endl;
            exit(1);
        }
    }
}

void Logger::write(LogType data) {
    if (!active_) {
        return;
    }
    log_file_ << visit(LogTypeVisitor(), data) << endl;
}

LogType Logger::read() {
    string msg;
    getline(log_file_, msg);
    switch (msg[0]) {
        case 'U':
            return Action::Up;
        case 'D':
            return Action::Down;
        case 'L':
            return Action::Left;
        case 'R':
            return Action::Right;
        case 'A':
            return SpawnApple(stoi(msg.substr(1)));
        case 'S':
            return SpawnSnake(stoi(msg.substr(1)));
        default: ;
    }
    return SpawnSnake();
}
