/*-
 * Copyright (c) 2010 Edward Tomasz Napierala <trasz@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id$
 */

#ifndef SMB2_SPNEGO_H
#define	SMB2_SPNEGO_H

struct smb2_connection;

/*
 * Client-side routines.
 */
void	smb2_spnego_take_neg_token_init_2(struct smb2_connection *conn, void *buf, size_t length);
void	smb2_spnego_make_neg_token_init(struct smb2_connection *conn, void **buf, size_t *length);
void	smb2_spnego_take_neg_token_resp(struct smb2_connection *conn, void *buf, size_t length);

/*
 * Server-side routines.
 */
void	smb2_spnego_server_make(struct smb2_connection *conn, void **buf, size_t *length);
int	smb2_spnego_server_take(struct smb2_connection *conn, const void *buf, size_t length);

/*
 * Called after smb2_spnego_make_whatever(), to free c_spnego_context.
 */
void	smb2_spnego_done(struct smb2_connection *conn);

#endif /* !SMB2_SPNEGO_H */
