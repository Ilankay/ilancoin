// Copyright (c) 2011-2020 The Blancoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ILANCOIN_QT_COINCONTROLTREEWIDGET_H
#define ILANCOIN_QT_COINCONTROLTREEWIDGET_H

#include <QKeyEvent>
#include <QTreeWidget>

class CoinControlTreeWidget : public QTreeWidget
{
    Q_OBJECT

public:
    explicit CoinControlTreeWidget(QWidget *parent = nullptr);

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // ILANCOIN_QT_COINCONTROLTREEWIDGET_H
