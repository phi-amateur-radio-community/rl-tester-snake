// Copyright (c) 2026 Phiarc Team and St Rangeset
// Licensed under the GNU General Public License v3.0
// See LICENSE file for details.
//
// src/ui/GridWidget.cpp
// Grid layout widget.

#include <ui/GridWidget.hpp>
#include <core/Action.hpp>
#include <QPainter>
#include <QKeyEvent>

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
            } else if (data_[index] == -1) {
                p.fillRect(i*CELL_LENGTH, j*CELL_LENGTH, CELL_LENGTH, CELL_LENGTH, APPLE_COLOR);
            }
            index++;
        }
    }
}

void GridWidget::keyPressEvent(QKeyEvent *event) {
    if (!key_call_back_) return;
    switch (event->key()) {
        case Qt::Key_W:
            key_call_back_->onClick(Action::Up);
            break;
        case Qt::Key_S:
            key_call_back_->onClick(Action::Down);
            break;
        case Qt::Key_A:
            key_call_back_->onClick(Action::Right);
            break;
        case Qt::Key_D:
            key_call_back_->onClick(Action::Left);
            break;
        default: ;
    }
}
