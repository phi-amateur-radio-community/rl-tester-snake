// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/ui/GridWidget.cpp
// Grid layout widget.

#include <ui/GridWidget.hpp>
#include <QPainter>

GridWidget::GridWidget(const int size, int* data, QWidget* parent) : QWidget(parent) {
    size_ = size;
    data_ = data;
    this->setFixedSize(size_*CELL_LENGTH, size_*CELL_LENGTH);
    this->update();
    this->show();
}

void GridWidget::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    p.fillRect(this->rect(), BACKGROUND_COLOR);
    int index = 0;
    for (int i = 0; i < size_; i++) {
        for (int j = 0; j < size_; j++) {
            if (data_[index] > 0) {
                p.fillRect(i*CELL_LENGTH, j*CELL_LENGTH, CELL_LENGTH, CELL_LENGTH, SNAKE_COLOR);
                qDebug() << i << " " << j;
            } else if (data_[index] == -1) {
                p.fillRect(i*CELL_LENGTH, j*CELL_LENGTH, CELL_LENGTH, CELL_LENGTH, APPLE_COLOR);
            }
            index++;
        }
    }
}