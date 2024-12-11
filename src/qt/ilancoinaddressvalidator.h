// Copyright (c) 2011-2020 The Blancoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ILANCOIN_QT_ILANCOINADDRESSVALIDATOR_H
#define ILANCOIN_QT_ILANCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class BlancoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BlancoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** Blancoin address widget validator, checks for a valid ilancoin address.
 */
class BlancoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BlancoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // ILANCOIN_QT_ILANCOINADDRESSVALIDATOR_H
