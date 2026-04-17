// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/ui/GridWidget.hpp
// Header file of grid widget.

#pragma once

#include <QWidget>

class GridWidget : public QWidget {
    int size_;
public:
    GridWidget(int size, QWidget* parent = nullptr);
};