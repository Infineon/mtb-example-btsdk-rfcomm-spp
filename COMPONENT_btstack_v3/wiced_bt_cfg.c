/*
 * Copyright 2016-2023, Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software") is owned by Cypress Semiconductor Corporation
 * or one of its affiliates ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products.  Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

/** @file
 *
 * Runtime Bluetooth stack configuration parameters
 *
 */

#include "wiced_bt_dev.h"
#include "wiced_bt_ble.h"
#include "wiced_bt_uuid.h"
#include "wiced_bt_gatt.h"
#include "wiced_bt_cfg.h"
#include "cycfg_bt_settings.h"

/* Null-Terminated Local Device Name */
uint8_t BT_LOCAL_NAME[] = { 's','p','p',' ','t','e','s','t','\0' };
const uint16_t BT_LOCAL_NAME_CAPACITY = sizeof(BT_LOCAL_NAME);


/*******************************************************************
 * wiced_bt core stack configuration
 ******************************************************************/
/* L2CAP Setting */
const wiced_bt_cfg_l2cap_application_t wiced_bt_cfg_l2cap_app = /* Application managed l2cap protocol configuration */
{
    /* BR EDR l2cap configuration */
    .max_app_l2cap_psms                 = 0,    /**< Maximum number of application-managed BR/EDR PSMs */
    .max_app_l2cap_channels             = 0,    /**< Maximum number of application-managed BR/EDR channels  */

    .max_app_l2cap_br_edr_ertm_chnls    = 0,    /**< Maximum ERTM channels allowed */
    .max_app_l2cap_br_edr_ertm_tx_win   = 0,    /**< Maximum ERTM TX Window allowed */

    /* LE L2cap connection-oriented channels configuration */
    .max_app_l2cap_le_fixed_channels    = 0,
};

/* BR Setting */
const wiced_bt_cfg_br_t wiced_bt_cfg_br =
{
    .br_max_simultaneous_links = 3,
    .br_max_rx_pdu_size = 1024,
    .device_class = {0x00, 0x00, 0x00},                 /**< Local device class */

    .rfcomm_cfg = /* RFCOMM configuration */
    {
        .max_links = 2, /**< Maximum number of simultaneous connected remote devices. Should be less than or equal to l2cap_application_max_links */
        .max_ports = 2, /**< Maximum number of simultaneous RFCOMM ports */
    },
    .avdt_cfg = /* Audio/Video Distribution configuration */
    {
        .max_links = 0, /**< Maximum simultaneous audio/video links */
        .max_seps  = 0, /**< Maximum number of stream end points */
    },

    .avrc_cfg = /* Audio/Video Remote Control configuration */
    {
        .max_links = 0, /**< Maximum simultaneous remote control links */
    },
};

/* ISOC Setting */
const wiced_bt_cfg_isoc_t wiced_bt_cfg_isoc =
{
    .max_cis_conn = 0,          /**< Max Number of CIS connections */
    .max_cig_count = 0,         /**< Max Number of CIG connections */
    .max_sdu_size = 0,          /**< Max SDU size */
    .channel_count = 0,         /**< Channel count */
    .max_buffers_per_cis = 0,   /**< Max Number of buffers per CIS */
};

 /* wiced_bt core stack configuration */
const wiced_bt_cfg_settings_t wiced_bt_cfg_settings =
{
    .device_name = (uint8_t*)BT_LOCAL_NAME,                      /**< Local device name (NULL terminated). Use same as configurator generated string.*/
    .security_required = BTM_SEC_BEST_EFFORT,                    /**< Security requirements mask */
    .p_br_cfg = &wiced_bt_cfg_br,
    .p_ble_cfg = &cy_bt_cfg_ble,
    .p_gatt_cfg = &cy_bt_cfg_gatt,
    .p_isoc_cfg = &wiced_bt_cfg_isoc,
    .p_l2cap_app_cfg = &wiced_bt_cfg_l2cap_app,
};
