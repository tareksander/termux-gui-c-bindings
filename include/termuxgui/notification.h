#pragma once

/**
 * @file
 * @brief This file contains all functions related to notifications.
 * 
 * 
 */

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif



/**
 * @brief Creates a notification channel.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param id The channel id.
 * @param name The name displayed to the user.
 * @param imp The importance of the channel.
 * @return The error code. 
 */
tgui_err tgui_notification_create_channel(tgui_connection c, const char* id, const char* name, tgui_importance imp);


/**
 * @brief Contains information needed to create a notification.
 * 
 */
typedef struct {
    /**
     * @brief The id of the channel the notification should be posted in.
     * 
     */
    const char* channel;
    
    /**
     * @brief When a notification is ongoing, it cannot be dismissed by the user.
     * 
     */
    bool ongoing;
    
    /**
     * @brief The notification timestamp in milliseconds since the Unix epoch. Leave 0 to use the current time.
     * 
     */
    uint64_t timestamp;
    
    /**
     * @brief Whether to show the timestamp in the notification or not.
     * 
     */
    bool show_timestamp;
    
    /**
     * @brief If set, alerts the user only once when the notification is created instead also on updates.
     * 
     */
    bool alert_once;
    
    /**
     * @brief Can contain a notification id. When used, updates the specified notification instead of creating a new one.
     * 
     */
    const tgui_notification* update;
    
    /**
     * @brief An icon for the notification. Set to NULL for the standard app icon.
     * 
     */
    const void* icon;
    
    /**
     * @brief The length of the icon data.
     * 
     */
    const size_t icon_length;
    
    /**
     * @brief The importance. Newer Android versions use the channel importance instead, which can be changed by the user.
     * 
     */
    tgui_importance importance;
    
    /**
     * @brief An optional array of string labels for actions the user can click in the notification.
     * 
     */
    const char** actions;
} tgui_notification_create_info;


/**
 * @brief Creates a normal notification.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param[out] n Will contain the notification id if successful.
 * @param[in] info General information for constructing a notification.
 * @param title The notification title.
 * @param content The notification content.
 * @return The error code. 
 */
tgui_err tgui_notification_create_normal(tgui_connection c, tgui_notification* n, const tgui_notification_create_info* info, const char* title, const char* content);


/**
 * @brief Creates a notification with a larger content field that can be opened up.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param[out] n Will contain the notification id if successful.
 * @param[in] info General information for constructing a notification.
 * @param title The notification title.
 * @param content The notification content.
 * @return The error code. 
 */
tgui_err tgui_notification_create_big_text(tgui_connection c, tgui_notification* n, const tgui_notification_create_info* info, const char* title, const char* content);


/**
 * @brief Creates a notification with a big image.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param[out] n Will contain the notification id if successful.
 * @param[in] info General information for constructing a notification.
 * @param title The notification title.
 * @param content The notification content.
 * @param[in] img The image data.
 * @param img_length The length of the image data.
 * @return The error code. 
 */
tgui_err tgui_notification_big_image(tgui_connection c, tgui_notification* n, const tgui_notification_create_info* info, const char* title, const char* content, const void* img, size_t img_length);


/**
 * @brief Creates a notification with a remote layout.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param[out] n Will contain the notification id if successful.
 * @param[in] info General information for constructing a notification.
 * @param normal The layout for the standard notification.
 * @param[in] expanded The layout for the expanded notification. Optional.
 * @param[in] hud The layout for the HUD notification. Optional.
 * @return The error code. 
 */
tgui_err tgui_notification_create_custom(tgui_connection c, tgui_notification* n, const tgui_notification_create_info* info, tgui_remote_layout normal, tgui_remote_layout* expanded, tgui_remote_layout* hud);



/**
 * @brief Dismisses a notification.
 * 
 * @details
 * ### Errors
 *  - TGUI_ERR_MESSAGE: Protobuf I/O error.
 *  - TGUI_ERR_NOMEM: Not enough memory.
 *  - TGUI_ERR_EXCEPTION: Generic exception triggered.
 * 
 * @param c The connection to use.
 * @param n The notification to dismiss.
 * @return The error code. 
 */
tgui_err tgui_notification_dismiss(tgui_connection c, tgui_notification n);




#ifdef __cplusplus
}
#endif
