// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/core/Session.cpp
// Program session.

#include <core/Session.hpp>

Session::Session(int size, bool gui) : gui_(gui), table_(size^2) {
    size_ = size;
    if (gui) {
        window_ = new QWidget();
        window_->setFixedSize(size_*30, size_*30);
        window_->show();
    }
}