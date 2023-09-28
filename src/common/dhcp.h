/*
 * DHCP definitions
 * Copyright (c) 2014-2017, Qualcomm Atheros, Inc.
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef DHCP_H
#define DHCP_H

#if 0
#include <netinet/ip.h>
#if __FAVOR_BSD
#include <netinet/udp.h>
#else
#define __FAVOR_BSD 1
#include <netinet/udp.h>
#undef __FAVOR_BSD
#endif
#endif

#define DHCP_SERVER_PORT 67
#define DHCP_CLIENT_PORT 68

struct dhcp_data
{
    u8 op;
    u8 htype;
    u8 hlen;
    u8 hops;
    be32 xid;
    be16 secs;
    be16 flags;
    be32 client_ip;
    be32 your_ip;
    be32 server_ip;
    be32 relay_ip;
    u8 hw_addr[16];
    u8 serv_name[64];
    u8 boot_file[128];
} STRUCT_PACKED;

struct bootp_pkt
{
    //    struct ip iph;
    //    struct udphdr udph;
    u8 op;
    u8 htype;
    u8 hlen;
    u8 hops;
    be32 xid;
    be16 secs;
    be16 flags;
    be32 client_ip;
    be32 your_ip;
    be32 server_ip;
    be32 relay_ip;
    u8 hw_addr[16];
    u8 serv_name[64];
    u8 boot_file[128];
    u8 exten[312];
} STRUCT_PACKED;

#define DHCP_MAGIC 0x63825363

/*
 * IANA DHCP/BOOTP registry
 * http://www.iana.org/assignments/bootp-dhcp-parameters/bootp-dhcp-parameters.xhtml
 */
