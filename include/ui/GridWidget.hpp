// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// include/ui/GridWidget.hpp
// Header file of grid widget.

#pragma once

#include <QWidget>

constexpr int CELL_LENGTH = 30;
constexpr QColor BACKGROUND_COLOR(135, 150, 186);
constexpr QColor SNAKE_COLOR(160, 193, 128);
constexpr QColor APPLE_COLOR(198, 45, 45);

class GridWidget : public QWidget {
    int size_;
    int* data_;
public:
    GridWidget(int size, int* data, QWidget* parent = nullptr);
protected:
    void paintEvent(QPaintEvent* event) override;
};