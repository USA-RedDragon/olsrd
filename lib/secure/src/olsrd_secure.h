/*
 * The olsr.org Optimized Link-State Routing daemon (olsrd)
 *
 * (c) by the OLSR project
 *
 * See our Git repository to find out who worked on this file
 * and thus is a copyright holder on it.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name of olsr.org, olsrd nor the names of its
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Visit http://www.olsr.org for more information.
 *
 * If you find this software useful feel free to make a donation
 * to the project. For more information see the website or contact
 * the copyright holders.
 *
 */

/*
 * Dynamic linked library example for UniK OLSRd
 */

#ifndef _OLSRD_SECURE_H
#define _OLSRD_SECURE_H

#include "secure_messages.h"

#include "hashing.h"

#define KEYFILE "/etc/olsrd.d/olsrd_secure_key"

/* Schemes */
#define ONE_CHECKSUM          1

/* Algorithm definitions */
#define SHA1_INCLUDING_KEY   1
#define MD5_INCLUDING_KEY   2

#ifdef USE_OPENSSL
#define SIGNATURE_SIZE 20
#else /* USE_OPENSSL */
#define SIGNATURE_SIZE 16
#endif /* USE_OPENSSL */

#define KEYLENGTH      16

/* AE6XE and KG6JEI - prior logic averaged the delta between 2 samples had overflow */
/* to correct, delta between 2 samples now actual, updated bounds accordingly */

#define UPPER_DIFF 6
#define LOWER_DIFF -6

extern char aes_key[16];

/* Seconds of slack allowed */
#define SLACK 3

int secure_plugin_init(void);

void secure_plugin_exit(void);

int plugin_ipc_init(void);

#endif /* _OLSRD_SECURE_H */

/*
 * Local Variables:
 * c-basic-offset: 2
 * indent-tabs-mode: nil
 * End:
 */