enum dhcp_options
{
    DHCP_OPT_PAD                               = 0,
    DHCP_OPT_SUBNET_MASK                       = 1,
    DHCP_OPT_TIME_OFFSET                       = 2,
    DHCP_OPT_ROUTER                            = 3,
    DHCP_OPT_TIME_SERVER                       = 4,
    DHCP_OPT_NAME_SERVER                       = 5,
    DHCP_OPT_DOMAIN_NAME_SERVER                = 6,
    DHCP_OPT_LOG_SERVER                        = 7,
    DHCP_OPT_QUOTES_SERVER                     = 8,
    DHCP_OPT_LPR_SERVER                        = 9,
    DHCP_OPT_IMPRESS_SERVER                    = 10,
    DHCP_OPT_RLP_SERVER                        = 11,
    DHCP_OPT_HOSTNAME                          = 12,
    DHCP_OPT_BOOT_FILE_SIZE                    = 13,
    DHCP_OPT_MERIT_DUMP_FILE                   = 14,
    DHCP_OPT_DOMAIN_NAME                       = 15,
    DHCP_OPT_SWAP_SERVER                       = 16,
    DHCP_OPT_ROOT_PATH                         = 17,
    DHCP_OPT_EXTENSION_PATH                    = 18,
    DHCP_OPT_FORWARD                           = 19,
    DHCP_OPT_SRC_RTE                           = 20,
    DHCP_OPT_POLICY_FILTER                     = 21,
    DHCP_OPT_MAX_DG_ASSEMBLY                   = 22,
    DHCP_OPT_DEFAULT_IP_TTL                    = 23,
    DHCP_OPT_MTU_TIMEOUT                       = 24,
    DHCP_OPT_MTU_PLATEAU                       = 25,
    DHCP_OPT_MTU_INTERFACE                     = 26,
    DHCP_OPT_ALL_SUBNETS_LOCAL                 = 27,
    DHCP_OPT_BROADCAST_ADDRESS                 = 28,
    DHCP_OPT_MASK_DISCOVERY                    = 29,
    DHCP_OPT_MASK_SUPPLIER                     = 30,
    DHCP_OPT_ROUTER_DISCOVERY                  = 31,
    DHCP_OPT_ROUTER_SOLICITATION_ADDRESS       = 32,
    DHCP_OPT_STATIC_ROUTE                      = 33,
    DHCP_OPT_TRAILERS                          = 34,
    DHCP_OPT_ARP_TIMEOUT                       = 35,
    DHCP_OPT_ETHERNET                          = 36,
    DHCP_OPT_TCP_DEFAULT_TTL                   = 37,
    DHCP_OPT_TCP_KEEPALIVE_INTERVAL            = 38,
    DHCP_OPT_TCP_KEEPALIVE_GARBAGE             = 39,
    DHCP_OPT_NIS_DOMAIN                        = 40,
    DHCP_OPT_NIS_SERVERS                       = 41,
    DHCP_OPT_NTP_SERVERS                       = 42,
    DHCP_OPT_VENDOR_SPECIFIC                   = 43,
    DHCP_OPT_NETBIOS_NAME_SERVER               = 44,
    DHCP_OPT_NETBIOS_DISTRIBUTION_SERVER       = 45,
    DHCP_OPT_NETBIOS_NODE_TYPE                 = 46,
    DHCP_OPT_NETBIOS_SCOPE                     = 47,
    DHCP_OPT_FONT_SERVER                       = 48,
    DHCP_OPT_DISPLAY_MANAGER                   = 49,
    DHCP_OPT_REQUESTED_IP_ADDRESS              = 50,
    DHCP_OPT_IP_ADDRESS_LEASE_TIME             = 51,
    DHCP_OPT_OVERLOAD                          = 52,
    DHCP_OPT_MSG_TYPE                          = 53,
    DHCP_OPT_SERVER_ID                         = 54,
    DHCP_OPT_PARAMETER_REQ_LIST                = 55,
    DHCP_OPT_MESSAGE                           = 56,
    DHCP_OPT_MAX_MESSAGE_SIZE                  = 57,
    DHCP_OPT_RENEWAL_TIME                      = 58,
    DHCP_OPT_REBINDING_TIME                    = 59,
    DHCP_OPT_VENDOR_CLASS_ID                   = 60,
    DHCP_OPT_CLIENT_ID                         = 61,
    DHCP_OPT_NETWARE_IP_DOMAIN                 = 62,
    DHCP_OPT_NETWARE_IP_OPTION                 = 63,
    DHCP_OPT_NIS_V3_DOMAIN                     = 64,
    DHCP_OPT_NIS_V3_SERVERS                    = 65,
    DHCP_OPT_TFTP_SERVER_NAME                  = 66,
    DHCP_OPT_BOOT_FILE_NAME                    = 67,
    DHCP_OPT_HOME_AGENT_ADDRESSES              = 68,
    DHCP_OPT_SMTP_SERVER                       = 69,
    DHCP_OPT_POP3_SERVER                       = 70,
    DHCP_OPT_NNTP_SERVER                       = 71,
    DHCP_OPT_WWW_SERVER                        = 72,
    DHCP_OPT_FINGER_SERVER                     = 73,
    DHCP_OPT_IRC_SERVER                        = 74,
    DHCP_OPT_STREETTALK_SERVER                 = 75,
    DHCP_OPT_STDA_SERVER                       = 76,
    DHCP_OPT_USER_CLASS                        = 77,
    DHCP_OPT_DIRECTORY_AGENT                   = 78,
    DHCP_OPT_SERVICE_SCOPE                     = 79,
    DHCP_OPT_RAPID_COMMIT                      = 80,
    DHCP_OPT_CLIENT_FQDN                       = 81,
    DHCP_OPT_RELAY_AGENT_INFO                  = 82,
    DHCP_OPT_ISNS                              = 83,
    DHCP_OPT_NDS_SERVERS                       = 85,
    DHCP_OPT_NDS_TREE_NAME                     = 86,
    DHCP_OPT_NDS_CONTEXT                       = 87,
    DHCP_OPT_BCMCS_CONTROLLER_DOMAIN_NAME_LIST = 88,
    DHCP_OPT_BCMCS_CONTROLLER_IPV4_ADDRESS     = 89,
    DHCP_OPT_AUTHENTICATION                    = 90,
    DHCP_OPT_CLIENT_LAST_TRANSACTION_TIME      = 91,
    DHCP_OPT_ASSOCIATED_IP                     = 92,
    DHCP_OPT_CLIENT_SYSYEM                     = 93,
    DHCP_OPT_CLIENT_NDI                        = 94,
    DHCP_OPT_LDAP                              = 95,
    DHCP_OPT_UUID_GUID                         = 97,
    DHCP_OPT_USER_AUTH                         = 98,
    DHCP_OPT_GEOCONF_CIVIC                     = 99,
    DHCP_OPT_PCODE                             = 100,
    DHCP_OPT_TCODE                             = 101,
    DHCP_OPT_NETINFO_ADDRESS                   = 112,
    DHCP_OPT_NETINFO_TAG                       = 113,
    DHCP_OPT_URL                               = 114,
    DHCP_OPT_AUTO_CONFIG                       = 116,
    DHCP_OPT_NAME_SERVICE_SEARCH               = 117,
    DHCP_OPT_SUBNET_SELECTION                  = 118,
    DHCP_OPT_DOMAIN_SEARCH                     = 119,
    DHCP_OPT_SIP_SERVERS_DCP                   = 120,
    DHCP_OPT_CLASSLESS_STATIC_ROUTE            = 121,
    DHCP_OPT_CCC                               = 122,
    DHCP_OPT_GEOCONF                           = 123,
    DHCP_OPT_V_I_VENDOR_CLASS                  = 124,
    DHCP_OPT_V_I_VENDOR_SPECIFIC_INFO          = 125,
    DHCP_OPT_PANA_AGENT                        = 136,
    DHCP_OPT_V4_LOST                           = 137,
    DHCP_OPT_CAPWAP_AC_V4                      = 138,
    DHCP_OPT_IPV4_ADDRESS_MOS                  = 139,
    DHCP_OPT_IPV4_FQDN_MOS                     = 140,
    DHCP_OPT_SIP_UA_CONF                       = 141,
    DHCP_OPT_IPV4_ADDRESS_ANDSF                = 142,
    DHCP_OPT_GEOLOC                            = 144,
    DHCP_OPT_FORCERENEW_NONCE_CAPABLE          = 145,
    DHCP_OPT_RDNSS_SELECTION                   = 146,
    DHCP_OPT_TFTP_SERVER_ADDRESS               = 150,
    DHCP_OPT_STATUS_CODE                       = 151,
    DHCP_OPT_BASE_TIME                         = 152,
    DHCP_OPT_START_TIME_OF_STATE               = 153,
    DHCP_OPT_QUERY_START_TIME                  = 154,
    DHCP_OPT_QUERY_END_TIME                    = 155,
    DHCP_OPT_STATE                             = 156,
    DHCP_OPT_DATA_SOURCE                       = 157,
    DHCP_OPT_V4_PCP_SERVER                     = 158,
    DHCP_OPT_V4_PORTPARAMS                     = 159,
    DHCP_OPT_CAPTIVE_PORTAL                    = 160,
    DHCP_OPT_CONF_FILE                         = 209,
    DHCP_OPT_PATH_PREFIX                       = 210,
    DHCP_OPT_REBOOT_TIME                       = 211,
    DHCP_OPT_6RD                               = 212,
    DHCP_OPT_V4_ACCESS_DOMAIN                  = 213,
    DHCP_OPT_SUBNET_ALLOCATION                 = 220,
    DHCP_OPT_VSS                               = 221,
    DHCP_OPT_END                               = 255
};

