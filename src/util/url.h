// Copyright (c) 2015-2020 The Blancoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ILANCOIN_UTIL_URL_H
#define ILANCOIN_UTIL_URL_H

#include <string>

using UrlDecodeFn = std::string(const std::string& url_encoded);
UrlDecodeFn urlDecode;
extern UrlDecodeFn* const URL_DECODE;

#endif // ILANCOIN_UTIL_URL_H
