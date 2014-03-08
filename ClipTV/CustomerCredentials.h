/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */


// You have been issued a Gracenote Client ID from Gracenote Professional Services.
// This client ID has the form XXXXXXXX-xxxxxxxxxxxxxxxxxxxxxxxxxxxxx

// Replace the CLIENT_ID below with the XXXXXXXX from your client ID
// Replace the CLIENT_ID_TAG below with the xxxxxxxxxxxxxxxxxxxxxxxxxxxxx from your client ID

// This Client ID/TAG is used for ACR/Video/EPG queries
#define CLIENT_ID_VIDEO               @"8027136" // replace me
#define CLIENT_TAG_VIDEO           @"781F5E799C9A08AB5A2523212F81A773" // replace me


// MusicID queries require a separate client ID/TAG.
// Consult Gracenote Professional Severices for assistance.
#define ENABLE_MUSIC_ID 1
#if ENABLE_MUSIC_ID

#define CLIENT_ID_MUSIC             @"" // replace me
#define CLIENT_TAG_MUSIC         @"" // replace me

#endif



// You have also been issued a license file from GN Professional Services.
// replace the empty LICENSE_STRING below with the text from you license file.
// Line feeds should be replaced by the escape string "\r\n", e.g. @"this is line one\r\nThis is line 2"
// GN Professional Services can supply you with a properly formatted license string by request.

// If you wish to utilize both ACR/Video/EPG and MusicID in the same application, the
// license must contain entitlements for both clientIDs above. Consult Gracenote Professional
// Severices for assistance.

#define LICENSE_STRING            @"-- BEGIN LICENSE v1.0 1ACA2C28 --\r\n" \
"licensee: Gracenote, Inc.\r\n" \
"name: TBS Hack Day\r\n" \
"notes: ODP for Entourage\r\n\r\n" \
"client_id: 8027136\r\n" \
"acr: enabled\r\n\r\n" \
"client_id: 11944960\r\n" \
"musicid_text: enabled\r\n" \
"musicid_stream: enabled\r\n\r\n" \
"-- SIGNATURE 1ACA2C28 --\r\n" \
"lAADAgAfAR2OP5jvVW5UodRh7qqn77/vbxkkkZqlo+b4rSBmGQAfAZGDUuCk+v4CFnXUMtqzBUE8bfH7EwSoahe4xt7yyQ==\r\n" \
"-- END LICENSE 1ACA2C28 --\r\n"

