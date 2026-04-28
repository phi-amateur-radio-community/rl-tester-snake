// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/util/Logger.hpp
// Header file of logger.

#pragma once

#include <fstream>
#include <core/Action.hpp>

using namespace std;

class Logger {
    fstream log_file_;
    bool active_;
public:
    explicit Logger(const string &path);
    explicit Logger(const string &path, bool active);
    void write(Action action);
    void write(bool status, int position);
};