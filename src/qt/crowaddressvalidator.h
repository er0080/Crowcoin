// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CROW_QT_CROWADDRESSVALIDATOR_H
#define CROW_QT_CROWADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class CrowAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit CrowAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Crow address widget validator, checks for a valid crow address.
 */
class CrowAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit CrowAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // CROW_QT_CROWADDRESSVALIDATOR_H