enum dhcp_message_types
{
    DHCPDISCOVER         = 1,
    DHCPOFFER            = 2,
    DHCPREQUEST          = 3,
    DHCPDECLINE          = 4,
    DHCPACK              = 5,
    DHCPNAK              = 6,
    DHCPRELEASE          = 7,
    DHCPINFORM           = 8,
    DHCPFORCERENEW       = 9,
    DHCPLEASEQUERY       = 10,
    DHCPLEASEUNASSIGNED  = 11,
    DHCPLEASEUNKNOWN     = 12,
    DHCPLEASEACTIVE      = 13,
    DHCPBULKLEASEQUERY   = 14,
    DHCPLEASEQUERYDONE   = 15,
    DHCPACTIVELEASEQUERY = 16,
    DHCPLEASEQUERYSTATUS = 17,
    DHCPTLS              = 18,
};

enum dhcp_relay_agent_suboptions
{
    DHCP_RELAY_OPT_AGENT_CIRCUIT_ID                        = 1,
    DHCP_RELAY_OPT_AGENT_REMOTE_ID                         = 2,
    DHCP_RELAY_OPT_DOCSIS_DEVICE_CLASS                     = 4,
    DHCP_RELAY_OPT_LINK_SELECTION                          = 5,
    DHCP_RELAY_OPT_SUBSCRIBE_ID                            = 6,
    DHCP_RELAY_OPT_RADIUS_ATTRIBUTES                       = 7,
    DHCP_RELAY_OPT_AUTHENTICATION                          = 8,
    DHCP_RELAY_OPT_VEDOR_SPECIFIC                          = 9,
    DHCP_RELAY_OPT_RELAY_AGENT_FLAGS                       = 10,
    DHCP_RELAY_OPT_SERVER_ID_OVERRIDE                      = 11,
    DHCP_RELAY_OPT_RELAY_AGENT_ID                          = 12,
    DHCP_RELAY_OPT_ACCESS_TECHNOLOGY_TYPE                  = 13,
    DHCP_RELAY_OPT_ACCESS_NETWORK_NAME                     = 14,
    DHCP_RELAY_OPT_ACCESS_POINT_NAME                       = 15,
    DHCP_RELAY_OPT_ACCESS_POINT_BSSID                      = 16,
    DHCP_RELAY_OPT_OPERATOR_ID                             = 17,
    DHCP_RELAY_OPT_OPERATOR_REALM                          = 18,
    DHCP_RELAY_OPT_DHCPV4_VIRTUAL_SUBNET_SELECTION         = 151,
    DHCP_RELAY_OPT_DHCPV4_VIRTUAL_SUBNET_SELECTION_CONTROL = 152,
};

enum access_technology_types
{
    ACCESS_TECHNOLOGY_VIRTUAL  = 1,
    ACCESS_TECHNOLOGY_PPP      = 2,
    ACCESS_TECHNOLOGY_ETHERNET = 3,
    ACCESS_TECHNOLOGY_WLAN     = 4,
    ACCESS_TECHNOLOGY_WIMAX    = 5,
};

#endif /* DHCP_H */
