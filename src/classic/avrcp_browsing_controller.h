/*
 * Copyright (C) 2016 BlueKitchen GmbH
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holders nor the names of
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 * 4. Any redistribution, use, or modification is done solely for
 *    personal benefit and not for any commercial purpose or for
 *    monetary gain.
 *
 * THIS SOFTWARE IS PROVIDED BY BLUEKITCHEN GMBH AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MATTHIAS
 * RINGWALD OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Please inquire about commercial licensing options at 
 * contact@bluekitchen-gmbh.com
 *
 */

/*
 * avrcp_browsing_controller.h
 * 
 * Audio/Video Remote Control Profile Browsing
 *
 */

#ifndef __AVRCP_BROWSING_CONTROLLER_H
#define __AVRCP_BROWSING_CONTROLLER_H

#include <stdint.h>
#include "avrcp.h"

#if defined __cplusplus
extern "C" {
#endif


/* API_START */

typedef enum {
	AVRCP_BROWSING_MEDIA_PLAYER_ITEM = 0x01,
	AVRCP_BROWSING_FOLDER_ITEM,
	AVRCP_BROWSING_MEDIA_ELEMENT_ITEM
} avrcp_browsing_item_type_t;

typedef enum {
	AVRCP_BROWSING_MEDIA_PLAYER_MAJOR_TYPE_AUDIO = 1,
	AVRCP_BROWSING_MEDIA_PLAYER_MAJOR_TYPE_VIDEO = 2,
	AVRCP_BROWSING_MEDIA_PLAYER_MAJOR_TYPE_BROADCASTING_AUDIO = 4,
	AVRCP_BROWSING_MEDIA_PLAYER_MAJOR_TYPE_BROADCASTING_VIDEO = 8
} avrcp_browsing_media_player_major_type_t;

typedef enum {
	AVRCP_BROWSING_MEDIA_PLAYER_SUBTYPE_AUDIO_BOOK = 1,
	AVRCP_BROWSING_MEDIA_PLAYER_SUBTYPE_POADCAST   = 2
} avrcp_browsing_media_player_subtype_t;

typedef enum {
	AVRCP_BROWSING_MEDIA_PLAYER_STATUS_STOPPED = 0,
	AVRCP_BROWSING_MEDIA_PLAYER_STATUS_PLAYING,
	AVRCP_BROWSING_MEDIA_PLAYER_STATUS_PAUSED,
	AVRCP_BROWSING_MEDIA_PLAYER_STATUS_FWD_SEEK,
	AVRCP_BROWSING_MEDIA_PLAYER_STATUS_REV_SEEK,
	AVRCP_BROWSING_MEDIA_PLAYER_STATUS_ERROR = 0xFF
} avrcp_browsing_media_player_status_t;

typedef enum {
	AVRCP_BROWSING_FOLDER_TYPE_MIXED = 0x00,
	AVRCP_BROWSING_FOLDER_TYPE_TITLES,
	AVRCP_BROWSING_FOLDER_TYPE_ALBUMS,
	AVRCP_BROWSING_FOLDER_TYPE_ARTISTS,
	AVRCP_BROWSING_FOLDER_TYPE_GENRES,
	AVRCP_BROWSING_FOLDER_TYPE_PLAYLISTS,
	AVRCP_BROWSING_FOLDER_TYPE_YEARS
} avrcp_browsing_folder_type_t;

typedef enum {
	AVRCP_BROWSING_MEDIA_TYPE_AUDIO = 0x00,
	AVRCP_BROWSING_MEDIA_TYPE_VIDEO
} avrcp_browsing_media_type_t;

/**
 * @brief Set up AVRCP Browsing Controller device.
 */
void avrcp_browsing_controller_init(void);

/**
 * @brief Register callback for the AVRCP Browsing Controller client. 
 * @param callback
 */
// void avrcp_browsing_controller_register_packet_handler(btstack_packet_handler_t callback);

/**
 * @brief Connect to device with a Bluetooth address.
 * @param bd_addr
 * @param ertm_buffer
 * @param ertm_buffer_size
 * @param ertm_config
 * @param avrcp_browsing_cid
 * @returns status
 */
uint8_t avrcp_browsing_controller_connect(bd_addr_t bd_addr, uint8_t * ertm_buffer, uint32_t size, l2cap_ertm_config_t * ertm_config, uint16_t * avrcp_browsing_cid);

/**
 * @brief Disconnect from AVRCP target
 * @param avrcp_browsing_cid
 * @returns status
 */
uint8_t avrcp_browsing_controller_disconnect(uint16_t avrcp_browsing_cid);

/**
 * @brief Retrieve a listing of the contents of a folder.
 * @param avrcp_browsing_cid
 * @param scope    0-player list, 1-virtual file system, 2-search, 3-now playing  
 * @param start_item
 * @param end_item
 * @param attribute_count
 * @param attribute_list
 **/
uint8_t avrcp_browsing_controller_get_folder_items(uint16_t avrcp_browsing_cid, uint8_t scope, uint32_t start_item, uint32_t end_item, uint8_t attribute_count, uint8_t * attribute_list);

/**
 * @brief Retrieve a player list.
 * @param avrcp_browsing_cid
 **/
uint8_t avrcp_browsing_controller_get_player_list(uint16_t avrcp_browsing_cid);

/* API_END */

#if defined __cplusplus
}
#endif

#endif // __AVRCP_BROWSING_CONTROLLER_H