// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Ilancoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ILANCOIN_SCRIPT_ILANCOINCONSENSUS_H
#define ILANCOIN_SCRIPT_ILANCOINCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_ILANCOIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/ilancoin-config.h>
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBILANCOINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define ILANCOINCONSENSUS_API_VER 1

typedef enum ilancoinconsensus_error_t
{
    ilancoinconsensus_ERR_OK = 0,
    ilancoinconsensus_ERR_TX_INDEX,
    ilancoinconsensus_ERR_TX_SIZE_MISMATCH,
    ilancoinconsensus_ERR_TX_DESERIALIZE,
    ilancoinconsensus_ERR_AMOUNT_REQUIRED,
    ilancoinconsensus_ERR_INVALID_FLAGS,
} ilancoinconsensus_error;

/** Script verification flags */
enum
{
    ilancoinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    ilancoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    ilancoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    ilancoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    ilancoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    ilancoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    ilancoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    ilancoinconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = ilancoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH | ilancoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               ilancoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | ilancoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               ilancoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | ilancoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int ilancoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, ilancoinconsensus_error* err);

EXPORT_SYMBOL int ilancoinconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, ilancoinconsensus_error* err);

EXPORT_SYMBOL unsigned int ilancoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // ILANCOIN_SCRIPT_ILANCOINCONSENSUS_H
