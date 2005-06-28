/*
 *  xfce4-mailwatch-plugin - a mail notification applet for the xfce4 panel
 *  Copyright (c) 2005 Brian Tarricone <bjt23@cornell.edu>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License ONLY.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __MAILWATCH_UTILS_H__
#define __MAILWATCH_UTILS_H__

#include <gtk/gtk.h>

#include <gnutls/gnutls.h>

G_BEGIN_DECLS

typedef enum
{
    AUTH_NONE = 0,
    AUTH_SSL_PORT,
    AUTH_STARTTLS
} XfceMailwatchAuthType;

typedef struct
{
    gboolean using_tls;
    gboolean gnutls_inited;
    gnutls_session_t gt_session;
    gnutls_certificate_credentials_t gt_creds;
} XfceMailwatchSecurityInfo;

gboolean xfce_mailwatch_net_get_sockaddr(const gchar *host, const gchar *service, struct addrinfo *hints, struct sockaddr_in *addr);
gboolean xfce_mailwatch_net_negotiate_tls(gint sockfd, XfceMailwatchSecurityInfo *security_info, const gchar *host);
gssize xfce_mailwatch_net_send(gint sockfd, XfceMailwatchSecurityInfo *security_info, const gchar *buf);
gssize xfce_mailwatch_net_recv(gint sockfd, XfceMailwatchSecurityInfo *security_info, gchar *buf, gsize len);
void xfce_mailwatch_net_tls_teardown(XfceMailwatchSecurityInfo *security_info);


GtkWidget *xfce_mailwatch_custom_button_new(const gchar *text, const gchar *icon);

G_END_DECLS

#endif