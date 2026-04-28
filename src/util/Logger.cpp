// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/util/Logger.cpp
// Record and read log file.

#include <iostream>
#include <util/Logger.hpp>

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

void Logger::write(const Action action) {
    if (!active_) {
        return;
    }
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
    log_file_ << msg << endl;
}

void Logger::write(const bool status, const int position) {
    if (!active_) {
        return;
    }
    if (status) {
        log_file_ << "A";
    } else {
        log_file_ << "S";
    }
    log_file_ << position << endl;
}
