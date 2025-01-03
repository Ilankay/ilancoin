// Copyright (c) 2011-2014 The Ilancoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ILANCOIN_QT_ILANCOINADDRESSVALIDATOR_H
#define ILANCOIN_QT_ILANCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class IlancoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit IlancoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Ilancoin address widget validator, checks for a valid ilancoin address.
 */
class IlancoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit IlancoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // ILANCOIN_QT_ILANCOINADDRESSVALIDATOR_H
