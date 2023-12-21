#Description: Wpa supplicant dpp; user_visible: True
include_guard(GLOBAL)
message("middleware_wireless_wpa_supplicant_dpp component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/wpa_supplicant/dpp_supplicant.c
    ${CMAKE_CURRENT_LIST_DIR}/wpa_supplicant/interworking.c
    ${CMAKE_CURRENT_LIST_DIR}/src/common/dpp.c
    ${CMAKE_CURRENT_LIST_DIR}/src/common/dpp_auth.c
    ${CMAKE_CURRENT_LIST_DIR}/src/common/dpp_backup.c
    ${CMAKE_CURRENT_LIST_DIR}/src/common/dpp_crypto.c
    ${CMAKE_CURRENT_LIST_DIR}/src/common/dpp_pkex.c
    ${CMAKE_CURRENT_LIST_DIR}/src/common/dpp_reconfig.c
    ${CMAKE_CURRENT_LIST_DIR}/src/common/dpp_tcp.c
    ${CMAKE_CURRENT_LIST_DIR}/src/common/gas_server.c
    ${CMAKE_CURRENT_LIST_DIR}/src/utils/json.c
    ${CMAKE_CURRENT_LIST_DIR}/src/tls/asn1.c
    ${CMAKE_CURRENT_LIST_DIR}/src/ap/dpp_hostapd.c
    ${CMAKE_CURRENT_LIST_DIR}/src/ap/gas_query_ap.c
    ${CMAKE_CURRENT_LIST_DIR}/src/ap/gas_serv.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
    ${CMAKE_CURRENT_LIST_DIR}/freertos
    ${CMAKE_CURRENT_LIST_DIR}/freertos/src
    ${CMAKE_CURRENT_LIST_DIR}/freertos/src/utils
    ${CMAKE_CURRENT_LIST_DIR}/hostapd
    ${CMAKE_CURRENT_LIST_DIR}/port/lwip
    ${CMAKE_CURRENT_LIST_DIR}/port/mbedtls
    ${CMAKE_CURRENT_LIST_DIR}/src
    ${CMAKE_CURRENT_LIST_DIR}/src/ap
    ${CMAKE_CURRENT_LIST_DIR}/src/common
    ${CMAKE_CURRENT_LIST_DIR}/src/crypto
    ${CMAKE_CURRENT_LIST_DIR}/src/drivers
    ${CMAKE_CURRENT_LIST_DIR}/src/eap_common
    ${CMAKE_CURRENT_LIST_DIR}/src/eap_peer
    ${CMAKE_CURRENT_LIST_DIR}/src/eap_server
    ${CMAKE_CURRENT_LIST_DIR}/src/eapol_auth
    ${CMAKE_CURRENT_LIST_DIR}/src/eapol_supp
    ${CMAKE_CURRENT_LIST_DIR}/src/fst
    ${CMAKE_CURRENT_LIST_DIR}/src/l2_packet
    ${CMAKE_CURRENT_LIST_DIR}/src/p2p
    ${CMAKE_CURRENT_LIST_DIR}/src/pae
    ${CMAKE_CURRENT_LIST_DIR}/src/radius
    ${CMAKE_CURRENT_LIST_DIR}/src/rsn_supp
    ${CMAKE_CURRENT_LIST_DIR}/src/tls
    ${CMAKE_CURRENT_LIST_DIR}/src/utils
    ${CMAKE_CURRENT_LIST_DIR}/src/wps
    ${CMAKE_CURRENT_LIST_DIR}/wpa_supplicant
)


include(middleware_wireless_wpa_supplicant_rtos)
